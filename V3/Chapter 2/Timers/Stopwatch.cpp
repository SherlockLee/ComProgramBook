// Stopwatch.cpp: implementation of the CStopwatch class.
//
//////////////////////////////////////////////////////////////////////

#include "Stopwatch.h"
#include <mmsystem.h>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStopwatch::CStopwatch()
{
	m_nStartTime.QuadPart = 0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&m_nFrequency);
}

CStopwatch::~CStopwatch()
{

}

unsigned long __stdcall CStopwatch::Release()
{
	delete this;
	return 0;
}

HRESULT __stdcall CStopwatch::Start()
{
	if (QueryPerformanceCounter((LARGE_INTEGER *)&m_nStartTime))
	{
		return S_OK;
	} 
	else
	{
		return E_FAIL;
	}
}

HRESULT __stdcall CStopwatch::ElapsedTime(float *Time)
{
	HRESULT hr;
	LARGE_INTEGER nStopTime;

	if (!QueryPerformanceCounter((LARGE_INTEGER *)&nStopTime) || (m_nStartTime.QuadPart == 0))
	{
		hr = E_FAIL;
	} 
	else
	{
		*Time = (float)(nStopTime.QuadPart - m_nStartTime.QuadPart);
		*Time = (*Time/m_nFrequency.QuadPart);
		hr = S_OK;
	}
	return hr;
}