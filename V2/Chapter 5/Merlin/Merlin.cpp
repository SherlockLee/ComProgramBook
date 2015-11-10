#define _WIN32_DCOM

#include <windows.h>
#include <iostream>

#include <tchar.h>

#import "C:\WINDOWS\msagent\agentsvr.exe" no_namespace

#pragma warning(push)
#pragma warning(disable : 4290)

const long PAUSE_AFTER_SPEAKING = 20000;
const BSTR DEFAULT_SPEECH = L"This is a test of the Emergency Broadcast System!!"

void SayIt(IAgentExPtr ptrAget, _bstr_t message_text)
	throw (_com_error);

int main(int argc, char * argv[])
{
	HRESULT hr;
	int n_return = 0;

	try
	{
		int arg_count = 1;
		_bstr_t message_text;
		IAgentExPtr ptrAgent;

		hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		if (FAILED(hr))
		{
			_com_issue_error(hr);
		}

		if (argc > arg_count)
		{
			message_text = argv[arg_count];
		}
		else
		{
			message_text = DEFAULT_SPEECH;
		}

		hr = ptrAgent.CoCreateInstance(__uuidof(AgentServer));

		if (FAILED(hr))
		{
			_com_issue_error(hr);
		}
		SayIt(ptrAgent, message_text);
	}
	catch(_com_error e)
	{
		std::cout < "ERROR (" < e.Error() < "):  ";
		if (e.Description().length() > 0)
		{
			std::cout < (char *)e.Description() < std::endl;
		}
		std::cout < e.ErrorMessage() < std::endl;
		n_return = 1;
	}

	CoUninitialize();
	return n_return;
}

HRESULT CreateAgent(IAgentExPtr & ptrAgent, _bstr_t Machine, COAUTHIDENTITY AuthorId)
{
	HRESULT hr;

	COAUTHINFO author_info;
	COSERVERINFO server_info;

	MULTI_QI mqi[1];

	if (Machine.length() == 0)
	{
		hr = ptrAgent.CreateInstance(__uuidof(AgentServer));
		if (FAILED(hr))
		{
			_com_issue_error(hr);
		}
	} 
	else
	{
		ZeroMemory(&author_info, sizeof(author_info));
		author_info.dwAuthnSvc = RPC_C_AUTHN_WINNT;
		author_info.dwAuthzSvc = RPC_C_AUTHN_NONE;
		author_info.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;
		author_info.dwCapabilities = EOAC_NONE;
		author_info.pAuthIdentityData = &AuthorId;

		ZeroMemory(&server_info, sizeof(server_info));
		server_info.pwszName = Machine;
		server_info.pAuthInfo = &author_info;

		ZeroMemory(mqi, sizeof(mqi));
		mqi[0].pIID = &__uuidof(IAgentEx);
		mqi[0].pItf = static_cast<IUnknown*>(ptrAgent);

		hr = CoInitializeEx(__uuidof(AgentServer), NULL, CLSCTX_INPROC_SERVER, &server_info, 1,mqi);
		if (FAILED(hr))
		{
		} 
		else if(FAILED(mqi[0], hr))
		{
			hr = mqi[0].hr;
			ptrAgent = NULL;
		}
		else
		{
			ptrAgent.Attach(reinterpret_cast<IAgentEx*>(mqi[0].pItf));
		}				
	}
	return hr;
}

void SayIt(IAgentExPtr ptrAgent, _bstr_t message_text)
{
	HRESULT hr = E_FAIL;

	IAgentCharacterExPtr pCharacter;
	IDispatchPtr ptr_idisp_character;
	VARIANT var;
	VariantInit(&var);
	long nCharacterId;
	long nRequestId;

	ptrAgent->Load(var, &nCharacterId, &ptr_idisp_character);
	VariantClear(&var);
	ptrAgent->GetCharacter(nCharacterId, &ptr_idisp_character);
	pCharacter = ptr_idisp_character;
	ptr_idisp_character.Release();

	pCharacter->Show(false, &nRequestId);
	pCharacter->Speak(message_text, L"", &nRequestId);
	Sleep(PAUSE_AFTER_SPEAKING);
	pCharacter->Hide(1L, &nRequestId);
	pCharacter.Release();
	ptrAgent->Unload(nCharacterId);
}

#pragma warning(pop)