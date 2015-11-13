// StopwatchClassFactory.cpp: implementation of the CStopwatchClassFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "StopwatchClassFactory.h"
#include "Stopwatch.h"

extern long g_nServerLockCount;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStopwatchClassFactory::CStopwatchClassFactory()
{
	m_nReferenceCount = 0;
}

CStopwatchClassFactory::~CStopwatchClassFactory()
{

}

HRESULT __stdcall CStopwatchClassFactory::QueryInterface(REFIID riid, void** ppvObject)
{
	HRESULT hr = S_OK;

	if (riid == IID_IUnknown)
	{
		*ppvObject = static_cast<IUnknown*>(
			static_cast<IClassFactory*>(this));
	} 
	else if (riid == IID_IClassFactory)
	{
		*ppvObject = static_cast<IClassFactory*>(this);
	}
	else
	{
		ppvObject = NULL;
		hr = E_NOINTERFACE;
	}

	if (SUCCEEDED(hr))
	{
		(static_cast<IUnknown*>(*ppvObject))->AddRef();
	}

	return hr;
}

unsigned long __stdcall CStopwatchClassFactory::AddRef()
{
	if (InterlockedIncrement(&m_nReferenceCount) == 1)
	{
		InterlockedIncrement(&g_nServerLockCount);
	}

	return m_nReferenceCount;
}

unsigned long __stdcall CStopwatchClassFactory::Release()
{
	if(InterlockedDecrement(&m_nReferenceCount) == 0)
	{
		delete this;
		InterlockedDecrement(&g_nServerLockCount);
		return 0;
	}
	return m_nReferenceCount;
}

HRESULT __stdcall CStopwatchClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject)
{
	HRESULT hr;
	CStopwatch* pStopwatch = new CStopwatch;

	hr = pStopwatch->QueryInterface(riid, ppvObject);
	if (FAILED(hr))
	{
		delete pStopwatch;
	}

	return hr;
}

HRESULT __stdcall CStopwatchClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
	{
		InterlockedIncrement(&g_nServerLockCount);
	}
	else
	{
		InterlockedDecrement(&g_nServerLockCount);
	}
	return S_OK;
}
