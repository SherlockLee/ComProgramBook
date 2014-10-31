// Stopwatch.h: interface for the CStopwatch class.

//////////////////////////////////////////////////////////////////////////

#if !defined(STOPWATCH_H)
#define STOPWATCH_H

#if _MSC_VER > 1000
#pragma once
#endif

#include <windows.h>
#include "Timers_i.c"

class IStopwatch : public IUnknown
{
public:
	// IStopwatch specific functions
	virtual HRESULT __stdcall Start() = 0;
	virtual HRESULT __stdcall ElapsedTime(float *Time) = 0;
};


#endif
// Stopwatch.h: interface for the CStopwatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__61884278_FA8F_4BF7_BB99_534848A8921B__INCLUDED_)
#define AFX_STOPWATCH_H__61884278_FA8F_4BF7_BB99_534848A8921B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStopwatch  : public IStopwatch
{
public:
	CStopwatch();
	virtual ~CStopwatch();

private:
	// The frequency of the counter
	// returned by QueryPerformanceCounter()
	LARGE_INTEGER m_nFrequency;

	// The counter value when the start method was last called
	LARGE_INTEGER m_nSartTime;

	long m_nReferenceCount;

public:
	// IStopwatch specific functions
	HRESULT __stdcall Start();
	HRESULT	__stdcall ElapsedTime(float *Time);

	// Utility functions
	HRESULT __stdcall QueryInterface(REFIID riid, void **ppvObject);
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

#endif // !defined(AFX_STOPWATCH_H__61884278_FA8F_4BF7_BB99_534848A8921B__INCLUDED_)

