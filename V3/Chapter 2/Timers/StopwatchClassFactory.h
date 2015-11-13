// StopwatchClassFactory.h: interface for the CStopwatchClassFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCHCLASSFACTORY_H__45D2BE0F_A7E0_40DB_9385_10B4AFE10474__INCLUDED_)
#define AFX_STOPWATCHCLASSFACTORY_H__45D2BE0F_A7E0_40DB_9385_10B4AFE10474__INCLUDED_

#include <windows.h>
#include "timers_i.c"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStopwatchClassFactory : public IClassFactory  
{
public:
	CStopwatchClassFactory();
	virtual ~CStopwatchClassFactory();

private:
	long m_nReferenceCount;

public:
	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();

	HRESULT __stdcall CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject);
	HRESULT __stdcall LockServer(BOOL fLock);
};

#endif // !defined(AFX_STOPWATCHCLASSFACTORY_H__45D2BE0F_A7E0_40DB_9385_10B4AFE10474__INCLUDED_)
