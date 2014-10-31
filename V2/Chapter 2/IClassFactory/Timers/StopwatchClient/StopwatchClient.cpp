#include <iostream>

#include "..\\Stopwatch.h"
#include "..\\Timers_i.c"
#include "..\\StopwatchClassFactory.h"

#define TIMERSDLL		"..\\Timers.dll"

typedef HRESULT (__stdcall *DLLGETCLASSOBJECT)(REFCLSID rc_sid,
											   REFIID riid, LPVOID *ppv);

typedef HRESULT (__stdcall *DLLCANUNLOADNOW)(void);
HINSTANCE hinstDll;

HRESULT CreateInstance(REFCLSID rclsid, REFIID riid, void** ppv)
{
	HRESULT hr = E_FAIL;
	DLLGETCLASSOBJECT	DllGetClassObject;
	IClassFactory* pClassFactory;

	hinstDll = LoadLibrary(TIMERSDLL);
	if(hinstDll == NULL)
	{
		std::cout << "Unable to load \"" TIMERSDLL "\"" << std::endl;
	}
	else
	{
		DllGetClassObject = 
			(DLLGETCLASSOBJECT)GetProcAddress(hinstDll,
			"DllGetClassObject");
		if (DllGetClassObject != NULL)
		{
			hr = DllGetClassObject(rclsid, IID_IClassFactory, (void**)&pClassFactory);
		}
		if (SUCCEEDED(hr))
		{
			hr = pClassFactory->CreateInstance(NULL, riid, ppv);
			pClassFactory->Release();
		}
	}
	return hr;
}

void UnloadDLL()
{
	DLLCANUNLOADNOW DllCanUnloadNow;
	DllCanUnloadNow = (DLLCANUNLOADNOW)GetProcAddress(hinstDll, "DllCanUnloadNow");
	if (DllCanUnloadNow != NULL)
	{
		if ((DllCanUnloadNow()) == S_OK)
		{
			FreeLibrary(hinstDll);
		}
	}
}

void UseStopwatch(IStopwatch* const pStopwatch)
{
	float nElapsedTime;
	pStopwatch->Start();
	pStopwatch->ElapsedTime(&nElapsedTime);
	std::cout << "The overhead time is "
		<< nElapsedTime << std::endl;
}

int main(int argc, char* argv[])
{
	HRESULT hr;
	IUnknown* pIUnknown = NULL;
	IUnknown* pIunknown2 = NULL;
	IStopwatch* pStopwatch = NULL;
	
	hr = CreateInstance(CLSID_Stopwatch, IID_IUnknown, (void**) &pIUnknown);
	
	if (!SUCCEEDED(hr))
	{
		std::cout << "ERROR: Unable to create Stopwatch!";
	} 
	else
	{
		pIunknown2 = pIUnknown;
		
		hr = pIunknown2->QueryInterface(IID_IStopwatch, (void **)&pStopwatch);
		if (!SUCCEEDED(hr))
		{
			std::cout << "ERROR: Unable to retrieve Stopwatch interface!!";
		} 
		else
		{
			UseStopwatch(pStopwatch);
			pStopwatch->Release();
			pStopwatch = NULL;
		}
		pIUnknown->Release();
	
	}

	UnloadDLL();
	return 0;
}