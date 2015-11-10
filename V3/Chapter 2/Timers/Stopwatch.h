// Stopwatch.h: interface for the CStopwatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_)
#define AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

class IStopwatch
{
public:
	// Utility functions
	virtual unsigned long __stdcall Release() = 0;

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

public:
	unsigned long __stdcall Release();
	HRESULT __stdcall Start();
	HRESULT __stdcall ElapsedTime(float *Time);
};

#endif // !defined(AFX_STOPWATCH_H__74D7AE7E_6ABB_4CD0_B2B9_C7D5369D9FB3__INCLUDED_)
