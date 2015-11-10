// Stopwatch.cpp : Implementation of CStopwatch
#include "stdafx.h"
#include "Timers.h"
#include "Stopwatch.h"

#include <mmsystem.h>

/////////////////////////////////////////////////////////////////////////////
// CStopwatch

HRESULT CStopwatch::FinalConstruct()
{
	m_nStartTime.QuadPart = 0;

	QueryPerformanceFrequency((LARGE_INTEGER *)&m_nFrenquency);

	Start();
	ElapsedTime(&m_nOverhead);

	return S_OK;
}

STDMETHODIMP CStopwatch::Start()
{
	// TODO: Add your implementation code here
	if (QueryPerformanceCounter((LARGE_INTEGER*)&m_nStartTime))
	{
		return S_OK;
	}
	else
	{
		return E_FAIL;
	}	
}

STDMETHODIMP CStopwatch::ElapsedTime(float *Time)
{
	// TODO: Add your implementation code here
	HRESULT hr;
	LARGE_INTEGER nStopTime;
	if (!QueryPerformanceCounter((LARGE_INTEGER*)&nStopTime) ||
		(m_nStartTime.QuadPart == 0))
	{
		hr = E_FAIL;
	}
	else
	{
		*Time = (float)(nStopTime.QuadPart - m_nStartTime.QuadPart);
		*Time = (*Time / m_nFrenquency.QuadPart);
		hr = S_OK;
	}
	return hr;
}

STDMETHODIMP CStopwatch::get_Overhead(float *pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_nOverhead;
	return S_OK;
}

STDMETHODIMP CStopwatch::put_Overhead(float newVal)
{
	// TODO: Add your implementation code here
	m_nOverhead = newVal;
	return S_OK;
}
