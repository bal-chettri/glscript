

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Aug 15 16:14:41 2017
 */
/* Compiler settings for ..\..\include\glscript\activescript\gls_core.idl:
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

#ifndef __gls_core_h__
#define __gls_core_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___GLScript_Array_FWD_DEFINED__
#define ___GLScript_Array_FWD_DEFINED__
typedef interface _GLScript_Array _GLScript_Array;
#endif 	/* ___GLScript_Array_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef ___GLScript_Array_INTERFACE_DEFINED__
#define ___GLScript_Array_INTERFACE_DEFINED__

/* interface _GLScript_Array */
/* [nonextensible][hidden][oleautomation][dual][uuid][object] */ 


EXTERN_C const IID IID__GLScript_Array;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("99CD2524-E3A2-4fbc-993B-B7CD2F7F8CB7")
    _GLScript_Array : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_type( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_length( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get( 
            /* [in] */ int index,
            /* [retval][out] */ VARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put( 
            /* [in] */ int index,
            /* [in] */ VARIANT value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _GLScript_ArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _GLScript_Array * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _GLScript_Array * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _GLScript_Array * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _GLScript_Array * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _GLScript_Array * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _GLScript_Array * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _GLScript_Array * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_type )( 
            _GLScript_Array * This,
            /* [retval][out] */ int *pValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_length )( 
            _GLScript_Array * This,
            /* [retval][out] */ int *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *get )( 
            _GLScript_Array * This,
            /* [in] */ int index,
            /* [retval][out] */ VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *put )( 
            _GLScript_Array * This,
            /* [in] */ int index,
            /* [in] */ VARIANT value);
        
        END_INTERFACE
    } _GLScript_ArrayVtbl;

    interface _GLScript_Array
    {
        CONST_VTBL struct _GLScript_ArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _GLScript_Array_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _GLScript_Array_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _GLScript_Array_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _GLScript_Array_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _GLScript_Array_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _GLScript_Array_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _GLScript_Array_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _GLScript_Array_get_type(This,pValue)	\
    ( (This)->lpVtbl -> get_type(This,pValue) ) 

#define _GLScript_Array_get_length(This,pValue)	\
    ( (This)->lpVtbl -> get_length(This,pValue) ) 

#define _GLScript_Array_get(This,index,pValue)	\
    ( (This)->lpVtbl -> get(This,index,pValue) ) 

#define _GLScript_Array_put(This,index,value)	\
    ( (This)->lpVtbl -> put(This,index,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___GLScript_Array_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


