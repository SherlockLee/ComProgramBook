// StopwatchClassFactory.h: interface for the CStopwatchClassFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCHCLASSFACTORY_H__D6D165F6_2448_4330_93E4_FC3C1EF177D4__INCLUDED_)
#define AFX_STOPWATCHCLASSFACTORY_H__D6D165F6_2448_4330_93E4_FC3C1EF177D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "Timers_i.c"

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

	HRESULT	__stdcall CreateInstance(IUnknown *pUnkOuter, REFIID riid, void** ppvObject);
	HRESULT __stdcall LockServer(BOOL fLock);


};

#endif // !defined(AFX_STOPWATCHCLASSFACTORY_H__D6D165F6_2448_4330_93E4_FC3C1EF177D4__INCLUDED_)
