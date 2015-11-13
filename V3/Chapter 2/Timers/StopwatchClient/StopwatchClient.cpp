#include <iostream>
#include <windows.h>

#include "..\timers_i.c"
#include "..\Stopwatch.h"

void UseStopwatch(IStopwatch* const pStopwatch)
{
	float nElapsedTime;
	pStopwatch->Start();
	pStopwatch->ElapsedTime(&nElapsedTime);

	std::cout << "The overhead time is "
			<< nElapsedTime << std::endl;
}

int main(int argc, char *argv[])
{
	HRESULT hr;
	IStopwatch* pStopwatch = NULL;

	CoInitialize(NULL);

	hr = CoCreateInstance(CLSID_Stopwatch, NULL, CLSCTX_INPROC_SERVER, IID_IStopwatch, (void**)&pStopwatch);

	if (!SUCCEEDED(hr))
	{
		std::cout << "ERROR: Unable to create Stopwatch!!";
		switch(hr)
		{
		case REGDB_E_CLASSNOTREG:
			std::cout<<"	Class not registered.\n";
			break;
		case E_NOINTERFACE:
			std::cout<<"	No such interface implemented.\n";
			break;
		case CLASS_E_NOAGGREGATION:
			std::cout<<"	No aggregation.\n";
			break;
		default:
			std::cout<<"	Unexpected error.\n";
			break;
		}
	} 
	else
	{
		UseStopwatch(pStopwatch);
		pStopwatch->Release();
		pStopwatch = NULL;
	}

	CoUninitialize();
	return 0;
}
