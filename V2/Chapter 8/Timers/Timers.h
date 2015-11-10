/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Nov 05 11:20:33 2014
 */
/* Compiler settings for C:\Documents and Settings\Administrator\×ÀÃæ\ComProgramBook\V2\Chapter 8\Timers\Timers.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Timers_h__
#define __Timers_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IStopwatch_FWD_DEFINED__
#define __IStopwatch_FWD_DEFINED__
typedef interface IStopwatch IStopwatch;
#endif 	/* __IStopwatch_FWD_DEFINED__ */


#ifndef __IStopwatch2_FWD_DEFINED__
#define __IStopwatch2_FWD_DEFINED__
typedef interface IStopwatch2 IStopwatch2;
#endif 	/* __IStopwatch2_FWD_DEFINED__ */


#ifndef __Stopwatch_FWD_DEFINED__
#define __Stopwatch_FWD_DEFINED__

#ifdef __cplusplus
typedef class Stopwatch Stopwatch;
#else
typedef struct Stopwatch Stopwatch;
#endif /* __cplusplus */

#endif 	/* __Stopwatch_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IStopwatch_INTERFACE_DEFINED__
#define __IStopwatch_INTERFACE_DEFINED__

/* interface IStopwatch */
/* [unique][helpstring][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IStopwatch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8DC0EEEC-FA21-4044-A142-6F83BC55F24A")
    IStopwatch : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ElapsedTime( 
            /* [retval][out] */ float __RPC_FAR *Time) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Overhead( 
            /* [retval][out] */ float __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Overhead( 
            /* [in] */ float newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStopwatchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStopwatch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStopwatch __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStopwatch __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Start )( 
            IStopwatch __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ElapsedTime )( 
            IStopwatch __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *Time);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Overhead )( 
            IStopwatch __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Overhead )( 
            IStopwatch __RPC_FAR * This,
            /* [in] */ float newVal);
        
        END_INTERFACE
    } IStopwatchVtbl;

    interface IStopwatch
    {
        CONST_VTBL struct IStopwatchVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStopwatch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStopwatch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStopwatch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStopwatch_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IStopwatch_ElapsedTime(This,Time)	\
    (This)->lpVtbl -> ElapsedTime(This,Time)

#define IStopwatch_get_Overhead(This,pVal)	\
    (This)->lpVtbl -> get_Overhead(This,pVal)

#define IStopwatch_put_Overhead(This,newVal)	\
    (This)->lpVtbl -> put_Overhead(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IStopwatch_Start_Proxy( 
    IStopwatch __RPC_FAR * This);


void __RPC_STUB IStopwatch_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IStopwatch_ElapsedTime_Proxy( 
    IStopwatch __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *Time);


void __RPC_STUB IStopwatch_ElapsedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStopwatch_get_Overhead_Proxy( 
    IStopwatch __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pVal);


void __RPC_STUB IStopwatch_get_Overhead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IStopwatch_put_Overhead_Proxy( 
    IStopwatch __RPC_FAR * This,
    /* [in] */ float newVal);


void __RPC_STUB IStopwatch_put_Overhead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStopwatch_INTERFACE_DEFINED__ */


#ifndef __IStopwatch2_INTERFACE_DEFINED__
#define __IStopwatch2_INTERFACE_DEFINED__

/* interface IStopwatch2 */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IStopwatch2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8ECA2E64-E725-4C95-A345-AED8CB7BAFD4")
    IStopwatch2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ElapsedTime( 
            /* [retval][out] */ float __RPC_FAR *Time) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Overhead( 
            /* [retval][out] */ float __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Overhead( 
            /* [in] */ float newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStopwatch2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStopwatch2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStopwatch2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStopwatch2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStopwatch2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStopwatch2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStopwatch2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStopwatch2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Start )( 
            IStopwatch2 __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ElapsedTime )( 
            IStopwatch2 __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *Time);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Overhead )( 
            IStopwatch2 __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Overhead )( 
            IStopwatch2 __RPC_FAR * This,
            /* [in] */ float newVal);
        
        END_INTERFACE
    } IStopwatch2Vtbl;

    interface IStopwatch2
    {
        CONST_VTBL struct IStopwatch2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStopwatch2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStopwatch2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStopwatch2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStopwatch2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStopwatch2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStopwatch2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStopwatch2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStopwatch2_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IStopwatch2_ElapsedTime(This,Time)	\
    (This)->lpVtbl -> ElapsedTime(This,Time)

#define IStopwatch2_get_Overhead(This,pVal)	\
    (This)->lpVtbl -> get_Overhead(This,pVal)

#define IStopwatch2_put_Overhead(This,newVal)	\
    (This)->lpVtbl -> put_Overhead(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStopwatch2_Start_Proxy( 
    IStopwatch2 __RPC_FAR * This);


void __RPC_STUB IStopwatch2_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IStopwatch2_ElapsedTime_Proxy( 
    IStopwatch2 __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *Time);


void __RPC_STUB IStopwatch2_ElapsedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IStopwatch2_get_Overhead_Proxy( 
    IStopwatch2 __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pVal);


void __RPC_STUB IStopwatch2_get_Overhead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IStopwatch2_put_Overhead_Proxy( 
    IStopwatch2 __RPC_FAR * This,
    /* [in] */ float newVal);


void __RPC_STUB IStopwatch2_put_Overhead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStopwatch2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_Timers_0210 */
/* [local] */ 


enum TmLibraryVersion
    {	tmLibraryVersionMajor	= 2,
	tmLibraryVersionMinor	= 2
    };


extern RPC_IF_HANDLE __MIDL_itf_Timers_0210_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Timers_0210_v0_0_s_ifspec;


#ifndef __TIMERSLib_LIBRARY_DEFINED__
#define __TIMERSLib_LIBRARY_DEFINED__

/* library TIMERSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TIMERSLib;

EXTERN_C const CLSID CLSID_Stopwatch;

#ifdef __cplusplus

class DECLSPEC_UUID("90236F32-CB2C-40F2-9D8F-FC643DB636A2")
Stopwatch;
#endif
#endif /* __TIMERSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
