#include <iostream>

#import "..\\Timers.dll" no_namespace

#include <winerror.h>

void UseStopwatch(IStopwatchPtr pStopwatch)
{
	float nElapsedTimeLateBound;
	float nElapsedTimeEarlyBound;
	float nDummy;

	enum StopwatchMethods
	{
		StopwatchMethodsStart,
		StopwatchMethodsElapsedTime,
		StopwatchMethodsOverhead,
		StopwatchMethodsTotal
	};

	OLECHAR FAR* FunctionNames[StopwatchMethodsTotal] = {L"Start", L"ElapsedTime", L"Overhead"};
	DISPID DispIds[StopwatchMethodsTotal];
	_variant_t varElapsedTime;
	_variant_t varOverhead;
	_variant_t varParms[1];

	DISPPARAMS dpParms = {NULL, NULL, 0, 0};
	HRESULT hr;

	IStopwatch2Ptr pStopwatch2(__uuidof(Stopwatch));
	IDispatchPtr pDispStopwatch;
	pStopwatch.QueryInterface(__uuidof(IDispatch), &pDispStopwatch);

	pStopwatch->Start();

	{
		pStopwatch2->Start();
		nDummy = pStopwatch2->ElapsedTime();
	}
	
	nElapsedTimeEarlyBound = pStopwatch->ElapsedTime();

	std::cout << "The early bound elapsed time is "
		<< nElapsedTimeEarlyBound << std::endl;

	
	//////////////////////////////////////////////////////////////////////////
	pStopwatch->Start();
	{
		if (FAILED(hr = pDispStopwatch->GetIDsOfNames(IID_NULL, &FunctionNames[StopwatchMethodsStart], 1, LOCALE_SYSTEM_DEFAULT, &DispIds[StopwatchMethodsStart])))
		{
			_com_raise_error(hr);
		}

		if (FAILED(hr = pDispStopwatch->Invoke(DispIds[StopwatchMethodsStart], IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dpParms, &varElapsedTime, NULL, NULL)))
		{
			_com_raise_error(hr);
		}

		if (FAILED(hr = pDispStopwatch->GetIDsOfNames(IID_NULL, &FunctionNames[StopwatchMethodsElapsedTime], 1, LOCALE_SYSTEM_DEFAULT, &DispIds[StopwatchMethodsElapsedTime])))
		{
			_com_raise_error(hr);
		}
		
		if (FAILED(hr = pDispStopwatch->Invoke(DispIds[StopwatchMethodsElapsedTime], IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dpParms, &varElapsedTime, NULL, NULL)))
		{
			_com_raise_error(hr);
		}
		
		nDummy = varElapsedTime;
	}

	nElapsedTimeLateBound = pStopwatch->ElapsedTime();

	std::cout << "The late bound elapsed time including a query for disp ids is "
		<< nElapsedTimeLateBound << std::endl;

	std::cout << "The expense of using the IDispatch without dispid is "
		<< (nElapsedTimeLateBound - nElapsedTimeEarlyBound)<< std::endl;
	

	//////////////////////////////////////////////////////////////////////////
	pStopwatch->Start();
	{

	}
}

int main(int argc, char* argv[])
{
	IStopwatch* pStopwatch = NULL;
	
	CoInitialize(NULL);

	try
	{
		IStopwatchPtr pStopwatch(__uuidof(Stopwatch));
		UseStopwatch(pStopwatch);
	}
	catch (_com_error e)
	{
		std::cout << "ERROR: " << e.ErrorMessage() << std::endl;
	}
	CoUninitialize();

	return 0;
}