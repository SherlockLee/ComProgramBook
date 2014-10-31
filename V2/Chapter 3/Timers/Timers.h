/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 31 16:48:29 2014
 */
/* Compiler settings for D:\COM Program\V2\Chapter 3\Timers\Timers.idl:
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
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IStopwatch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8DC0EEEC-FA21-4044-A142-6F83BC55F24A")
    IStopwatch : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ElapsedTime( 
            /* [retval][out] */ float __RPC_FAR *Time) = 0;
        
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



#endif 	/* __IStopwatch_INTERFACE_DEFINED__ */



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
