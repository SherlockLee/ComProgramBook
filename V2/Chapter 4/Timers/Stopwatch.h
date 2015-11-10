// Stopwatch.h : Declaration of the CStopwatch

#ifndef __STOPWATCH_H_
#define __STOPWATCH_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStopwatch
class ATL_NO_VTABLE CStopwatch : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStopwatch, &CLSID_Stopwatch>,
	public IStopwatch
{
public:
	CStopwatch()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STOPWATCH)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStopwatch)
	COM_INTERFACE_ENTRY(IStopwatch)
END_COM_MAP()

// IStopwatch
public:
	STDMETHOD(get_Overhead)(/*[out, retval]*/ float *pVal);
	STDMETHOD(put_Overhead)(/*[in]*/ float newVal);
	STDMETHOD(ElapsedTime)(/*[out, retval]*/ float* Time);
	STDMETHOD(Start)();
	
	HRESULT FinalConstruct();

private:
	LARGE_INTEGER m_nFrenquency;
	LARGE_INTEGER m_nStartTime;
	float m_nOverhead;
};

#endif //__STOPWATCH_H_
