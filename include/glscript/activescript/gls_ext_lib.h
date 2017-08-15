

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Aug 15 16:14:43 2017
 */
/* Compiler settings for ..\..\include\glscript\activescript\gls_ext_lib.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __gls_ext_lib_h__
#define __gls_ext_lib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___GLScriptExtLib_FWD_DEFINED__
#define ___GLScriptExtLib_FWD_DEFINED__
typedef interface _GLScriptExtLib _GLScriptExtLib;
#endif 	/* ___GLScriptExtLib_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef ___GLScriptExtLib_INTERFACE_DEFINED__
#define ___GLScriptExtLib_INTERFACE_DEFINED__

/* interface _GLScriptExtLib */
/* [oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID__GLScriptExtLib;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9D67C09A-FFF4-47ee-B1B8-D00C372489EA")
    _GLScriptExtLib : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_name( 
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ short *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _GLScriptExtLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _GLScriptExtLib * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _GLScriptExtLib * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _GLScriptExtLib * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _GLScriptExtLib * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _GLScriptExtLib * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _GLScriptExtLib * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _GLScriptExtLib * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_name )( 
            _GLScriptExtLib * This,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            _GLScriptExtLib * This,
            /* [retval][out] */ short *pValue);
        
        END_INTERFACE
    } _GLScriptExtLibVtbl;

    interface _GLScriptExtLib
    {
        CONST_VTBL struct _GLScriptExtLibVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _GLScriptExtLib_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _GLScriptExtLib_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _GLScriptExtLib_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _GLScriptExtLib_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _GLScriptExtLib_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _GLScriptExtLib_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _GLScriptExtLib_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _GLScriptExtLib_get_name(This,pValue)	\
    ( (This)->lpVtbl -> get_name(This,pValue) ) 

#define _GLScriptExtLib_get_version(This,pValue)	\
    ( (This)->lpVtbl -> get_version(This,pValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___GLScriptExtLib_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


