// Stopwatch.h: interface for the CStopwatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_)
#define AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include "Timers_i.c"

class IStopwatch :public IUnknown
{
public:
	// IStopwatch specific functions
	virtual HRESULT __stdcall Start() = 0;
	virtual HRESULT __stdcall ElapsedTime(float *Time) = 0;

};

class CStopwatch  : public IStopwatch
{
public:
	CStopwatch();
	virtual ~CStopwatch();

private:
	LARGE_INTEGER m_nFrequency;

	LARGE_INTEGER m_nStartTime;

	long m_nReferenceCount;

public:	
	HRESULT __stdcall Start();
	HRESULT __stdcall ElapsedTime(float *Time);
	HRESULT __stdcall QueryInterface(REFIID riid, void ** ppvObject);
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();

};

#endif // !defined(AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_)
