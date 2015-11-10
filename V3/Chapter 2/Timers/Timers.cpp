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
	*ppv = static_cast<IStopwatch*>(new CStopwatch);
	return S_OK;
}