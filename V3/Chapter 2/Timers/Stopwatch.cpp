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
	m_nReferenceCount = 0;
	QueryPerformanceFrequency((LARGE_INTEGER *)&m_nFrequency);
}

CStopwatch::~CStopwatch()
{

}

unsigned long __stdcall CStopwatch::Release()
{
	if (InterlockedDecrement(&m_nReferenceCount) == 0)
	{
		delete this;
		return 0;
	}
	return m_nReferenceCount;
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

HRESULT __stdcall CStopwatch::QueryInterface(REFIID riid, void ** ppvObject)
{
	HRESULT hr = S_OK;

	if (riid == IID_IUnknown)
	{
		*ppvObject = static_cast<IUnknown*>(static_cast<IStopwatch*>(this));
	}
	else if (riid == IID_IStopwatch)
	{
		*ppvObject = static_cast<IStopwatch*>(this);
	} 
	else
	{
		ppvObject = NULL;
		hr = E_NOINTERFACE;
	}

	if (SUCCEEDED(hr))
	{
		(static_cast<IUnknown*>(*ppvObject)->AddRef());
	}
	return hr;
}

unsigned long __stdcall CStopwatch::AddRef()
{
	return InterlockedIncrement(&m_nReferenceCount);
}

