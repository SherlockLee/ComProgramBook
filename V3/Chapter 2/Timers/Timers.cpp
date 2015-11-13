#include <windows.h>
#include "Stopwatch.h"

extern "C"
BOOL __stdcall DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
	return TRUE;
}

extern "C"
HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT hr;
	if (rclsid == CLSID_Stopwatch)
	{
		CStopwatch* stopwatch = new CStopwatch;
		hr = stopwatch->QueryInterface(riid, ppv);
	} 
	else
	{
		hr = CLASS_E_CLASSNOTAVAILABLE;
	}
	
	return S_OK;
}