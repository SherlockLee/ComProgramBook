#include <iostream>

#include "..\Stopwatch.h"
#define TIMERSDLL	"..\\Timers.dll"

typedef HRESULT(__stdcall *DLLGETCLASSOBJECT)(REFCLSID rc_sid, REFIID riid, LPVOID * ppv);

HRESULT CreateInstance(void ** ppv)
{
	HRESULT hr = E_FAIL;
	HINSTANCE hinstDll;
	DLLGETCLASSOBJECT DllGetClassObject;
	GUID guid;

	hinstDll = LoadLibrary(TIMERSDLL);
	if (hinstDll == NULL)
	{
		std::cout << "Unable to load\"" TIMERSDLL "\"" << std::endl;
	} 
	else
	{
		DllGetClassObject = ((DLLGETCLASSOBJECT)GetProcAddress(hinstDll, "DllGetClassObject"));
		if (DllGetClassObject != NULL)
		{
			hr = DllGetClassObject(guid, guid, ppv);
		}
	}

	return hr;
}

int main(int argc, char *argv[])
{
	float nElapsedTime;
	HRESULT hr;
	IStopwatch* pStopwatch = NULL;

	hr = CreateInstance((void **)&pStopwatch);
	if (!SUCCEEDED(hr))
	{
		std::cout << "ERROR: Unable to create Stopwatch!!";
	} 
	else
	{
		pStopwatch->Start();
		pStopwatch->ElapsedTime(&nElapsedTime);

		std::cout << "The overhead time is "
			<< nElapsedTime << std::endl;
		pStopwatch->Release();
		pStopwatch = NULL;
	}

	return 0;
}
