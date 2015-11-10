#include <iostream>

#import "..\\Timers.dll" no_namespace

void UseStopwatch(IStopwatchPtr pStopwatch)
{
	float nElapsedTime;
	float nOverhead;

	nOverhead = pStopwatch->Overhead;	
	std::cout << "The overhead time without going " "across the COM boundary is "
		<< nOverhead << std::endl;

	pStopwatch->Start();
	nElapsedTime = pStopwatch->ElapsedTime();
	std::cout << "The overhead time with the " "COM boundary is "
		<< nOverhead << std::endl;

	std::cout << "The expense of using the " "COM boundary is "
		<< (nElapsedTime - nOverhead) << std::endl;

	pStopwatch->Overhead = nElapsedTime;

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