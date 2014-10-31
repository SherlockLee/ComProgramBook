#include <windows.h>
#include "Stopwatch.h"
#include "StopwatchClassFactory.h"

long g_nServerLockCount = 0;

extern "C"
BOOL __stdcall DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	return TRUE;
}

extern "C"
HRESULT __stdcall DllCanUnloadNow(void)
{
	return (g_nServerLockCount == 0) ? S_OK : S_FALSE;
}

extern "C"
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT hr;
	if (rclsid == CLSID_Stopwatch)
	{
		CStopwatchClassFactory* pStopwatchClassFactory = new CStopwatchClassFactory;
		hr = pStopwatchClassFactory->QueryInterface(riid, ppv);
		if (FAILED(hr))
		{
			delete pStopwatchClassFactory;
		}
	} 
	else
	{
		hr = CLASS_E_CLASSNOTAVAILABLE;
	}

	return hr;
}