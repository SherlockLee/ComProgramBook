#include <iostream>

#include <windows.h>
#include "..\\Timers_i.c"
#include "..\\Timers.h"

void UseStopwatch(IStopwatch* const pStopwatch)
{
	float nElapsedTime;
	float nOverhead;

	pStopwatch->get_Overhead(&nOverhead);
	std::cout << "The overhead time without going " "across the COM boundary is "
		<< nOverhead << std::endl;

	pStopwatch->Start();
	pStopwatch->ElapsedTime(&nElapsedTime);
	std::cout << "The overhead time with the " "COM boundary is "
		<< nOverhead << std::endl;

	std::cout << "The expense of using the " "COM boundary is "
		<< (nElapsedTime - nOverhead) << std::endl;

	pStopwatch->put_Overhead(nElapsedTime);

}

int main(int argc, char* argv[])
{
	HRESULT hr;
	IStopwatch* pStopwatch = NULL;

	CoInitialize(NULL);

	hr = CoCreateInstance(CLSID_Stopwatch, NULL
		,CLSCTX_INPROC_SERVER, IID_IStopwatch, (void**) &pStopwatch);
	
	if (!SUCCEEDED(hr))
	{
		switch(hr)
		{
		case REGDB_E_CLASSNOTREG:
			std::cout << "		Class not registered.\n";
			break;
		case E_NOINTERFACE:
			std::cout << "		No such interface implemented.\n";
			break;
		case CLASS_E_NOAGGREGATION:
			std::cout << "		No aggregation.\n";
			break;
		default:
			std::cout << "		Unexpected error.\n";
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