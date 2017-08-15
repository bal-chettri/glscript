

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Aug 15 16:14:37 2017
 */
/* Compiler settings for ..\..\include\glscript\activescript\gls_activescript_interfaces.idl:
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


#ifndef __gls_activescript_interfaces_h__
#define __gls_activescript_interfaces_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___GLScript_Console_FWD_DEFINED__
#define ___GLScript_Console_FWD_DEFINED__
typedef interface _GLScript_Console _GLScript_Console;
#endif 	/* ___GLScript_Console_FWD_DEFINED__ */


#ifndef ___GLScript_Engine_FWD_DEFINED__
#define ___GLScript_Engine_FWD_DEFINED__
typedef interface _GLScript_Engine _GLScript_Engine;
#endif 	/* ___GLScript_Engine_FWD_DEFINED__ */


#ifndef ___GLScript_Context_FWD_DEFINED__
#define ___GLScript_Context_FWD_DEFINED__
typedef interface _GLScript_Context _GLScript_Context;
#endif 	/* ___GLScript_Context_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "gls_core.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __LIBGLScript_LIBRARY_DEFINED__
#define __LIBGLScript_LIBRARY_DEFINED__

/* library LIBGLScript */
/* [helpstring][version][uuid] */ 


DEFINE_GUID(LIBID_LIBGLScript,0x922C6F46,0xC588,0x47ea,0x99,0xC1,0x4D,0xDA,0xDA,0x27,0xFF,0x9F);

#ifndef ___GLScript_Console_INTERFACE_DEFINED__
#define ___GLScript_Console_INTERFACE_DEFINED__

/* interface _GLScript_Console */
/* [nonextensible][hidden][oleautomation][dual][uuid][object] */ 


DEFINE_GUID(IID__GLScript_Console,0xDE2FED75,0x70CD,0x440d,0x9F,0x20,0xAD,0xF8,0xAD,0x48,0xC5,0xF4);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE2FED75-70CD-440d-9F20-ADF8AD48C5F4")
    _GLScript_Console : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE log( 
            /* [in] */ VARIANT msg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE warn( 
            /* [in] */ VARIANT msg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE error( 
            /* [in] */ VARIANT msg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _GLScript_ConsoleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _GLScript_Console * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _GLScript_Console * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _GLScript_Console * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _GLScript_Console * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _GLScript_Console * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _GLScript_Console * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _GLScript_Console * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *log )( 
            _GLScript_Console * This,
            /* [in] */ VARIANT msg);
        
        HRESULT ( STDMETHODCALLTYPE *warn )( 
            _GLScript_Console * This,
            /* [in] */ VARIANT msg);
        
        HRESULT ( STDMETHODCALLTYPE *error )( 
            _GLScript_Console * This,
            /* [in] */ VARIANT msg);
        
        HRESULT ( STDMETHODCALLTYPE *clear )( 
            _GLScript_Console * This);
        
        END_INTERFACE
    } _GLScript_ConsoleVtbl;

    interface _GLScript_Console
    {
        CONST_VTBL struct _GLScript_ConsoleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _GLScript_Console_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _GLScript_Console_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _GLScript_Console_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _GLScript_Console_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _GLScript_Console_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _GLScript_Console_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _GLScript_Console_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _GLScript_Console_log(This,msg)	\
    ( (This)->lpVtbl -> log(This,msg) ) 

#define _GLScript_Console_warn(This,msg)	\
    ( (This)->lpVtbl -> warn(This,msg) ) 

#define _GLScript_Console_error(This,msg)	\
    ( (This)->lpVtbl -> error(This,msg) ) 

#define _GLScript_Console_clear(This)	\
    ( (This)->lpVtbl -> clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___GLScript_Console_INTERFACE_DEFINED__ */


#ifndef ___GLScript_Engine_INTERFACE_DEFINED__
#define ___GLScript_Engine_INTERFACE_DEFINED__

/* interface _GLScript_Engine */
/* [nonextensible][hidden][oleautomation][dual][uuid][object] */ 


DEFINE_GUID(IID__GLScript_Engine,0xFA6780B7,0x0734,0x4907,0xA0,0xAB,0xFF,0xB8,0x8C,0x3F,0xCC,0xA3);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA6780B7-0734-4907-A0AB-FFB88C3FCCA3")
    _GLScript_Engine : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ short *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_native( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_native( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_gles( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_gles( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_glver( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_shader( 
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_shader( 
            /* [in] */ BSTR value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_windowTitle( 
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_windowTitle( 
            /* [in] */ BSTR value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_windowWidth( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_windowWidth( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_windowHeight( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_windowHeight( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_viewPortLeft( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_viewPortLeft( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_viewPortTop( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_viewPortTop( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_viewPortWidth( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_viewPortWidth( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_viewPortHeight( 
            /* [retval][out] */ int *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_viewPortHeight( 
            /* [in] */ int value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ortho( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_ortho( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_animation( 
            /* [retval][out] */ VARIANT_BOOL *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_animation( 
            /* [in] */ VARIANT_BOOL value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_frameRate( 
            /* [retval][out] */ short *pValue) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_frameRate( 
            /* [in] */ short value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_fps( 
            /* [retval][out] */ short *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE require( 
            /* [in] */ BSTR path,
            /* [optional][in] */ VARIANT options,
            /* [retval][out] */ IDispatch **ppDispatch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE byteArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ubyteArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE shortArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ushortArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE intArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE uintArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE floatArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE doubleArray( 
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _GLScript_EngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _GLScript_Engine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _GLScript_Engine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _GLScript_Engine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _GLScript_Engine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _GLScript_Engine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _GLScript_Engine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _GLScript_Engine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            _GLScript_Engine * This,
            /* [retval][out] */ short *pValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_native )( 
            _GLScript_Engine * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_native )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT_BOOL value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_gles )( 
            _GLScript_Engine * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_gles )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT_BOOL value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_glver )( 
            _GLScript_Engine * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_shader )( 
            _GLScript_Engine * This,
            /* [retval][out] */ BSTR *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_shader )( 
            _GLScript_Engine * This,
            /* [in] */ BSTR value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_windowTitle )( 
            _GLScript_Engine * This,
            /* [retval][out] */ BSTR *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_windowTitle )( 
            _GLScript_Engine * This,
            /* [in] */ BSTR value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_windowWidth )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_windowWidth )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_windowHeight )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_windowHeight )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_viewPortLeft )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_viewPortLeft )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_viewPortTop )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_viewPortTop )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_viewPortWidth )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_viewPortWidth )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_viewPortHeight )( 
            _GLScript_Engine * This,
            /* [retval][out] */ int *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_viewPortHeight )( 
            _GLScript_Engine * This,
            /* [in] */ int value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ortho )( 
            _GLScript_Engine * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_ortho )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT_BOOL value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_animation )( 
            _GLScript_Engine * This,
            /* [retval][out] */ VARIANT_BOOL *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_animation )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT_BOOL value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_frameRate )( 
            _GLScript_Engine * This,
            /* [retval][out] */ short *pValue);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_frameRate )( 
            _GLScript_Engine * This,
            /* [in] */ short value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_fps )( 
            _GLScript_Engine * This,
            /* [retval][out] */ short *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *require )( 
            _GLScript_Engine * This,
            /* [in] */ BSTR path,
            /* [optional][in] */ VARIANT options,
            /* [retval][out] */ IDispatch **ppDispatch);
        
        HRESULT ( STDMETHODCALLTYPE *byteArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *ubyteArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *shortArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *ushortArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *intArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *uintArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *floatArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        HRESULT ( STDMETHODCALLTYPE *doubleArray )( 
            _GLScript_Engine * This,
            /* [in] */ VARIANT varArrayConfig,
            /* [retval][out] */ _GLScript_Array **pOutArray);
        
        END_INTERFACE
    } _GLScript_EngineVtbl;

    interface _GLScript_Engine
    {
        CONST_VTBL struct _GLScript_EngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _GLScript_Engine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _GLScript_Engine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _GLScript_Engine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _GLScript_Engine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _GLScript_Engine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _GLScript_Engine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _GLScript_Engine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _GLScript_Engine_get_version(This,pValue)	\
    ( (This)->lpVtbl -> get_version(This,pValue) ) 

#define _GLScript_Engine_get_native(This,pValue)	\
    ( (This)->lpVtbl -> get_native(This,pValue) ) 

#define _GLScript_Engine_put_native(This,value)	\
    ( (This)->lpVtbl -> put_native(This,value) ) 

#define _GLScript_Engine_get_gles(This,pValue)	\
    ( (This)->lpVtbl -> get_gles(This,pValue) ) 

#define _GLScript_Engine_put_gles(This,value)	\
    ( (This)->lpVtbl -> put_gles(This,value) ) 

#define _GLScript_Engine_get_glver(This,pValue)	\
    ( (This)->lpVtbl -> get_glver(This,pValue) ) 

#define _GLScript_Engine_get_shader(This,pValue)	\
    ( (This)->lpVtbl -> get_shader(This,pValue) ) 

#define _GLScript_Engine_put_shader(This,value)	\
    ( (This)->lpVtbl -> put_shader(This,value) ) 

#define _GLScript_Engine_get_windowTitle(This,pValue)	\
    ( (This)->lpVtbl -> get_windowTitle(This,pValue) ) 

#define _GLScript_Engine_put_windowTitle(This,value)	\
    ( (This)->lpVtbl -> put_windowTitle(This,value) ) 

#define _GLScript_Engine_get_windowWidth(This,pValue)	\
    ( (This)->lpVtbl -> get_windowWidth(This,pValue) ) 

#define _GLScript_Engine_put_windowWidth(This,value)	\
    ( (This)->lpVtbl -> put_windowWidth(This,value) ) 

#define _GLScript_Engine_get_windowHeight(This,pValue)	\
    ( (This)->lpVtbl -> get_windowHeight(This,pValue) ) 

#define _GLScript_Engine_put_windowHeight(This,value)	\
    ( (This)->lpVtbl -> put_windowHeight(This,value) ) 

#define _GLScript_Engine_get_viewPortLeft(This,pValue)	\
    ( (This)->lpVtbl -> get_viewPortLeft(This,pValue) ) 

#define _GLScript_Engine_put_viewPortLeft(This,value)	\
    ( (This)->lpVtbl -> put_viewPortLeft(This,value) ) 

#define _GLScript_Engine_get_viewPortTop(This,pValue)	\
    ( (This)->lpVtbl -> get_viewPortTop(This,pValue) ) 

#define _GLScript_Engine_put_viewPortTop(This,value)	\
    ( (This)->lpVtbl -> put_viewPortTop(This,value) ) 

#define _GLScript_Engine_get_viewPortWidth(This,pValue)	\
    ( (This)->lpVtbl -> get_viewPortWidth(This,pValue) ) 

#define _GLScript_Engine_put_viewPortWidth(This,value)	\
    ( (This)->lpVtbl -> put_viewPortWidth(This,value) ) 

#define _GLScript_Engine_get_viewPortHeight(This,pValue)	\
    ( (This)->lpVtbl -> get_viewPortHeight(This,pValue) ) 

#define _GLScript_Engine_put_viewPortHeight(This,value)	\
    ( (This)->lpVtbl -> put_viewPortHeight(This,value) ) 

#define _GLScript_Engine_get_ortho(This,pValue)	\
    ( (This)->lpVtbl -> get_ortho(This,pValue) ) 

#define _GLScript_Engine_put_ortho(This,value)	\
    ( (This)->lpVtbl -> put_ortho(This,value) ) 

#define _GLScript_Engine_get_animation(This,pValue)	\
    ( (This)->lpVtbl -> get_animation(This,pValue) ) 

#define _GLScript_Engine_put_animation(This,value)	\
    ( (This)->lpVtbl -> put_animation(This,value) ) 

#define _GLScript_Engine_get_frameRate(This,pValue)	\
    ( (This)->lpVtbl -> get_frameRate(This,pValue) ) 

#define _GLScript_Engine_put_frameRate(This,value)	\
    ( (This)->lpVtbl -> put_frameRate(This,value) ) 

#define _GLScript_Engine_get_fps(This,pValue)	\
    ( (This)->lpVtbl -> get_fps(This,pValue) ) 

#define _GLScript_Engine_require(This,path,options,ppDispatch)	\
    ( (This)->lpVtbl -> require(This,path,options,ppDispatch) ) 

#define _GLScript_Engine_byteArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> byteArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_ubyteArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> ubyteArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_shortArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> shortArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_ushortArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> ushortArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_intArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> intArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_uintArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> uintArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_floatArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> floatArray(This,varArrayConfig,pOutArray) ) 

#define _GLScript_Engine_doubleArray(This,varArrayConfig,pOutArray)	\
    ( (This)->lpVtbl -> doubleArray(This,varArrayConfig,pOutArray) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___GLScript_Engine_INTERFACE_DEFINED__ */


#ifndef ___GLScript_Context_INTERFACE_DEFINED__
#define ___GLScript_Context_INTERFACE_DEFINED__

/* interface _GLScript_Context */
/* [nonextensible][hidden][oleautomation][dual][uuid][object] */ 


DEFINE_GUID(IID__GLScript_Context,0x83711F8E,0x7E57,0x4016,0x84,0x74,0xBF,0xCF,0x37,0x6B,0x0F,0x46);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83711F8E-7E57-4016-8474-BFCF376B0F46")
    _GLScript_Context : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE flush( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glAccum( 
            /* [in] */ unsigned int op,
            /* [in] */ float value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glAlphaFunc( 
            /* [in] */ unsigned int func,
            /* [in] */ float ref1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glAreTexturesResident( 
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures,
            /* [in] */ _GLScript_Array *residences,
            /* [retval][out] */ unsigned char *pRet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glArrayElement( 
            /* [in] */ int i) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glBegin( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glBindTexture( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int texture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glBitmap( 
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ float xorig,
            /* [in] */ float yorig,
            /* [in] */ float xmove,
            /* [in] */ float ymove,
            /* [in] */ _GLScript_Array *bitmap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glBlendFunc( 
            /* [in] */ unsigned int sfactor,
            /* [in] */ unsigned int dfactor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCallList( 
            /* [in] */ unsigned int list) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCallLists( 
            /* [in] */ int n,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *lists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClear( 
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClearAccum( 
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClearColor( 
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClearDepth( 
            /* [in] */ double depth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClearIndex( 
            /* [in] */ float c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClearStencil( 
            /* [in] */ int s) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glClipPlane( 
            /* [in] */ unsigned int plane,
            /* [in] */ _GLScript_Array *equation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3b( 
            /* [in] */ signed char red,
            /* [in] */ signed char green,
            /* [in] */ signed char blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3bv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3d( 
            /* [in] */ double red,
            /* [in] */ double green,
            /* [in] */ double blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3f( 
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3i( 
            /* [in] */ int red,
            /* [in] */ int green,
            /* [in] */ int blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3s( 
            /* [in] */ short red,
            /* [in] */ short green,
            /* [in] */ short blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3ub( 
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3ubv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3ui( 
            /* [in] */ unsigned int red,
            /* [in] */ unsigned int green,
            /* [in] */ unsigned int blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3uiv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3us( 
            /* [in] */ unsigned short red,
            /* [in] */ unsigned short green,
            /* [in] */ unsigned short blue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor3usv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4b( 
            /* [in] */ signed char red,
            /* [in] */ signed char green,
            /* [in] */ signed char blue,
            /* [in] */ signed char alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4bv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4d( 
            /* [in] */ double red,
            /* [in] */ double green,
            /* [in] */ double blue,
            /* [in] */ double alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4f( 
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4i( 
            /* [in] */ int red,
            /* [in] */ int green,
            /* [in] */ int blue,
            /* [in] */ int alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4s( 
            /* [in] */ short red,
            /* [in] */ short green,
            /* [in] */ short blue,
            /* [in] */ short alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4ub( 
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue,
            /* [in] */ unsigned char alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4ubv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4ui( 
            /* [in] */ unsigned int red,
            /* [in] */ unsigned int green,
            /* [in] */ unsigned int blue,
            /* [in] */ unsigned int alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4uiv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4us( 
            /* [in] */ unsigned short red,
            /* [in] */ unsigned short green,
            /* [in] */ unsigned short blue,
            /* [in] */ unsigned short alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColor4usv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColorMask( 
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue,
            /* [in] */ unsigned char alpha) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColorMaterial( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glColorPointer( 
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCopyPixels( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCopyTexImage1D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int internalFormat,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int border) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCopyTexImage2D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int internalFormat,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int border) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCopyTexSubImage1D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCopyTexSubImage2D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int yoffset,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glCullFace( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDeleteLists( 
            /* [in] */ unsigned int list,
            /* [in] */ int range) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDeleteTextures( 
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDepthFunc( 
            /* [in] */ unsigned int func) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDepthMask( 
            /* [in] */ unsigned char flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDepthRange( 
            /* [in] */ double zNear,
            /* [in] */ double zFar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDisable( 
            /* [in] */ unsigned int cap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDisableClientState( 
            /* [in] */ unsigned int array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDrawArrays( 
            /* [in] */ unsigned int mode,
            /* [in] */ int first,
            /* [in] */ int count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDrawBuffer( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDrawElements( 
            /* [in] */ unsigned int mode,
            /* [in] */ int count,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *indices) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glDrawPixels( 
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEdgeFlag( 
            /* [in] */ unsigned char flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEdgeFlagPointer( 
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEdgeFlagv( 
            /* [in] */ _GLScript_Array *flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEnable( 
            /* [in] */ unsigned int cap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEnableClientState( 
            /* [in] */ unsigned int array) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEndList( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord1d( 
            /* [in] */ double u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord1dv( 
            /* [in] */ _GLScript_Array *u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord1f( 
            /* [in] */ float u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord1fv( 
            /* [in] */ _GLScript_Array *u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord2d( 
            /* [in] */ double u,
            /* [in] */ double v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord2dv( 
            /* [in] */ _GLScript_Array *u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord2f( 
            /* [in] */ float u,
            /* [in] */ float v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalCoord2fv( 
            /* [in] */ _GLScript_Array *u) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalMesh1( 
            /* [in] */ unsigned int mode,
            /* [in] */ int i1,
            /* [in] */ int i2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalMesh2( 
            /* [in] */ unsigned int mode,
            /* [in] */ int i1,
            /* [in] */ int i2,
            /* [in] */ int j1,
            /* [in] */ int j2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalPoint1( 
            /* [in] */ int i) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glEvalPoint2( 
            /* [in] */ int i,
            /* [in] */ int j) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFeedbackBuffer( 
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFinish( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFlush( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFogf( 
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFogfv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFogi( 
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFogiv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFrontFace( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glFrustum( 
            /* [in] */ double left,
            /* [in] */ double right,
            /* [in] */ double bottom,
            /* [in] */ double top,
            /* [in] */ double zNear,
            /* [in] */ double zFar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGenLists( 
            /* [in] */ int range,
            /* [retval][out] */ unsigned int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGenTextures( 
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetBooleanv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetClipPlane( 
            /* [in] */ unsigned int plane,
            /* [in] */ _GLScript_Array *equation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetDoublev( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetError( 
            /* [retval][out] */ unsigned int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetFloatv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetIntegerv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetLightfv( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetLightiv( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetMapdv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetMapfv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetMapiv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetMaterialfv( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetMaterialiv( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetPixelMapfv( 
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetPixelMapuiv( 
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetPixelMapusv( 
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetPointerv( 
            /* [in] */ unsigned int pname,
            /* [in] */ void **params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetPolygonStipple( 
            /* [in] */ _GLScript_Array *mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetString( 
            /* [in] */ unsigned int name,
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexEnvfv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexEnviv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexGendv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexGenfv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexGeniv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexImage( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexLevelParameterfv( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexLevelParameteriv( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexParameterfv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glGetTexParameteriv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glHint( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexMask( 
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexPointer( 
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexd( 
            /* [in] */ double c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexdv( 
            /* [in] */ _GLScript_Array *c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexf( 
            /* [in] */ float c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexfv( 
            /* [in] */ _GLScript_Array *c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexi( 
            /* [in] */ int c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexiv( 
            /* [in] */ _GLScript_Array *c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexs( 
            /* [in] */ short c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexsv( 
            /* [in] */ _GLScript_Array *c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexub( 
            /* [in] */ unsigned char c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIndexubv( 
            /* [in] */ _GLScript_Array *c) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glInitNames( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glInterleavedArrays( 
            /* [in] */ unsigned int format,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIsEnabled( 
            /* [in] */ unsigned int cap,
            /* [retval][out] */ unsigned char *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIsList( 
            /* [in] */ unsigned int list,
            /* [retval][out] */ unsigned char *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glIsTexture( 
            /* [in] */ unsigned int texture,
            /* [retval][out] */ unsigned char *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightModelf( 
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightModelfv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightModeli( 
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightModeliv( 
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightf( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightfv( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLighti( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLightiv( 
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLineStipple( 
            /* [in] */ int factor,
            /* [in] */ unsigned short pattern) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLineWidth( 
            /* [in] */ float width) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glListBase( 
            /* [in] */ unsigned int base) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLoadIdentity( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLoadMatrixd( 
            /* [in] */ _GLScript_Array *m) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLoadMatrixf( 
            /* [in] */ _GLScript_Array *m) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLoadName( 
            /* [in] */ unsigned int name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glLogicOp( 
            /* [in] */ unsigned int opcode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMap1d( 
            /* [in] */ unsigned int target,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int stride,
            /* [in] */ int order,
            /* [in] */ _GLScript_Array *points) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMap1f( 
            /* [in] */ unsigned int target,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int stride,
            /* [in] */ int order,
            /* [in] */ _GLScript_Array *points) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMap2d( 
            /* [in] */ unsigned int target,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int ustride,
            /* [in] */ int uorder,
            /* [in] */ double v1,
            /* [in] */ double v2,
            /* [in] */ int vstride,
            /* [in] */ int vorder,
            /* [in] */ _GLScript_Array *points) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMap2f( 
            /* [in] */ unsigned int target,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int ustride,
            /* [in] */ int uorder,
            /* [in] */ float v1,
            /* [in] */ float v2,
            /* [in] */ int vstride,
            /* [in] */ int vorder,
            /* [in] */ _GLScript_Array *points) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMapGrid1d( 
            /* [in] */ int un,
            /* [in] */ double u1,
            /* [in] */ double u2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMapGrid1f( 
            /* [in] */ int un,
            /* [in] */ float u1,
            /* [in] */ float u2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMapGrid2d( 
            /* [in] */ int un,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int vn,
            /* [in] */ double v1,
            /* [in] */ double v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMapGrid2f( 
            /* [in] */ int un,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int vn,
            /* [in] */ float v1,
            /* [in] */ float v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMaterialf( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMaterialfv( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMateriali( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMaterialiv( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMatrixMode( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMultMatrixd( 
            /* [in] */ _GLScript_Array *m) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glMultMatrixf( 
            /* [in] */ _GLScript_Array *m) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNewList( 
            /* [in] */ unsigned int list,
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3b( 
            /* [in] */ signed char nx,
            /* [in] */ signed char ny,
            /* [in] */ signed char nz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3bv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3d( 
            /* [in] */ double nx,
            /* [in] */ double ny,
            /* [in] */ double nz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3f( 
            /* [in] */ float nx,
            /* [in] */ float ny,
            /* [in] */ float nz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3i( 
            /* [in] */ int nx,
            /* [in] */ int ny,
            /* [in] */ int nz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3s( 
            /* [in] */ short nx,
            /* [in] */ short ny,
            /* [in] */ short nz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormal3sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glNormalPointer( 
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glOrtho( 
            /* [in] */ double left,
            /* [in] */ double right,
            /* [in] */ double bottom,
            /* [in] */ double top,
            /* [in] */ double zNear,
            /* [in] */ double zFar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPassThrough( 
            /* [in] */ float token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelMapfv( 
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelMapuiv( 
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelMapusv( 
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelStoref( 
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelStorei( 
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelTransferf( 
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelTransferi( 
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPixelZoom( 
            /* [in] */ float xfactor,
            /* [in] */ float yfactor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPointSize( 
            /* [in] */ float size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPolygonMode( 
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPolygonOffset( 
            /* [in] */ float factor,
            /* [in] */ float units) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPolygonStipple( 
            /* [in] */ _GLScript_Array *mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPopAttrib( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPopClientAttrib( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPopMatrix( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPopName( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPrioritizeTextures( 
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures,
            /* [in] */ _GLScript_Array *priorities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPushAttrib( 
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPushClientAttrib( 
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPushMatrix( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glPushName( 
            /* [in] */ unsigned int name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2d( 
            /* [in] */ double x,
            /* [in] */ double y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2f( 
            /* [in] */ float x,
            /* [in] */ float y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2i( 
            /* [in] */ int x,
            /* [in] */ int y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2s( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos2sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3d( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3f( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3i( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3s( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos3sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4d( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z,
            /* [in] */ double w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4f( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z,
            /* [in] */ float w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4i( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z,
            /* [in] */ int w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4s( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z,
            /* [in] */ short w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRasterPos4sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glReadBuffer( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glReadPixels( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectd( 
            /* [in] */ double x1,
            /* [in] */ double y1,
            /* [in] */ double x2,
            /* [in] */ double y2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectdv( 
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectf( 
            /* [in] */ float x1,
            /* [in] */ float y1,
            /* [in] */ float x2,
            /* [in] */ float y2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectfv( 
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRecti( 
            /* [in] */ int x1,
            /* [in] */ int y1,
            /* [in] */ int x2,
            /* [in] */ int y2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectiv( 
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRects( 
            /* [in] */ short x1,
            /* [in] */ short y1,
            /* [in] */ short x2,
            /* [in] */ short y2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRectsv( 
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRenderMode( 
            /* [in] */ unsigned int mode,
            /* [retval][out] */ int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRotated( 
            /* [in] */ double angle,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glRotatef( 
            /* [in] */ float angle,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glScaled( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glScalef( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glScissor( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glSelectBuffer( 
            /* [in] */ int size,
            /* [in] */ _GLScript_Array *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glShadeModel( 
            /* [in] */ unsigned int mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glStencilFunc( 
            /* [in] */ unsigned int func,
            /* [in] */ int ref,
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glStencilMask( 
            /* [in] */ unsigned int mask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glStencilOp( 
            /* [in] */ unsigned int fail,
            /* [in] */ unsigned int zfail,
            /* [in] */ unsigned int zpass) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1d( 
            /* [in] */ double s) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1f( 
            /* [in] */ float s) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1i( 
            /* [in] */ int s) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1s( 
            /* [in] */ short s) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord1sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2d( 
            /* [in] */ double s,
            /* [in] */ double t) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2f( 
            /* [in] */ float s,
            /* [in] */ float t) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2i( 
            /* [in] */ int s,
            /* [in] */ int t) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2s( 
            /* [in] */ short s,
            /* [in] */ short t) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord2sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3d( 
            /* [in] */ double s,
            /* [in] */ double t,
            /* [in] */ double r) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3f( 
            /* [in] */ float s,
            /* [in] */ float t,
            /* [in] */ float r) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3i( 
            /* [in] */ int s,
            /* [in] */ int t,
            /* [in] */ int r) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3s( 
            /* [in] */ short s,
            /* [in] */ short t,
            /* [in] */ short r) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord3sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4d( 
            /* [in] */ double s,
            /* [in] */ double t,
            /* [in] */ double r,
            /* [in] */ double q) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4f( 
            /* [in] */ float s,
            /* [in] */ float t,
            /* [in] */ float r,
            /* [in] */ float q) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4i( 
            /* [in] */ int s,
            /* [in] */ int t,
            /* [in] */ int r,
            /* [in] */ int q) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4s( 
            /* [in] */ short s,
            /* [in] */ short t,
            /* [in] */ short r,
            /* [in] */ short q) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoord4sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexCoordPointer( 
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexEnvf( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexEnvfv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexEnvi( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexEnviv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGend( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ double param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGendv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGenf( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGenfv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGeni( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexGeniv( 
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexImage1D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int internalformat,
            /* [in] */ int width,
            /* [in] */ int border,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexImage2D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int internalformat,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int border,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexParameterf( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ float param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexParameterfv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexParameteri( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ int param) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexParameteriv( 
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexSubImage1D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int width,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTexSubImage2D( 
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int yoffset,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTranslated( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glTranslatef( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2d( 
            /* [in] */ double x,
            /* [in] */ double y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2f( 
            /* [in] */ float x,
            /* [in] */ float y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2i( 
            /* [in] */ int x,
            /* [in] */ int y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2s( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex2sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3d( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3f( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3i( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3s( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex3sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4d( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z,
            /* [in] */ double w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4dv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4f( 
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z,
            /* [in] */ float w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4fv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4i( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z,
            /* [in] */ int w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4iv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4s( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z,
            /* [in] */ short w) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertex4sv( 
            /* [in] */ _GLScript_Array *v) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glVertexPointer( 
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE glViewport( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _GLScript_ContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _GLScript_Context * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _GLScript_Context * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _GLScript_Context * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _GLScript_Context * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _GLScript_Context * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _GLScript_Context * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *flush )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glAccum )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int op,
            /* [in] */ float value);
        
        HRESULT ( STDMETHODCALLTYPE *glAlphaFunc )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int func,
            /* [in] */ float ref1);
        
        HRESULT ( STDMETHODCALLTYPE *glAreTexturesResident )( 
            _GLScript_Context * This,
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures,
            /* [in] */ _GLScript_Array *residences,
            /* [retval][out] */ unsigned char *pRet);
        
        HRESULT ( STDMETHODCALLTYPE *glArrayElement )( 
            _GLScript_Context * This,
            /* [in] */ int i);
        
        HRESULT ( STDMETHODCALLTYPE *glBegin )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glBindTexture )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int texture);
        
        HRESULT ( STDMETHODCALLTYPE *glBitmap )( 
            _GLScript_Context * This,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ float xorig,
            /* [in] */ float yorig,
            /* [in] */ float xmove,
            /* [in] */ float ymove,
            /* [in] */ _GLScript_Array *bitmap);
        
        HRESULT ( STDMETHODCALLTYPE *glBlendFunc )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int sfactor,
            /* [in] */ unsigned int dfactor);
        
        HRESULT ( STDMETHODCALLTYPE *glCallList )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int list);
        
        HRESULT ( STDMETHODCALLTYPE *glCallLists )( 
            _GLScript_Context * This,
            /* [in] */ int n,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *lists);
        
        HRESULT ( STDMETHODCALLTYPE *glClear )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glClearAccum )( 
            _GLScript_Context * This,
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glClearColor )( 
            _GLScript_Context * This,
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glClearDepth )( 
            _GLScript_Context * This,
            /* [in] */ double depth);
        
        HRESULT ( STDMETHODCALLTYPE *glClearIndex )( 
            _GLScript_Context * This,
            /* [in] */ float c);
        
        HRESULT ( STDMETHODCALLTYPE *glClearStencil )( 
            _GLScript_Context * This,
            /* [in] */ int s);
        
        HRESULT ( STDMETHODCALLTYPE *glClipPlane )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int plane,
            /* [in] */ _GLScript_Array *equation);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3b )( 
            _GLScript_Context * This,
            /* [in] */ signed char red,
            /* [in] */ signed char green,
            /* [in] */ signed char blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3bv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3d )( 
            _GLScript_Context * This,
            /* [in] */ double red,
            /* [in] */ double green,
            /* [in] */ double blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3f )( 
            _GLScript_Context * This,
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3i )( 
            _GLScript_Context * This,
            /* [in] */ int red,
            /* [in] */ int green,
            /* [in] */ int blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3s )( 
            _GLScript_Context * This,
            /* [in] */ short red,
            /* [in] */ short green,
            /* [in] */ short blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3ub )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3ubv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3ui )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int red,
            /* [in] */ unsigned int green,
            /* [in] */ unsigned int blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3uiv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3us )( 
            _GLScript_Context * This,
            /* [in] */ unsigned short red,
            /* [in] */ unsigned short green,
            /* [in] */ unsigned short blue);
        
        HRESULT ( STDMETHODCALLTYPE *glColor3usv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4b )( 
            _GLScript_Context * This,
            /* [in] */ signed char red,
            /* [in] */ signed char green,
            /* [in] */ signed char blue,
            /* [in] */ signed char alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4bv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4d )( 
            _GLScript_Context * This,
            /* [in] */ double red,
            /* [in] */ double green,
            /* [in] */ double blue,
            /* [in] */ double alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4f )( 
            _GLScript_Context * This,
            /* [in] */ float red,
            /* [in] */ float green,
            /* [in] */ float blue,
            /* [in] */ float alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4i )( 
            _GLScript_Context * This,
            /* [in] */ int red,
            /* [in] */ int green,
            /* [in] */ int blue,
            /* [in] */ int alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4s )( 
            _GLScript_Context * This,
            /* [in] */ short red,
            /* [in] */ short green,
            /* [in] */ short blue,
            /* [in] */ short alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4ub )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue,
            /* [in] */ unsigned char alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4ubv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4ui )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int red,
            /* [in] */ unsigned int green,
            /* [in] */ unsigned int blue,
            /* [in] */ unsigned int alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4uiv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4us )( 
            _GLScript_Context * This,
            /* [in] */ unsigned short red,
            /* [in] */ unsigned short green,
            /* [in] */ unsigned short blue,
            /* [in] */ unsigned short alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColor4usv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glColorMask )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char red,
            /* [in] */ unsigned char green,
            /* [in] */ unsigned char blue,
            /* [in] */ unsigned char alpha);
        
        HRESULT ( STDMETHODCALLTYPE *glColorMaterial )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glColorPointer )( 
            _GLScript_Context * This,
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glCopyPixels )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int type);
        
        HRESULT ( STDMETHODCALLTYPE *glCopyTexImage1D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int internalFormat,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int border);
        
        HRESULT ( STDMETHODCALLTYPE *glCopyTexImage2D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int internalFormat,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int border);
        
        HRESULT ( STDMETHODCALLTYPE *glCopyTexSubImage1D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width);
        
        HRESULT ( STDMETHODCALLTYPE *glCopyTexSubImage2D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int yoffset,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height);
        
        HRESULT ( STDMETHODCALLTYPE *glCullFace )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glDeleteLists )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int list,
            /* [in] */ int range);
        
        HRESULT ( STDMETHODCALLTYPE *glDeleteTextures )( 
            _GLScript_Context * This,
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures);
        
        HRESULT ( STDMETHODCALLTYPE *glDepthFunc )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int func);
        
        HRESULT ( STDMETHODCALLTYPE *glDepthMask )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char flag);
        
        HRESULT ( STDMETHODCALLTYPE *glDepthRange )( 
            _GLScript_Context * This,
            /* [in] */ double zNear,
            /* [in] */ double zFar);
        
        HRESULT ( STDMETHODCALLTYPE *glDisable )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int cap);
        
        HRESULT ( STDMETHODCALLTYPE *glDisableClientState )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int array);
        
        HRESULT ( STDMETHODCALLTYPE *glDrawArrays )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode,
            /* [in] */ int first,
            /* [in] */ int count);
        
        HRESULT ( STDMETHODCALLTYPE *glDrawBuffer )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glDrawElements )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode,
            /* [in] */ int count,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *indices);
        
        HRESULT ( STDMETHODCALLTYPE *glDrawPixels )( 
            _GLScript_Context * This,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glEdgeFlag )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char flag);
        
        HRESULT ( STDMETHODCALLTYPE *glEdgeFlagPointer )( 
            _GLScript_Context * This,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glEdgeFlagv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *flag);
        
        HRESULT ( STDMETHODCALLTYPE *glEnable )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int cap);
        
        HRESULT ( STDMETHODCALLTYPE *glEnableClientState )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int array);
        
        HRESULT ( STDMETHODCALLTYPE *glEnd )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glEndList )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord1d )( 
            _GLScript_Context * This,
            /* [in] */ double u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord1dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord1f )( 
            _GLScript_Context * This,
            /* [in] */ float u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord1fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord2d )( 
            _GLScript_Context * This,
            /* [in] */ double u,
            /* [in] */ double v);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord2dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord2f )( 
            _GLScript_Context * This,
            /* [in] */ float u,
            /* [in] */ float v);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalCoord2fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *u);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalMesh1 )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode,
            /* [in] */ int i1,
            /* [in] */ int i2);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalMesh2 )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode,
            /* [in] */ int i1,
            /* [in] */ int i2,
            /* [in] */ int j1,
            /* [in] */ int j2);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalPoint1 )( 
            _GLScript_Context * This,
            /* [in] */ int i);
        
        HRESULT ( STDMETHODCALLTYPE *glEvalPoint2 )( 
            _GLScript_Context * This,
            /* [in] */ int i,
            /* [in] */ int j);
        
        HRESULT ( STDMETHODCALLTYPE *glFeedbackBuffer )( 
            _GLScript_Context * This,
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *buffer);
        
        HRESULT ( STDMETHODCALLTYPE *glFinish )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glFlush )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glFogf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glFogfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glFogi )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glFogiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glFrontFace )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glFrustum )( 
            _GLScript_Context * This,
            /* [in] */ double left,
            /* [in] */ double right,
            /* [in] */ double bottom,
            /* [in] */ double top,
            /* [in] */ double zNear,
            /* [in] */ double zFar);
        
        HRESULT ( STDMETHODCALLTYPE *glGenLists )( 
            _GLScript_Context * This,
            /* [in] */ int range,
            /* [retval][out] */ unsigned int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glGenTextures )( 
            _GLScript_Context * This,
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures);
        
        HRESULT ( STDMETHODCALLTYPE *glGetBooleanv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetClipPlane )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int plane,
            /* [in] */ _GLScript_Array *equation);
        
        HRESULT ( STDMETHODCALLTYPE *glGetDoublev )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetError )( 
            _GLScript_Context * This,
            /* [retval][out] */ unsigned int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glGetFloatv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetIntegerv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetLightfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetLightiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetMapdv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glGetMapfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glGetMapiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int query,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glGetMaterialfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetMaterialiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetPixelMapfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glGetPixelMapuiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glGetPixelMapusv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glGetPointerv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ void **params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetPolygonStipple )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *mask);
        
        HRESULT ( STDMETHODCALLTYPE *glGetString )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int name,
            /* [retval][out] */ BSTR *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexEnvfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexEnviv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexGendv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexGenfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexGeniv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexImage )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexLevelParameterfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexLevelParameteriv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexParameterfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glGetTexParameteriv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glHint )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexMask )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexPointer )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexd )( 
            _GLScript_Context * This,
            /* [in] */ double c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexdv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexf )( 
            _GLScript_Context * This,
            /* [in] */ float c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexfv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexi )( 
            _GLScript_Context * This,
            /* [in] */ int c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexiv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexs )( 
            _GLScript_Context * This,
            /* [in] */ short c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexsv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexub )( 
            _GLScript_Context * This,
            /* [in] */ unsigned char c);
        
        HRESULT ( STDMETHODCALLTYPE *glIndexubv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *c);
        
        HRESULT ( STDMETHODCALLTYPE *glInitNames )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glInterleavedArrays )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int format,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glIsEnabled )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int cap,
            /* [retval][out] */ unsigned char *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glIsList )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int list,
            /* [retval][out] */ unsigned char *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glIsTexture )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int texture,
            /* [retval][out] */ unsigned char *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glLightModelf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glLightModelfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glLightModeli )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glLightModeliv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glLightf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glLightfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glLighti )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glLightiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int light,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glLineStipple )( 
            _GLScript_Context * This,
            /* [in] */ int factor,
            /* [in] */ unsigned short pattern);
        
        HRESULT ( STDMETHODCALLTYPE *glLineWidth )( 
            _GLScript_Context * This,
            /* [in] */ float width);
        
        HRESULT ( STDMETHODCALLTYPE *glListBase )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int base);
        
        HRESULT ( STDMETHODCALLTYPE *glLoadIdentity )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glLoadMatrixd )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *m);
        
        HRESULT ( STDMETHODCALLTYPE *glLoadMatrixf )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *m);
        
        HRESULT ( STDMETHODCALLTYPE *glLoadName )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int name);
        
        HRESULT ( STDMETHODCALLTYPE *glLogicOp )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int opcode);
        
        HRESULT ( STDMETHODCALLTYPE *glMap1d )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int stride,
            /* [in] */ int order,
            /* [in] */ _GLScript_Array *points);
        
        HRESULT ( STDMETHODCALLTYPE *glMap1f )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int stride,
            /* [in] */ int order,
            /* [in] */ _GLScript_Array *points);
        
        HRESULT ( STDMETHODCALLTYPE *glMap2d )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int ustride,
            /* [in] */ int uorder,
            /* [in] */ double v1,
            /* [in] */ double v2,
            /* [in] */ int vstride,
            /* [in] */ int vorder,
            /* [in] */ _GLScript_Array *points);
        
        HRESULT ( STDMETHODCALLTYPE *glMap2f )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int ustride,
            /* [in] */ int uorder,
            /* [in] */ float v1,
            /* [in] */ float v2,
            /* [in] */ int vstride,
            /* [in] */ int vorder,
            /* [in] */ _GLScript_Array *points);
        
        HRESULT ( STDMETHODCALLTYPE *glMapGrid1d )( 
            _GLScript_Context * This,
            /* [in] */ int un,
            /* [in] */ double u1,
            /* [in] */ double u2);
        
        HRESULT ( STDMETHODCALLTYPE *glMapGrid1f )( 
            _GLScript_Context * This,
            /* [in] */ int un,
            /* [in] */ float u1,
            /* [in] */ float u2);
        
        HRESULT ( STDMETHODCALLTYPE *glMapGrid2d )( 
            _GLScript_Context * This,
            /* [in] */ int un,
            /* [in] */ double u1,
            /* [in] */ double u2,
            /* [in] */ int vn,
            /* [in] */ double v1,
            /* [in] */ double v2);
        
        HRESULT ( STDMETHODCALLTYPE *glMapGrid2f )( 
            _GLScript_Context * This,
            /* [in] */ int un,
            /* [in] */ float u1,
            /* [in] */ float u2,
            /* [in] */ int vn,
            /* [in] */ float v1,
            /* [in] */ float v2);
        
        HRESULT ( STDMETHODCALLTYPE *glMaterialf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glMaterialfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glMateriali )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glMaterialiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glMatrixMode )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glMultMatrixd )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *m);
        
        HRESULT ( STDMETHODCALLTYPE *glMultMatrixf )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *m);
        
        HRESULT ( STDMETHODCALLTYPE *glNewList )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int list,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3b )( 
            _GLScript_Context * This,
            /* [in] */ signed char nx,
            /* [in] */ signed char ny,
            /* [in] */ signed char nz);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3bv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3d )( 
            _GLScript_Context * This,
            /* [in] */ double nx,
            /* [in] */ double ny,
            /* [in] */ double nz);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3f )( 
            _GLScript_Context * This,
            /* [in] */ float nx,
            /* [in] */ float ny,
            /* [in] */ float nz);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3i )( 
            _GLScript_Context * This,
            /* [in] */ int nx,
            /* [in] */ int ny,
            /* [in] */ int nz);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3s )( 
            _GLScript_Context * This,
            /* [in] */ short nx,
            /* [in] */ short ny,
            /* [in] */ short nz);
        
        HRESULT ( STDMETHODCALLTYPE *glNormal3sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glNormalPointer )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glOrtho )( 
            _GLScript_Context * This,
            /* [in] */ double left,
            /* [in] */ double right,
            /* [in] */ double bottom,
            /* [in] */ double top,
            /* [in] */ double zNear,
            /* [in] */ double zFar);
        
        HRESULT ( STDMETHODCALLTYPE *glPassThrough )( 
            _GLScript_Context * This,
            /* [in] */ float token);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelMapfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelMapuiv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelMapusv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int map,
            /* [in] */ int mapsize,
            /* [in] */ _GLScript_Array *values);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelStoref )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelStorei )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelTransferf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelTransferi )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glPixelZoom )( 
            _GLScript_Context * This,
            /* [in] */ float xfactor,
            /* [in] */ float yfactor);
        
        HRESULT ( STDMETHODCALLTYPE *glPointSize )( 
            _GLScript_Context * This,
            /* [in] */ float size);
        
        HRESULT ( STDMETHODCALLTYPE *glPolygonMode )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int face,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glPolygonOffset )( 
            _GLScript_Context * This,
            /* [in] */ float factor,
            /* [in] */ float units);
        
        HRESULT ( STDMETHODCALLTYPE *glPolygonStipple )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *mask);
        
        HRESULT ( STDMETHODCALLTYPE *glPopAttrib )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glPopClientAttrib )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glPopMatrix )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glPopName )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glPrioritizeTextures )( 
            _GLScript_Context * This,
            /* [in] */ int n,
            /* [in] */ _GLScript_Array *textures,
            /* [in] */ _GLScript_Array *priorities);
        
        HRESULT ( STDMETHODCALLTYPE *glPushAttrib )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glPushClientAttrib )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glPushMatrix )( 
            _GLScript_Context * This);
        
        HRESULT ( STDMETHODCALLTYPE *glPushName )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int name);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos2sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos3sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z,
            /* [in] */ double w);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z,
            /* [in] */ float w);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z,
            /* [in] */ int w);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z,
            /* [in] */ short w);
        
        HRESULT ( STDMETHODCALLTYPE *glRasterPos4sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glReadBuffer )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glReadPixels )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glRectd )( 
            _GLScript_Context * This,
            /* [in] */ double x1,
            /* [in] */ double y1,
            /* [in] */ double x2,
            /* [in] */ double y2);
        
        HRESULT ( STDMETHODCALLTYPE *glRectdv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2);
        
        HRESULT ( STDMETHODCALLTYPE *glRectf )( 
            _GLScript_Context * This,
            /* [in] */ float x1,
            /* [in] */ float y1,
            /* [in] */ float x2,
            /* [in] */ float y2);
        
        HRESULT ( STDMETHODCALLTYPE *glRectfv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2);
        
        HRESULT ( STDMETHODCALLTYPE *glRecti )( 
            _GLScript_Context * This,
            /* [in] */ int x1,
            /* [in] */ int y1,
            /* [in] */ int x2,
            /* [in] */ int y2);
        
        HRESULT ( STDMETHODCALLTYPE *glRectiv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2);
        
        HRESULT ( STDMETHODCALLTYPE *glRects )( 
            _GLScript_Context * This,
            /* [in] */ short x1,
            /* [in] */ short y1,
            /* [in] */ short x2,
            /* [in] */ short y2);
        
        HRESULT ( STDMETHODCALLTYPE *glRectsv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v1,
            /* [in] */ _GLScript_Array *v2);
        
        HRESULT ( STDMETHODCALLTYPE *glRenderMode )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode,
            /* [retval][out] */ int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *glRotated )( 
            _GLScript_Context * This,
            /* [in] */ double angle,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z);
        
        HRESULT ( STDMETHODCALLTYPE *glRotatef )( 
            _GLScript_Context * This,
            /* [in] */ float angle,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z);
        
        HRESULT ( STDMETHODCALLTYPE *glScaled )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z);
        
        HRESULT ( STDMETHODCALLTYPE *glScalef )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z);
        
        HRESULT ( STDMETHODCALLTYPE *glScissor )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height);
        
        HRESULT ( STDMETHODCALLTYPE *glSelectBuffer )( 
            _GLScript_Context * This,
            /* [in] */ int size,
            /* [in] */ _GLScript_Array *buffer);
        
        HRESULT ( STDMETHODCALLTYPE *glShadeModel )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mode);
        
        HRESULT ( STDMETHODCALLTYPE *glStencilFunc )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int func,
            /* [in] */ int ref,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glStencilMask )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int mask);
        
        HRESULT ( STDMETHODCALLTYPE *glStencilOp )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int fail,
            /* [in] */ unsigned int zfail,
            /* [in] */ unsigned int zpass);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1d )( 
            _GLScript_Context * This,
            /* [in] */ double s);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1f )( 
            _GLScript_Context * This,
            /* [in] */ float s);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1i )( 
            _GLScript_Context * This,
            /* [in] */ int s);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1s )( 
            _GLScript_Context * This,
            /* [in] */ short s);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord1sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2d )( 
            _GLScript_Context * This,
            /* [in] */ double s,
            /* [in] */ double t);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2f )( 
            _GLScript_Context * This,
            /* [in] */ float s,
            /* [in] */ float t);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2i )( 
            _GLScript_Context * This,
            /* [in] */ int s,
            /* [in] */ int t);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2s )( 
            _GLScript_Context * This,
            /* [in] */ short s,
            /* [in] */ short t);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord2sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3d )( 
            _GLScript_Context * This,
            /* [in] */ double s,
            /* [in] */ double t,
            /* [in] */ double r);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3f )( 
            _GLScript_Context * This,
            /* [in] */ float s,
            /* [in] */ float t,
            /* [in] */ float r);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3i )( 
            _GLScript_Context * This,
            /* [in] */ int s,
            /* [in] */ int t,
            /* [in] */ int r);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3s )( 
            _GLScript_Context * This,
            /* [in] */ short s,
            /* [in] */ short t,
            /* [in] */ short r);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord3sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4d )( 
            _GLScript_Context * This,
            /* [in] */ double s,
            /* [in] */ double t,
            /* [in] */ double r,
            /* [in] */ double q);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4f )( 
            _GLScript_Context * This,
            /* [in] */ float s,
            /* [in] */ float t,
            /* [in] */ float r,
            /* [in] */ float q);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4i )( 
            _GLScript_Context * This,
            /* [in] */ int s,
            /* [in] */ int t,
            /* [in] */ int r,
            /* [in] */ int q);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4s )( 
            _GLScript_Context * This,
            /* [in] */ short s,
            /* [in] */ short t,
            /* [in] */ short r,
            /* [in] */ short q);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoord4sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glTexCoordPointer )( 
            _GLScript_Context * This,
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glTexEnvf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexEnvfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexEnvi )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexEnviv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGend )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ double param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGendv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGenf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGenfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGeni )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexGeniv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int coord,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexImage1D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int internalformat,
            /* [in] */ int width,
            /* [in] */ int border,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glTexImage2D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int internalformat,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ int border,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glTexParameterf )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ float param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexParameterfv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexParameteri )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ int param);
        
        HRESULT ( STDMETHODCALLTYPE *glTexParameteriv )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ unsigned int pname,
            /* [in] */ _GLScript_Array *params);
        
        HRESULT ( STDMETHODCALLTYPE *glTexSubImage1D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int width,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glTexSubImage2D )( 
            _GLScript_Context * This,
            /* [in] */ unsigned int target,
            /* [in] */ int level,
            /* [in] */ int xoffset,
            /* [in] */ int yoffset,
            /* [in] */ int width,
            /* [in] */ int height,
            /* [in] */ unsigned int format,
            /* [in] */ unsigned int type,
            /* [in] */ _GLScript_Array *pixels);
        
        HRESULT ( STDMETHODCALLTYPE *glTranslated )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z);
        
        HRESULT ( STDMETHODCALLTYPE *glTranslatef )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex2sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex3sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4d )( 
            _GLScript_Context * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [in] */ double z,
            /* [in] */ double w);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4dv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4f )( 
            _GLScript_Context * This,
            /* [in] */ float x,
            /* [in] */ float y,
            /* [in] */ float z,
            /* [in] */ float w);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4fv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4i )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int z,
            /* [in] */ int w);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4iv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4s )( 
            _GLScript_Context * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ short z,
            /* [in] */ short w);
        
        HRESULT ( STDMETHODCALLTYPE *glVertex4sv )( 
            _GLScript_Context * This,
            /* [in] */ _GLScript_Array *v);
        
        HRESULT ( STDMETHODCALLTYPE *glVertexPointer )( 
            _GLScript_Context * This,
            /* [in] */ int size,
            /* [in] */ unsigned int type,
            /* [in] */ int stride,
            /* [in] */ _GLScript_Array *pointer);
        
        HRESULT ( STDMETHODCALLTYPE *glViewport )( 
            _GLScript_Context * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int width,
            /* [in] */ int height);
        
        END_INTERFACE
    } _GLScript_ContextVtbl;

    interface _GLScript_Context
    {
        CONST_VTBL struct _GLScript_ContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _GLScript_Context_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _GLScript_Context_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _GLScript_Context_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _GLScript_Context_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _GLScript_Context_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _GLScript_Context_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _GLScript_Context_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _GLScript_Context_flush(This)	\
    ( (This)->lpVtbl -> flush(This) ) 

#define _GLScript_Context_glAccum(This,op,value)	\
    ( (This)->lpVtbl -> glAccum(This,op,value) ) 

#define _GLScript_Context_glAlphaFunc(This,func,ref1)	\
    ( (This)->lpVtbl -> glAlphaFunc(This,func,ref1) ) 

#define _GLScript_Context_glAreTexturesResident(This,n,textures,residences,pRet)	\
    ( (This)->lpVtbl -> glAreTexturesResident(This,n,textures,residences,pRet) ) 

#define _GLScript_Context_glArrayElement(This,i)	\
    ( (This)->lpVtbl -> glArrayElement(This,i) ) 

#define _GLScript_Context_glBegin(This,mode)	\
    ( (This)->lpVtbl -> glBegin(This,mode) ) 

#define _GLScript_Context_glBindTexture(This,target,texture)	\
    ( (This)->lpVtbl -> glBindTexture(This,target,texture) ) 

#define _GLScript_Context_glBitmap(This,width,height,xorig,yorig,xmove,ymove,bitmap)	\
    ( (This)->lpVtbl -> glBitmap(This,width,height,xorig,yorig,xmove,ymove,bitmap) ) 

#define _GLScript_Context_glBlendFunc(This,sfactor,dfactor)	\
    ( (This)->lpVtbl -> glBlendFunc(This,sfactor,dfactor) ) 

#define _GLScript_Context_glCallList(This,list)	\
    ( (This)->lpVtbl -> glCallList(This,list) ) 

#define _GLScript_Context_glCallLists(This,n,type,lists)	\
    ( (This)->lpVtbl -> glCallLists(This,n,type,lists) ) 

#define _GLScript_Context_glClear(This,mask)	\
    ( (This)->lpVtbl -> glClear(This,mask) ) 

#define _GLScript_Context_glClearAccum(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glClearAccum(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glClearColor(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glClearColor(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glClearDepth(This,depth)	\
    ( (This)->lpVtbl -> glClearDepth(This,depth) ) 

#define _GLScript_Context_glClearIndex(This,c)	\
    ( (This)->lpVtbl -> glClearIndex(This,c) ) 

#define _GLScript_Context_glClearStencil(This,s)	\
    ( (This)->lpVtbl -> glClearStencil(This,s) ) 

#define _GLScript_Context_glClipPlane(This,plane,equation)	\
    ( (This)->lpVtbl -> glClipPlane(This,plane,equation) ) 

#define _GLScript_Context_glColor3b(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3b(This,red,green,blue) ) 

#define _GLScript_Context_glColor3bv(This,v)	\
    ( (This)->lpVtbl -> glColor3bv(This,v) ) 

#define _GLScript_Context_glColor3d(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3d(This,red,green,blue) ) 

#define _GLScript_Context_glColor3dv(This,v)	\
    ( (This)->lpVtbl -> glColor3dv(This,v) ) 

#define _GLScript_Context_glColor3f(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3f(This,red,green,blue) ) 

#define _GLScript_Context_glColor3fv(This,v)	\
    ( (This)->lpVtbl -> glColor3fv(This,v) ) 

#define _GLScript_Context_glColor3i(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3i(This,red,green,blue) ) 

#define _GLScript_Context_glColor3iv(This,v)	\
    ( (This)->lpVtbl -> glColor3iv(This,v) ) 

#define _GLScript_Context_glColor3s(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3s(This,red,green,blue) ) 

#define _GLScript_Context_glColor3sv(This,v)	\
    ( (This)->lpVtbl -> glColor3sv(This,v) ) 

#define _GLScript_Context_glColor3ub(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3ub(This,red,green,blue) ) 

#define _GLScript_Context_glColor3ubv(This,v)	\
    ( (This)->lpVtbl -> glColor3ubv(This,v) ) 

#define _GLScript_Context_glColor3ui(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3ui(This,red,green,blue) ) 

#define _GLScript_Context_glColor3uiv(This,v)	\
    ( (This)->lpVtbl -> glColor3uiv(This,v) ) 

#define _GLScript_Context_glColor3us(This,red,green,blue)	\
    ( (This)->lpVtbl -> glColor3us(This,red,green,blue) ) 

#define _GLScript_Context_glColor3usv(This,v)	\
    ( (This)->lpVtbl -> glColor3usv(This,v) ) 

#define _GLScript_Context_glColor4b(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4b(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4bv(This,v)	\
    ( (This)->lpVtbl -> glColor4bv(This,v) ) 

#define _GLScript_Context_glColor4d(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4d(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4dv(This,v)	\
    ( (This)->lpVtbl -> glColor4dv(This,v) ) 

#define _GLScript_Context_glColor4f(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4f(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4fv(This,v)	\
    ( (This)->lpVtbl -> glColor4fv(This,v) ) 

#define _GLScript_Context_glColor4i(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4i(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4iv(This,v)	\
    ( (This)->lpVtbl -> glColor4iv(This,v) ) 

#define _GLScript_Context_glColor4s(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4s(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4sv(This,v)	\
    ( (This)->lpVtbl -> glColor4sv(This,v) ) 

#define _GLScript_Context_glColor4ub(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4ub(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4ubv(This,v)	\
    ( (This)->lpVtbl -> glColor4ubv(This,v) ) 

#define _GLScript_Context_glColor4ui(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4ui(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4uiv(This,v)	\
    ( (This)->lpVtbl -> glColor4uiv(This,v) ) 

#define _GLScript_Context_glColor4us(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColor4us(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColor4usv(This,v)	\
    ( (This)->lpVtbl -> glColor4usv(This,v) ) 

#define _GLScript_Context_glColorMask(This,red,green,blue,alpha)	\
    ( (This)->lpVtbl -> glColorMask(This,red,green,blue,alpha) ) 

#define _GLScript_Context_glColorMaterial(This,face,mode)	\
    ( (This)->lpVtbl -> glColorMaterial(This,face,mode) ) 

#define _GLScript_Context_glColorPointer(This,size,type,stride,pointer)	\
    ( (This)->lpVtbl -> glColorPointer(This,size,type,stride,pointer) ) 

#define _GLScript_Context_glCopyPixels(This,x,y,width,height,type)	\
    ( (This)->lpVtbl -> glCopyPixels(This,x,y,width,height,type) ) 

#define _GLScript_Context_glCopyTexImage1D(This,target,level,internalFormat,x,y,width,border)	\
    ( (This)->lpVtbl -> glCopyTexImage1D(This,target,level,internalFormat,x,y,width,border) ) 

#define _GLScript_Context_glCopyTexImage2D(This,target,level,internalFormat,x,y,width,height,border)	\
    ( (This)->lpVtbl -> glCopyTexImage2D(This,target,level,internalFormat,x,y,width,height,border) ) 

#define _GLScript_Context_glCopyTexSubImage1D(This,target,level,xoffset,x,y,width)	\
    ( (This)->lpVtbl -> glCopyTexSubImage1D(This,target,level,xoffset,x,y,width) ) 

#define _GLScript_Context_glCopyTexSubImage2D(This,target,level,xoffset,yoffset,x,y,width,height)	\
    ( (This)->lpVtbl -> glCopyTexSubImage2D(This,target,level,xoffset,yoffset,x,y,width,height) ) 

#define _GLScript_Context_glCullFace(This,mode)	\
    ( (This)->lpVtbl -> glCullFace(This,mode) ) 

#define _GLScript_Context_glDeleteLists(This,list,range)	\
    ( (This)->lpVtbl -> glDeleteLists(This,list,range) ) 

#define _GLScript_Context_glDeleteTextures(This,n,textures)	\
    ( (This)->lpVtbl -> glDeleteTextures(This,n,textures) ) 

#define _GLScript_Context_glDepthFunc(This,func)	\
    ( (This)->lpVtbl -> glDepthFunc(This,func) ) 

#define _GLScript_Context_glDepthMask(This,flag)	\
    ( (This)->lpVtbl -> glDepthMask(This,flag) ) 

#define _GLScript_Context_glDepthRange(This,zNear,zFar)	\
    ( (This)->lpVtbl -> glDepthRange(This,zNear,zFar) ) 

#define _GLScript_Context_glDisable(This,cap)	\
    ( (This)->lpVtbl -> glDisable(This,cap) ) 

#define _GLScript_Context_glDisableClientState(This,array)	\
    ( (This)->lpVtbl -> glDisableClientState(This,array) ) 

#define _GLScript_Context_glDrawArrays(This,mode,first,count)	\
    ( (This)->lpVtbl -> glDrawArrays(This,mode,first,count) ) 

#define _GLScript_Context_glDrawBuffer(This,mode)	\
    ( (This)->lpVtbl -> glDrawBuffer(This,mode) ) 

#define _GLScript_Context_glDrawElements(This,mode,count,type,indices)	\
    ( (This)->lpVtbl -> glDrawElements(This,mode,count,type,indices) ) 

#define _GLScript_Context_glDrawPixels(This,width,height,format,type,pixels)	\
    ( (This)->lpVtbl -> glDrawPixels(This,width,height,format,type,pixels) ) 

#define _GLScript_Context_glEdgeFlag(This,flag)	\
    ( (This)->lpVtbl -> glEdgeFlag(This,flag) ) 

#define _GLScript_Context_glEdgeFlagPointer(This,stride,pointer)	\
    ( (This)->lpVtbl -> glEdgeFlagPointer(This,stride,pointer) ) 

#define _GLScript_Context_glEdgeFlagv(This,flag)	\
    ( (This)->lpVtbl -> glEdgeFlagv(This,flag) ) 

#define _GLScript_Context_glEnable(This,cap)	\
    ( (This)->lpVtbl -> glEnable(This,cap) ) 

#define _GLScript_Context_glEnableClientState(This,array)	\
    ( (This)->lpVtbl -> glEnableClientState(This,array) ) 

#define _GLScript_Context_glEnd(This)	\
    ( (This)->lpVtbl -> glEnd(This) ) 

#define _GLScript_Context_glEndList(This)	\
    ( (This)->lpVtbl -> glEndList(This) ) 

#define _GLScript_Context_glEvalCoord1d(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord1d(This,u) ) 

#define _GLScript_Context_glEvalCoord1dv(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord1dv(This,u) ) 

#define _GLScript_Context_glEvalCoord1f(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord1f(This,u) ) 

#define _GLScript_Context_glEvalCoord1fv(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord1fv(This,u) ) 

#define _GLScript_Context_glEvalCoord2d(This,u,v)	\
    ( (This)->lpVtbl -> glEvalCoord2d(This,u,v) ) 

#define _GLScript_Context_glEvalCoord2dv(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord2dv(This,u) ) 

#define _GLScript_Context_glEvalCoord2f(This,u,v)	\
    ( (This)->lpVtbl -> glEvalCoord2f(This,u,v) ) 

#define _GLScript_Context_glEvalCoord2fv(This,u)	\
    ( (This)->lpVtbl -> glEvalCoord2fv(This,u) ) 

#define _GLScript_Context_glEvalMesh1(This,mode,i1,i2)	\
    ( (This)->lpVtbl -> glEvalMesh1(This,mode,i1,i2) ) 

#define _GLScript_Context_glEvalMesh2(This,mode,i1,i2,j1,j2)	\
    ( (This)->lpVtbl -> glEvalMesh2(This,mode,i1,i2,j1,j2) ) 

#define _GLScript_Context_glEvalPoint1(This,i)	\
    ( (This)->lpVtbl -> glEvalPoint1(This,i) ) 

#define _GLScript_Context_glEvalPoint2(This,i,j)	\
    ( (This)->lpVtbl -> glEvalPoint2(This,i,j) ) 

#define _GLScript_Context_glFeedbackBuffer(This,size,type,buffer)	\
    ( (This)->lpVtbl -> glFeedbackBuffer(This,size,type,buffer) ) 

#define _GLScript_Context_glFinish(This)	\
    ( (This)->lpVtbl -> glFinish(This) ) 

#define _GLScript_Context_glFlush(This)	\
    ( (This)->lpVtbl -> glFlush(This) ) 

#define _GLScript_Context_glFogf(This,pname,param)	\
    ( (This)->lpVtbl -> glFogf(This,pname,param) ) 

#define _GLScript_Context_glFogfv(This,pname,params)	\
    ( (This)->lpVtbl -> glFogfv(This,pname,params) ) 

#define _GLScript_Context_glFogi(This,pname,param)	\
    ( (This)->lpVtbl -> glFogi(This,pname,param) ) 

#define _GLScript_Context_glFogiv(This,pname,params)	\
    ( (This)->lpVtbl -> glFogiv(This,pname,params) ) 

#define _GLScript_Context_glFrontFace(This,mode)	\
    ( (This)->lpVtbl -> glFrontFace(This,mode) ) 

#define _GLScript_Context_glFrustum(This,left,right,bottom,top,zNear,zFar)	\
    ( (This)->lpVtbl -> glFrustum(This,left,right,bottom,top,zNear,zFar) ) 

#define _GLScript_Context_glGenLists(This,range,pRetVal)	\
    ( (This)->lpVtbl -> glGenLists(This,range,pRetVal) ) 

#define _GLScript_Context_glGenTextures(This,n,textures)	\
    ( (This)->lpVtbl -> glGenTextures(This,n,textures) ) 

#define _GLScript_Context_glGetBooleanv(This,pname,params)	\
    ( (This)->lpVtbl -> glGetBooleanv(This,pname,params) ) 

#define _GLScript_Context_glGetClipPlane(This,plane,equation)	\
    ( (This)->lpVtbl -> glGetClipPlane(This,plane,equation) ) 

#define _GLScript_Context_glGetDoublev(This,pname,params)	\
    ( (This)->lpVtbl -> glGetDoublev(This,pname,params) ) 

#define _GLScript_Context_glGetError(This,pRetVal)	\
    ( (This)->lpVtbl -> glGetError(This,pRetVal) ) 

#define _GLScript_Context_glGetFloatv(This,pname,params)	\
    ( (This)->lpVtbl -> glGetFloatv(This,pname,params) ) 

#define _GLScript_Context_glGetIntegerv(This,pname,params)	\
    ( (This)->lpVtbl -> glGetIntegerv(This,pname,params) ) 

#define _GLScript_Context_glGetLightfv(This,light,pname,params)	\
    ( (This)->lpVtbl -> glGetLightfv(This,light,pname,params) ) 

#define _GLScript_Context_glGetLightiv(This,light,pname,params)	\
    ( (This)->lpVtbl -> glGetLightiv(This,light,pname,params) ) 

#define _GLScript_Context_glGetMapdv(This,target,query,v)	\
    ( (This)->lpVtbl -> glGetMapdv(This,target,query,v) ) 

#define _GLScript_Context_glGetMapfv(This,target,query,v)	\
    ( (This)->lpVtbl -> glGetMapfv(This,target,query,v) ) 

#define _GLScript_Context_glGetMapiv(This,target,query,v)	\
    ( (This)->lpVtbl -> glGetMapiv(This,target,query,v) ) 

#define _GLScript_Context_glGetMaterialfv(This,face,pname,params)	\
    ( (This)->lpVtbl -> glGetMaterialfv(This,face,pname,params) ) 

#define _GLScript_Context_glGetMaterialiv(This,face,pname,params)	\
    ( (This)->lpVtbl -> glGetMaterialiv(This,face,pname,params) ) 

#define _GLScript_Context_glGetPixelMapfv(This,map,values)	\
    ( (This)->lpVtbl -> glGetPixelMapfv(This,map,values) ) 

#define _GLScript_Context_glGetPixelMapuiv(This,map,values)	\
    ( (This)->lpVtbl -> glGetPixelMapuiv(This,map,values) ) 

#define _GLScript_Context_glGetPixelMapusv(This,map,values)	\
    ( (This)->lpVtbl -> glGetPixelMapusv(This,map,values) ) 

#define _GLScript_Context_glGetPointerv(This,pname,params)	\
    ( (This)->lpVtbl -> glGetPointerv(This,pname,params) ) 

#define _GLScript_Context_glGetPolygonStipple(This,mask)	\
    ( (This)->lpVtbl -> glGetPolygonStipple(This,mask) ) 

#define _GLScript_Context_glGetString(This,name,pRetVal)	\
    ( (This)->lpVtbl -> glGetString(This,name,pRetVal) ) 

#define _GLScript_Context_glGetTexEnvfv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glGetTexEnvfv(This,target,pname,params) ) 

#define _GLScript_Context_glGetTexEnviv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glGetTexEnviv(This,target,pname,params) ) 

#define _GLScript_Context_glGetTexGendv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glGetTexGendv(This,coord,pname,params) ) 

#define _GLScript_Context_glGetTexGenfv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glGetTexGenfv(This,coord,pname,params) ) 

#define _GLScript_Context_glGetTexGeniv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glGetTexGeniv(This,coord,pname,params) ) 

#define _GLScript_Context_glGetTexImage(This,target,level,format,type,pixels)	\
    ( (This)->lpVtbl -> glGetTexImage(This,target,level,format,type,pixels) ) 

#define _GLScript_Context_glGetTexLevelParameterfv(This,target,level,pname,params)	\
    ( (This)->lpVtbl -> glGetTexLevelParameterfv(This,target,level,pname,params) ) 

#define _GLScript_Context_glGetTexLevelParameteriv(This,target,level,pname,params)	\
    ( (This)->lpVtbl -> glGetTexLevelParameteriv(This,target,level,pname,params) ) 

#define _GLScript_Context_glGetTexParameterfv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glGetTexParameterfv(This,target,pname,params) ) 

#define _GLScript_Context_glGetTexParameteriv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glGetTexParameteriv(This,target,pname,params) ) 

#define _GLScript_Context_glHint(This,target,mode)	\
    ( (This)->lpVtbl -> glHint(This,target,mode) ) 

#define _GLScript_Context_glIndexMask(This,mask)	\
    ( (This)->lpVtbl -> glIndexMask(This,mask) ) 

#define _GLScript_Context_glIndexPointer(This,type,stride,pointer)	\
    ( (This)->lpVtbl -> glIndexPointer(This,type,stride,pointer) ) 

#define _GLScript_Context_glIndexd(This,c)	\
    ( (This)->lpVtbl -> glIndexd(This,c) ) 

#define _GLScript_Context_glIndexdv(This,c)	\
    ( (This)->lpVtbl -> glIndexdv(This,c) ) 

#define _GLScript_Context_glIndexf(This,c)	\
    ( (This)->lpVtbl -> glIndexf(This,c) ) 

#define _GLScript_Context_glIndexfv(This,c)	\
    ( (This)->lpVtbl -> glIndexfv(This,c) ) 

#define _GLScript_Context_glIndexi(This,c)	\
    ( (This)->lpVtbl -> glIndexi(This,c) ) 

#define _GLScript_Context_glIndexiv(This,c)	\
    ( (This)->lpVtbl -> glIndexiv(This,c) ) 

#define _GLScript_Context_glIndexs(This,c)	\
    ( (This)->lpVtbl -> glIndexs(This,c) ) 

#define _GLScript_Context_glIndexsv(This,c)	\
    ( (This)->lpVtbl -> glIndexsv(This,c) ) 

#define _GLScript_Context_glIndexub(This,c)	\
    ( (This)->lpVtbl -> glIndexub(This,c) ) 

#define _GLScript_Context_glIndexubv(This,c)	\
    ( (This)->lpVtbl -> glIndexubv(This,c) ) 

#define _GLScript_Context_glInitNames(This)	\
    ( (This)->lpVtbl -> glInitNames(This) ) 

#define _GLScript_Context_glInterleavedArrays(This,format,stride,pointer)	\
    ( (This)->lpVtbl -> glInterleavedArrays(This,format,stride,pointer) ) 

#define _GLScript_Context_glIsEnabled(This,cap,pRetVal)	\
    ( (This)->lpVtbl -> glIsEnabled(This,cap,pRetVal) ) 

#define _GLScript_Context_glIsList(This,list,pRetVal)	\
    ( (This)->lpVtbl -> glIsList(This,list,pRetVal) ) 

#define _GLScript_Context_glIsTexture(This,texture,pRetVal)	\
    ( (This)->lpVtbl -> glIsTexture(This,texture,pRetVal) ) 

#define _GLScript_Context_glLightModelf(This,pname,param)	\
    ( (This)->lpVtbl -> glLightModelf(This,pname,param) ) 

#define _GLScript_Context_glLightModelfv(This,pname,params)	\
    ( (This)->lpVtbl -> glLightModelfv(This,pname,params) ) 

#define _GLScript_Context_glLightModeli(This,pname,param)	\
    ( (This)->lpVtbl -> glLightModeli(This,pname,param) ) 

#define _GLScript_Context_glLightModeliv(This,pname,params)	\
    ( (This)->lpVtbl -> glLightModeliv(This,pname,params) ) 

#define _GLScript_Context_glLightf(This,light,pname,param)	\
    ( (This)->lpVtbl -> glLightf(This,light,pname,param) ) 

#define _GLScript_Context_glLightfv(This,light,pname,params)	\
    ( (This)->lpVtbl -> glLightfv(This,light,pname,params) ) 

#define _GLScript_Context_glLighti(This,light,pname,param)	\
    ( (This)->lpVtbl -> glLighti(This,light,pname,param) ) 

#define _GLScript_Context_glLightiv(This,light,pname,params)	\
    ( (This)->lpVtbl -> glLightiv(This,light,pname,params) ) 

#define _GLScript_Context_glLineStipple(This,factor,pattern)	\
    ( (This)->lpVtbl -> glLineStipple(This,factor,pattern) ) 

#define _GLScript_Context_glLineWidth(This,width)	\
    ( (This)->lpVtbl -> glLineWidth(This,width) ) 

#define _GLScript_Context_glListBase(This,base)	\
    ( (This)->lpVtbl -> glListBase(This,base) ) 

#define _GLScript_Context_glLoadIdentity(This)	\
    ( (This)->lpVtbl -> glLoadIdentity(This) ) 

#define _GLScript_Context_glLoadMatrixd(This,m)	\
    ( (This)->lpVtbl -> glLoadMatrixd(This,m) ) 

#define _GLScript_Context_glLoadMatrixf(This,m)	\
    ( (This)->lpVtbl -> glLoadMatrixf(This,m) ) 

#define _GLScript_Context_glLoadName(This,name)	\
    ( (This)->lpVtbl -> glLoadName(This,name) ) 

#define _GLScript_Context_glLogicOp(This,opcode)	\
    ( (This)->lpVtbl -> glLogicOp(This,opcode) ) 

#define _GLScript_Context_glMap1d(This,target,u1,u2,stride,order,points)	\
    ( (This)->lpVtbl -> glMap1d(This,target,u1,u2,stride,order,points) ) 

#define _GLScript_Context_glMap1f(This,target,u1,u2,stride,order,points)	\
    ( (This)->lpVtbl -> glMap1f(This,target,u1,u2,stride,order,points) ) 

#define _GLScript_Context_glMap2d(This,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points)	\
    ( (This)->lpVtbl -> glMap2d(This,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points) ) 

#define _GLScript_Context_glMap2f(This,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points)	\
    ( (This)->lpVtbl -> glMap2f(This,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points) ) 

#define _GLScript_Context_glMapGrid1d(This,un,u1,u2)	\
    ( (This)->lpVtbl -> glMapGrid1d(This,un,u1,u2) ) 

#define _GLScript_Context_glMapGrid1f(This,un,u1,u2)	\
    ( (This)->lpVtbl -> glMapGrid1f(This,un,u1,u2) ) 

#define _GLScript_Context_glMapGrid2d(This,un,u1,u2,vn,v1,v2)	\
    ( (This)->lpVtbl -> glMapGrid2d(This,un,u1,u2,vn,v1,v2) ) 

#define _GLScript_Context_glMapGrid2f(This,un,u1,u2,vn,v1,v2)	\
    ( (This)->lpVtbl -> glMapGrid2f(This,un,u1,u2,vn,v1,v2) ) 

#define _GLScript_Context_glMaterialf(This,face,pname,param)	\
    ( (This)->lpVtbl -> glMaterialf(This,face,pname,param) ) 

#define _GLScript_Context_glMaterialfv(This,face,pname,params)	\
    ( (This)->lpVtbl -> glMaterialfv(This,face,pname,params) ) 

#define _GLScript_Context_glMateriali(This,face,pname,param)	\
    ( (This)->lpVtbl -> glMateriali(This,face,pname,param) ) 

#define _GLScript_Context_glMaterialiv(This,face,pname,params)	\
    ( (This)->lpVtbl -> glMaterialiv(This,face,pname,params) ) 

#define _GLScript_Context_glMatrixMode(This,mode)	\
    ( (This)->lpVtbl -> glMatrixMode(This,mode) ) 

#define _GLScript_Context_glMultMatrixd(This,m)	\
    ( (This)->lpVtbl -> glMultMatrixd(This,m) ) 

#define _GLScript_Context_glMultMatrixf(This,m)	\
    ( (This)->lpVtbl -> glMultMatrixf(This,m) ) 

#define _GLScript_Context_glNewList(This,list,mode)	\
    ( (This)->lpVtbl -> glNewList(This,list,mode) ) 

#define _GLScript_Context_glNormal3b(This,nx,ny,nz)	\
    ( (This)->lpVtbl -> glNormal3b(This,nx,ny,nz) ) 

#define _GLScript_Context_glNormal3bv(This,v)	\
    ( (This)->lpVtbl -> glNormal3bv(This,v) ) 

#define _GLScript_Context_glNormal3d(This,nx,ny,nz)	\
    ( (This)->lpVtbl -> glNormal3d(This,nx,ny,nz) ) 

#define _GLScript_Context_glNormal3dv(This,v)	\
    ( (This)->lpVtbl -> glNormal3dv(This,v) ) 

#define _GLScript_Context_glNormal3f(This,nx,ny,nz)	\
    ( (This)->lpVtbl -> glNormal3f(This,nx,ny,nz) ) 

#define _GLScript_Context_glNormal3fv(This,v)	\
    ( (This)->lpVtbl -> glNormal3fv(This,v) ) 

#define _GLScript_Context_glNormal3i(This,nx,ny,nz)	\
    ( (This)->lpVtbl -> glNormal3i(This,nx,ny,nz) ) 

#define _GLScript_Context_glNormal3iv(This,v)	\
    ( (This)->lpVtbl -> glNormal3iv(This,v) ) 

#define _GLScript_Context_glNormal3s(This,nx,ny,nz)	\
    ( (This)->lpVtbl -> glNormal3s(This,nx,ny,nz) ) 

#define _GLScript_Context_glNormal3sv(This,v)	\
    ( (This)->lpVtbl -> glNormal3sv(This,v) ) 

#define _GLScript_Context_glNormalPointer(This,type,stride,pointer)	\
    ( (This)->lpVtbl -> glNormalPointer(This,type,stride,pointer) ) 

#define _GLScript_Context_glOrtho(This,left,right,bottom,top,zNear,zFar)	\
    ( (This)->lpVtbl -> glOrtho(This,left,right,bottom,top,zNear,zFar) ) 

#define _GLScript_Context_glPassThrough(This,token)	\
    ( (This)->lpVtbl -> glPassThrough(This,token) ) 

#define _GLScript_Context_glPixelMapfv(This,map,mapsize,values)	\
    ( (This)->lpVtbl -> glPixelMapfv(This,map,mapsize,values) ) 

#define _GLScript_Context_glPixelMapuiv(This,map,mapsize,values)	\
    ( (This)->lpVtbl -> glPixelMapuiv(This,map,mapsize,values) ) 

#define _GLScript_Context_glPixelMapusv(This,map,mapsize,values)	\
    ( (This)->lpVtbl -> glPixelMapusv(This,map,mapsize,values) ) 

#define _GLScript_Context_glPixelStoref(This,pname,param)	\
    ( (This)->lpVtbl -> glPixelStoref(This,pname,param) ) 

#define _GLScript_Context_glPixelStorei(This,pname,param)	\
    ( (This)->lpVtbl -> glPixelStorei(This,pname,param) ) 

#define _GLScript_Context_glPixelTransferf(This,pname,param)	\
    ( (This)->lpVtbl -> glPixelTransferf(This,pname,param) ) 

#define _GLScript_Context_glPixelTransferi(This,pname,param)	\
    ( (This)->lpVtbl -> glPixelTransferi(This,pname,param) ) 

#define _GLScript_Context_glPixelZoom(This,xfactor,yfactor)	\
    ( (This)->lpVtbl -> glPixelZoom(This,xfactor,yfactor) ) 

#define _GLScript_Context_glPointSize(This,size)	\
    ( (This)->lpVtbl -> glPointSize(This,size) ) 

#define _GLScript_Context_glPolygonMode(This,face,mode)	\
    ( (This)->lpVtbl -> glPolygonMode(This,face,mode) ) 

#define _GLScript_Context_glPolygonOffset(This,factor,units)	\
    ( (This)->lpVtbl -> glPolygonOffset(This,factor,units) ) 

#define _GLScript_Context_glPolygonStipple(This,mask)	\
    ( (This)->lpVtbl -> glPolygonStipple(This,mask) ) 

#define _GLScript_Context_glPopAttrib(This)	\
    ( (This)->lpVtbl -> glPopAttrib(This) ) 

#define _GLScript_Context_glPopClientAttrib(This)	\
    ( (This)->lpVtbl -> glPopClientAttrib(This) ) 

#define _GLScript_Context_glPopMatrix(This)	\
    ( (This)->lpVtbl -> glPopMatrix(This) ) 

#define _GLScript_Context_glPopName(This)	\
    ( (This)->lpVtbl -> glPopName(This) ) 

#define _GLScript_Context_glPrioritizeTextures(This,n,textures,priorities)	\
    ( (This)->lpVtbl -> glPrioritizeTextures(This,n,textures,priorities) ) 

#define _GLScript_Context_glPushAttrib(This,mask)	\
    ( (This)->lpVtbl -> glPushAttrib(This,mask) ) 

#define _GLScript_Context_glPushClientAttrib(This,mask)	\
    ( (This)->lpVtbl -> glPushClientAttrib(This,mask) ) 

#define _GLScript_Context_glPushMatrix(This)	\
    ( (This)->lpVtbl -> glPushMatrix(This) ) 

#define _GLScript_Context_glPushName(This,name)	\
    ( (This)->lpVtbl -> glPushName(This,name) ) 

#define _GLScript_Context_glRasterPos2d(This,x,y)	\
    ( (This)->lpVtbl -> glRasterPos2d(This,x,y) ) 

#define _GLScript_Context_glRasterPos2dv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos2dv(This,v) ) 

#define _GLScript_Context_glRasterPos2f(This,x,y)	\
    ( (This)->lpVtbl -> glRasterPos2f(This,x,y) ) 

#define _GLScript_Context_glRasterPos2fv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos2fv(This,v) ) 

#define _GLScript_Context_glRasterPos2i(This,x,y)	\
    ( (This)->lpVtbl -> glRasterPos2i(This,x,y) ) 

#define _GLScript_Context_glRasterPos2iv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos2iv(This,v) ) 

#define _GLScript_Context_glRasterPos2s(This,x,y)	\
    ( (This)->lpVtbl -> glRasterPos2s(This,x,y) ) 

#define _GLScript_Context_glRasterPos2sv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos2sv(This,v) ) 

#define _GLScript_Context_glRasterPos3d(This,x,y,z)	\
    ( (This)->lpVtbl -> glRasterPos3d(This,x,y,z) ) 

#define _GLScript_Context_glRasterPos3dv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos3dv(This,v) ) 

#define _GLScript_Context_glRasterPos3f(This,x,y,z)	\
    ( (This)->lpVtbl -> glRasterPos3f(This,x,y,z) ) 

#define _GLScript_Context_glRasterPos3fv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos3fv(This,v) ) 

#define _GLScript_Context_glRasterPos3i(This,x,y,z)	\
    ( (This)->lpVtbl -> glRasterPos3i(This,x,y,z) ) 

#define _GLScript_Context_glRasterPos3iv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos3iv(This,v) ) 

#define _GLScript_Context_glRasterPos3s(This,x,y,z)	\
    ( (This)->lpVtbl -> glRasterPos3s(This,x,y,z) ) 

#define _GLScript_Context_glRasterPos3sv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos3sv(This,v) ) 

#define _GLScript_Context_glRasterPos4d(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glRasterPos4d(This,x,y,z,w) ) 

#define _GLScript_Context_glRasterPos4dv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos4dv(This,v) ) 

#define _GLScript_Context_glRasterPos4f(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glRasterPos4f(This,x,y,z,w) ) 

#define _GLScript_Context_glRasterPos4fv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos4fv(This,v) ) 

#define _GLScript_Context_glRasterPos4i(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glRasterPos4i(This,x,y,z,w) ) 

#define _GLScript_Context_glRasterPos4iv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos4iv(This,v) ) 

#define _GLScript_Context_glRasterPos4s(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glRasterPos4s(This,x,y,z,w) ) 

#define _GLScript_Context_glRasterPos4sv(This,v)	\
    ( (This)->lpVtbl -> glRasterPos4sv(This,v) ) 

#define _GLScript_Context_glReadBuffer(This,mode)	\
    ( (This)->lpVtbl -> glReadBuffer(This,mode) ) 

#define _GLScript_Context_glReadPixels(This,x,y,width,height,format,type,pixels)	\
    ( (This)->lpVtbl -> glReadPixels(This,x,y,width,height,format,type,pixels) ) 

#define _GLScript_Context_glRectd(This,x1,y1,x2,y2)	\
    ( (This)->lpVtbl -> glRectd(This,x1,y1,x2,y2) ) 

#define _GLScript_Context_glRectdv(This,v1,v2)	\
    ( (This)->lpVtbl -> glRectdv(This,v1,v2) ) 

#define _GLScript_Context_glRectf(This,x1,y1,x2,y2)	\
    ( (This)->lpVtbl -> glRectf(This,x1,y1,x2,y2) ) 

#define _GLScript_Context_glRectfv(This,v1,v2)	\
    ( (This)->lpVtbl -> glRectfv(This,v1,v2) ) 

#define _GLScript_Context_glRecti(This,x1,y1,x2,y2)	\
    ( (This)->lpVtbl -> glRecti(This,x1,y1,x2,y2) ) 

#define _GLScript_Context_glRectiv(This,v1,v2)	\
    ( (This)->lpVtbl -> glRectiv(This,v1,v2) ) 

#define _GLScript_Context_glRects(This,x1,y1,x2,y2)	\
    ( (This)->lpVtbl -> glRects(This,x1,y1,x2,y2) ) 

#define _GLScript_Context_glRectsv(This,v1,v2)	\
    ( (This)->lpVtbl -> glRectsv(This,v1,v2) ) 

#define _GLScript_Context_glRenderMode(This,mode,pRetVal)	\
    ( (This)->lpVtbl -> glRenderMode(This,mode,pRetVal) ) 

#define _GLScript_Context_glRotated(This,angle,x,y,z)	\
    ( (This)->lpVtbl -> glRotated(This,angle,x,y,z) ) 

#define _GLScript_Context_glRotatef(This,angle,x,y,z)	\
    ( (This)->lpVtbl -> glRotatef(This,angle,x,y,z) ) 

#define _GLScript_Context_glScaled(This,x,y,z)	\
    ( (This)->lpVtbl -> glScaled(This,x,y,z) ) 

#define _GLScript_Context_glScalef(This,x,y,z)	\
    ( (This)->lpVtbl -> glScalef(This,x,y,z) ) 

#define _GLScript_Context_glScissor(This,x,y,width,height)	\
    ( (This)->lpVtbl -> glScissor(This,x,y,width,height) ) 

#define _GLScript_Context_glSelectBuffer(This,size,buffer)	\
    ( (This)->lpVtbl -> glSelectBuffer(This,size,buffer) ) 

#define _GLScript_Context_glShadeModel(This,mode)	\
    ( (This)->lpVtbl -> glShadeModel(This,mode) ) 

#define _GLScript_Context_glStencilFunc(This,func,ref,mask)	\
    ( (This)->lpVtbl -> glStencilFunc(This,func,ref,mask) ) 

#define _GLScript_Context_glStencilMask(This,mask)	\
    ( (This)->lpVtbl -> glStencilMask(This,mask) ) 

#define _GLScript_Context_glStencilOp(This,fail,zfail,zpass)	\
    ( (This)->lpVtbl -> glStencilOp(This,fail,zfail,zpass) ) 

#define _GLScript_Context_glTexCoord1d(This,s)	\
    ( (This)->lpVtbl -> glTexCoord1d(This,s) ) 

#define _GLScript_Context_glTexCoord1dv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord1dv(This,v) ) 

#define _GLScript_Context_glTexCoord1f(This,s)	\
    ( (This)->lpVtbl -> glTexCoord1f(This,s) ) 

#define _GLScript_Context_glTexCoord1fv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord1fv(This,v) ) 

#define _GLScript_Context_glTexCoord1i(This,s)	\
    ( (This)->lpVtbl -> glTexCoord1i(This,s) ) 

#define _GLScript_Context_glTexCoord1iv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord1iv(This,v) ) 

#define _GLScript_Context_glTexCoord1s(This,s)	\
    ( (This)->lpVtbl -> glTexCoord1s(This,s) ) 

#define _GLScript_Context_glTexCoord1sv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord1sv(This,v) ) 

#define _GLScript_Context_glTexCoord2d(This,s,t)	\
    ( (This)->lpVtbl -> glTexCoord2d(This,s,t) ) 

#define _GLScript_Context_glTexCoord2dv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord2dv(This,v) ) 

#define _GLScript_Context_glTexCoord2f(This,s,t)	\
    ( (This)->lpVtbl -> glTexCoord2f(This,s,t) ) 

#define _GLScript_Context_glTexCoord2fv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord2fv(This,v) ) 

#define _GLScript_Context_glTexCoord2i(This,s,t)	\
    ( (This)->lpVtbl -> glTexCoord2i(This,s,t) ) 

#define _GLScript_Context_glTexCoord2iv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord2iv(This,v) ) 

#define _GLScript_Context_glTexCoord2s(This,s,t)	\
    ( (This)->lpVtbl -> glTexCoord2s(This,s,t) ) 

#define _GLScript_Context_glTexCoord2sv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord2sv(This,v) ) 

#define _GLScript_Context_glTexCoord3d(This,s,t,r)	\
    ( (This)->lpVtbl -> glTexCoord3d(This,s,t,r) ) 

#define _GLScript_Context_glTexCoord3dv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord3dv(This,v) ) 

#define _GLScript_Context_glTexCoord3f(This,s,t,r)	\
    ( (This)->lpVtbl -> glTexCoord3f(This,s,t,r) ) 

#define _GLScript_Context_glTexCoord3fv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord3fv(This,v) ) 

#define _GLScript_Context_glTexCoord3i(This,s,t,r)	\
    ( (This)->lpVtbl -> glTexCoord3i(This,s,t,r) ) 

#define _GLScript_Context_glTexCoord3iv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord3iv(This,v) ) 

#define _GLScript_Context_glTexCoord3s(This,s,t,r)	\
    ( (This)->lpVtbl -> glTexCoord3s(This,s,t,r) ) 

#define _GLScript_Context_glTexCoord3sv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord3sv(This,v) ) 

#define _GLScript_Context_glTexCoord4d(This,s,t,r,q)	\
    ( (This)->lpVtbl -> glTexCoord4d(This,s,t,r,q) ) 

#define _GLScript_Context_glTexCoord4dv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord4dv(This,v) ) 

#define _GLScript_Context_glTexCoord4f(This,s,t,r,q)	\
    ( (This)->lpVtbl -> glTexCoord4f(This,s,t,r,q) ) 

#define _GLScript_Context_glTexCoord4fv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord4fv(This,v) ) 

#define _GLScript_Context_glTexCoord4i(This,s,t,r,q)	\
    ( (This)->lpVtbl -> glTexCoord4i(This,s,t,r,q) ) 

#define _GLScript_Context_glTexCoord4iv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord4iv(This,v) ) 

#define _GLScript_Context_glTexCoord4s(This,s,t,r,q)	\
    ( (This)->lpVtbl -> glTexCoord4s(This,s,t,r,q) ) 

#define _GLScript_Context_glTexCoord4sv(This,v)	\
    ( (This)->lpVtbl -> glTexCoord4sv(This,v) ) 

#define _GLScript_Context_glTexCoordPointer(This,size,type,stride,pointer)	\
    ( (This)->lpVtbl -> glTexCoordPointer(This,size,type,stride,pointer) ) 

#define _GLScript_Context_glTexEnvf(This,target,pname,param)	\
    ( (This)->lpVtbl -> glTexEnvf(This,target,pname,param) ) 

#define _GLScript_Context_glTexEnvfv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glTexEnvfv(This,target,pname,params) ) 

#define _GLScript_Context_glTexEnvi(This,target,pname,param)	\
    ( (This)->lpVtbl -> glTexEnvi(This,target,pname,param) ) 

#define _GLScript_Context_glTexEnviv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glTexEnviv(This,target,pname,params) ) 

#define _GLScript_Context_glTexGend(This,coord,pname,param)	\
    ( (This)->lpVtbl -> glTexGend(This,coord,pname,param) ) 

#define _GLScript_Context_glTexGendv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glTexGendv(This,coord,pname,params) ) 

#define _GLScript_Context_glTexGenf(This,coord,pname,param)	\
    ( (This)->lpVtbl -> glTexGenf(This,coord,pname,param) ) 

#define _GLScript_Context_glTexGenfv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glTexGenfv(This,coord,pname,params) ) 

#define _GLScript_Context_glTexGeni(This,coord,pname,param)	\
    ( (This)->lpVtbl -> glTexGeni(This,coord,pname,param) ) 

#define _GLScript_Context_glTexGeniv(This,coord,pname,params)	\
    ( (This)->lpVtbl -> glTexGeniv(This,coord,pname,params) ) 

#define _GLScript_Context_glTexImage1D(This,target,level,internalformat,width,border,format,type,pixels)	\
    ( (This)->lpVtbl -> glTexImage1D(This,target,level,internalformat,width,border,format,type,pixels) ) 

#define _GLScript_Context_glTexImage2D(This,target,level,internalformat,width,height,border,format,type,pixels)	\
    ( (This)->lpVtbl -> glTexImage2D(This,target,level,internalformat,width,height,border,format,type,pixels) ) 

#define _GLScript_Context_glTexParameterf(This,target,pname,param)	\
    ( (This)->lpVtbl -> glTexParameterf(This,target,pname,param) ) 

#define _GLScript_Context_glTexParameterfv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glTexParameterfv(This,target,pname,params) ) 

#define _GLScript_Context_glTexParameteri(This,target,pname,param)	\
    ( (This)->lpVtbl -> glTexParameteri(This,target,pname,param) ) 

#define _GLScript_Context_glTexParameteriv(This,target,pname,params)	\
    ( (This)->lpVtbl -> glTexParameteriv(This,target,pname,params) ) 

#define _GLScript_Context_glTexSubImage1D(This,target,level,xoffset,width,format,type,pixels)	\
    ( (This)->lpVtbl -> glTexSubImage1D(This,target,level,xoffset,width,format,type,pixels) ) 

#define _GLScript_Context_glTexSubImage2D(This,target,level,xoffset,yoffset,width,height,format,type,pixels)	\
    ( (This)->lpVtbl -> glTexSubImage2D(This,target,level,xoffset,yoffset,width,height,format,type,pixels) ) 

#define _GLScript_Context_glTranslated(This,x,y,z)	\
    ( (This)->lpVtbl -> glTranslated(This,x,y,z) ) 

#define _GLScript_Context_glTranslatef(This,x,y,z)	\
    ( (This)->lpVtbl -> glTranslatef(This,x,y,z) ) 

#define _GLScript_Context_glVertex2d(This,x,y)	\
    ( (This)->lpVtbl -> glVertex2d(This,x,y) ) 

#define _GLScript_Context_glVertex2dv(This,v)	\
    ( (This)->lpVtbl -> glVertex2dv(This,v) ) 

#define _GLScript_Context_glVertex2f(This,x,y)	\
    ( (This)->lpVtbl -> glVertex2f(This,x,y) ) 

#define _GLScript_Context_glVertex2fv(This,v)	\
    ( (This)->lpVtbl -> glVertex2fv(This,v) ) 

#define _GLScript_Context_glVertex2i(This,x,y)	\
    ( (This)->lpVtbl -> glVertex2i(This,x,y) ) 

#define _GLScript_Context_glVertex2iv(This,v)	\
    ( (This)->lpVtbl -> glVertex2iv(This,v) ) 

#define _GLScript_Context_glVertex2s(This,x,y)	\
    ( (This)->lpVtbl -> glVertex2s(This,x,y) ) 

#define _GLScript_Context_glVertex2sv(This,v)	\
    ( (This)->lpVtbl -> glVertex2sv(This,v) ) 

#define _GLScript_Context_glVertex3d(This,x,y,z)	\
    ( (This)->lpVtbl -> glVertex3d(This,x,y,z) ) 

#define _GLScript_Context_glVertex3dv(This,v)	\
    ( (This)->lpVtbl -> glVertex3dv(This,v) ) 

#define _GLScript_Context_glVertex3f(This,x,y,z)	\
    ( (This)->lpVtbl -> glVertex3f(This,x,y,z) ) 

#define _GLScript_Context_glVertex3fv(This,v)	\
    ( (This)->lpVtbl -> glVertex3fv(This,v) ) 

#define _GLScript_Context_glVertex3i(This,x,y,z)	\
    ( (This)->lpVtbl -> glVertex3i(This,x,y,z) ) 

#define _GLScript_Context_glVertex3iv(This,v)	\
    ( (This)->lpVtbl -> glVertex3iv(This,v) ) 

#define _GLScript_Context_glVertex3s(This,x,y,z)	\
    ( (This)->lpVtbl -> glVertex3s(This,x,y,z) ) 

#define _GLScript_Context_glVertex3sv(This,v)	\
    ( (This)->lpVtbl -> glVertex3sv(This,v) ) 

#define _GLScript_Context_glVertex4d(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glVertex4d(This,x,y,z,w) ) 

#define _GLScript_Context_glVertex4dv(This,v)	\
    ( (This)->lpVtbl -> glVertex4dv(This,v) ) 

#define _GLScript_Context_glVertex4f(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glVertex4f(This,x,y,z,w) ) 

#define _GLScript_Context_glVertex4fv(This,v)	\
    ( (This)->lpVtbl -> glVertex4fv(This,v) ) 

#define _GLScript_Context_glVertex4i(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glVertex4i(This,x,y,z,w) ) 

#define _GLScript_Context_glVertex4iv(This,v)	\
    ( (This)->lpVtbl -> glVertex4iv(This,v) ) 

#define _GLScript_Context_glVertex4s(This,x,y,z,w)	\
    ( (This)->lpVtbl -> glVertex4s(This,x,y,z,w) ) 

#define _GLScript_Context_glVertex4sv(This,v)	\
    ( (This)->lpVtbl -> glVertex4sv(This,v) ) 

#define _GLScript_Context_glVertexPointer(This,size,type,stride,pointer)	\
    ( (This)->lpVtbl -> glVertexPointer(This,size,type,stride,pointer) ) 

#define _GLScript_Context_glViewport(This,x,y,width,height)	\
    ( (This)->lpVtbl -> glViewport(This,x,y,width,height) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexGendv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexGendv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexGenfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexGenfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexGeniv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexGeniv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexImage_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glGetTexImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexLevelParameterfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexLevelParameterfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexLevelParameteriv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexLevelParameteriv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexParameterfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexParameterfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glGetTexParameteriv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glGetTexParameteriv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glHint_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glHint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexMask_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mask);


void __RPC_STUB _GLScript_Context_glIndexMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexPointer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int type,
    /* [in] */ int stride,
    /* [in] */ _GLScript_Array *pointer);


void __RPC_STUB _GLScript_Context_glIndexPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexd_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double c);


void __RPC_STUB _GLScript_Context_glIndexd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexdv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *c);


void __RPC_STUB _GLScript_Context_glIndexdv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float c);


void __RPC_STUB _GLScript_Context_glIndexf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *c);


void __RPC_STUB _GLScript_Context_glIndexfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexi_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int c);


void __RPC_STUB _GLScript_Context_glIndexi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexiv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *c);


void __RPC_STUB _GLScript_Context_glIndexiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexs_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short c);


void __RPC_STUB _GLScript_Context_glIndexs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexsv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *c);


void __RPC_STUB _GLScript_Context_glIndexsv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexub_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned char c);


void __RPC_STUB _GLScript_Context_glIndexub_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIndexubv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *c);


void __RPC_STUB _GLScript_Context_glIndexubv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glInitNames_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glInitNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glInterleavedArrays_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int format,
    /* [in] */ int stride,
    /* [in] */ _GLScript_Array *pointer);


void __RPC_STUB _GLScript_Context_glInterleavedArrays_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIsEnabled_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int cap,
    /* [retval][out] */ unsigned char *pRetVal);


void __RPC_STUB _GLScript_Context_glIsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIsList_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int list,
    /* [retval][out] */ unsigned char *pRetVal);


void __RPC_STUB _GLScript_Context_glIsList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glIsTexture_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int texture,
    /* [retval][out] */ unsigned char *pRetVal);


void __RPC_STUB _GLScript_Context_glIsTexture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightModelf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glLightModelf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightModelfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glLightModelfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightModeli_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glLightModeli_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightModeliv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glLightModeliv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int light,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glLightf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int light,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glLightfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLighti_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int light,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glLighti_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLightiv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int light,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glLightiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLineStipple_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int factor,
    /* [in] */ unsigned short pattern);


void __RPC_STUB _GLScript_Context_glLineStipple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLineWidth_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float width);


void __RPC_STUB _GLScript_Context_glLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glListBase_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int base);


void __RPC_STUB _GLScript_Context_glListBase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLoadIdentity_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glLoadIdentity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLoadMatrixd_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *m);


void __RPC_STUB _GLScript_Context_glLoadMatrixd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLoadMatrixf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *m);


void __RPC_STUB _GLScript_Context_glLoadMatrixf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLoadName_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int name);


void __RPC_STUB _GLScript_Context_glLoadName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glLogicOp_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int opcode);


void __RPC_STUB _GLScript_Context_glLogicOp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMap1d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ double u1,
    /* [in] */ double u2,
    /* [in] */ int stride,
    /* [in] */ int order,
    /* [in] */ _GLScript_Array *points);


void __RPC_STUB _GLScript_Context_glMap1d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMap1f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ float u1,
    /* [in] */ float u2,
    /* [in] */ int stride,
    /* [in] */ int order,
    /* [in] */ _GLScript_Array *points);


void __RPC_STUB _GLScript_Context_glMap1f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMap2d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ double u1,
    /* [in] */ double u2,
    /* [in] */ int ustride,
    /* [in] */ int uorder,
    /* [in] */ double v1,
    /* [in] */ double v2,
    /* [in] */ int vstride,
    /* [in] */ int vorder,
    /* [in] */ _GLScript_Array *points);


void __RPC_STUB _GLScript_Context_glMap2d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMap2f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ float u1,
    /* [in] */ float u2,
    /* [in] */ int ustride,
    /* [in] */ int uorder,
    /* [in] */ float v1,
    /* [in] */ float v2,
    /* [in] */ int vstride,
    /* [in] */ int vorder,
    /* [in] */ _GLScript_Array *points);


void __RPC_STUB _GLScript_Context_glMap2f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMapGrid1d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int un,
    /* [in] */ double u1,
    /* [in] */ double u2);


void __RPC_STUB _GLScript_Context_glMapGrid1d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMapGrid1f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int un,
    /* [in] */ float u1,
    /* [in] */ float u2);


void __RPC_STUB _GLScript_Context_glMapGrid1f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMapGrid2d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int un,
    /* [in] */ double u1,
    /* [in] */ double u2,
    /* [in] */ int vn,
    /* [in] */ double v1,
    /* [in] */ double v2);


void __RPC_STUB _GLScript_Context_glMapGrid2d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMapGrid2f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int un,
    /* [in] */ float u1,
    /* [in] */ float u2,
    /* [in] */ int vn,
    /* [in] */ float v1,
    /* [in] */ float v2);


void __RPC_STUB _GLScript_Context_glMapGrid2f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMaterialf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int face,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glMaterialf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMaterialfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int face,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glMaterialfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMateriali_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int face,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glMateriali_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMaterialiv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int face,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glMaterialiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMatrixMode_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glMatrixMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMultMatrixd_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *m);


void __RPC_STUB _GLScript_Context_glMultMatrixd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glMultMatrixf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *m);


void __RPC_STUB _GLScript_Context_glMultMatrixf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNewList_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int list,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glNewList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3b_Proxy( 
    _GLScript_Context * This,
    /* [in] */ signed char nx,
    /* [in] */ signed char ny,
    /* [in] */ signed char nz);


void __RPC_STUB _GLScript_Context_glNormal3b_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3bv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glNormal3bv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double nx,
    /* [in] */ double ny,
    /* [in] */ double nz);


void __RPC_STUB _GLScript_Context_glNormal3d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glNormal3dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float nx,
    /* [in] */ float ny,
    /* [in] */ float nz);


void __RPC_STUB _GLScript_Context_glNormal3f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glNormal3fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int nx,
    /* [in] */ int ny,
    /* [in] */ int nz);


void __RPC_STUB _GLScript_Context_glNormal3i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glNormal3iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short nx,
    /* [in] */ short ny,
    /* [in] */ short nz);


void __RPC_STUB _GLScript_Context_glNormal3s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormal3sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glNormal3sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glNormalPointer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int type,
    /* [in] */ int stride,
    /* [in] */ _GLScript_Array *pointer);


void __RPC_STUB _GLScript_Context_glNormalPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glOrtho_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double left,
    /* [in] */ double right,
    /* [in] */ double bottom,
    /* [in] */ double top,
    /* [in] */ double zNear,
    /* [in] */ double zFar);


void __RPC_STUB _GLScript_Context_glOrtho_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPassThrough_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float token);


void __RPC_STUB _GLScript_Context_glPassThrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelMapfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int map,
    /* [in] */ int mapsize,
    /* [in] */ _GLScript_Array *values);


void __RPC_STUB _GLScript_Context_glPixelMapfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelMapuiv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int map,
    /* [in] */ int mapsize,
    /* [in] */ _GLScript_Array *values);


void __RPC_STUB _GLScript_Context_glPixelMapuiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelMapusv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int map,
    /* [in] */ int mapsize,
    /* [in] */ _GLScript_Array *values);


void __RPC_STUB _GLScript_Context_glPixelMapusv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelStoref_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glPixelStoref_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelStorei_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glPixelStorei_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelTransferf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glPixelTransferf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelTransferi_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glPixelTransferi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPixelZoom_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float xfactor,
    /* [in] */ float yfactor);


void __RPC_STUB _GLScript_Context_glPixelZoom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPointSize_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float size);


void __RPC_STUB _GLScript_Context_glPointSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPolygonMode_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int face,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glPolygonMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPolygonOffset_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float factor,
    /* [in] */ float units);


void __RPC_STUB _GLScript_Context_glPolygonOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPolygonStipple_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *mask);


void __RPC_STUB _GLScript_Context_glPolygonStipple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPopAttrib_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glPopAttrib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPopClientAttrib_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glPopClientAttrib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPopMatrix_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glPopMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPopName_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glPopName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPrioritizeTextures_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int n,
    /* [in] */ _GLScript_Array *textures,
    /* [in] */ _GLScript_Array *priorities);


void __RPC_STUB _GLScript_Context_glPrioritizeTextures_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPushAttrib_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mask);


void __RPC_STUB _GLScript_Context_glPushAttrib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPushClientAttrib_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mask);


void __RPC_STUB _GLScript_Context_glPushClientAttrib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPushMatrix_Proxy( 
    _GLScript_Context * This);


void __RPC_STUB _GLScript_Context_glPushMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glPushName_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int name);


void __RPC_STUB _GLScript_Context_glPushName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y);


void __RPC_STUB _GLScript_Context_glRasterPos2d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos2dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y);


void __RPC_STUB _GLScript_Context_glRasterPos2f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos2fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y);


void __RPC_STUB _GLScript_Context_glRasterPos2i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos2iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB _GLScript_Context_glRasterPos2s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos2sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos2sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z);


void __RPC_STUB _GLScript_Context_glRasterPos3d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos3dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z);


void __RPC_STUB _GLScript_Context_glRasterPos3f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos3fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int z);


void __RPC_STUB _GLScript_Context_glRasterPos3i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos3iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ short z);


void __RPC_STUB _GLScript_Context_glRasterPos3s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos3sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos3sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z,
    /* [in] */ double w);


void __RPC_STUB _GLScript_Context_glRasterPos4d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos4dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z,
    /* [in] */ float w);


void __RPC_STUB _GLScript_Context_glRasterPos4f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos4fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int z,
    /* [in] */ int w);


void __RPC_STUB _GLScript_Context_glRasterPos4i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos4iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ short z,
    /* [in] */ short w);


void __RPC_STUB _GLScript_Context_glRasterPos4s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRasterPos4sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glRasterPos4sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glReadBuffer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glReadPixels_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int width,
    /* [in] */ int height,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glReadPixels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectd_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x1,
    /* [in] */ double y1,
    /* [in] */ double x2,
    /* [in] */ double y2);


void __RPC_STUB _GLScript_Context_glRectd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectdv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v1,
    /* [in] */ _GLScript_Array *v2);


void __RPC_STUB _GLScript_Context_glRectdv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x1,
    /* [in] */ float y1,
    /* [in] */ float x2,
    /* [in] */ float y2);


void __RPC_STUB _GLScript_Context_glRectf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v1,
    /* [in] */ _GLScript_Array *v2);


void __RPC_STUB _GLScript_Context_glRectfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRecti_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x1,
    /* [in] */ int y1,
    /* [in] */ int x2,
    /* [in] */ int y2);


void __RPC_STUB _GLScript_Context_glRecti_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectiv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v1,
    /* [in] */ _GLScript_Array *v2);


void __RPC_STUB _GLScript_Context_glRectiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRects_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x1,
    /* [in] */ short y1,
    /* [in] */ short x2,
    /* [in] */ short y2);


void __RPC_STUB _GLScript_Context_glRects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRectsv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v1,
    /* [in] */ _GLScript_Array *v2);


void __RPC_STUB _GLScript_Context_glRectsv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRenderMode_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mode,
    /* [retval][out] */ int *pRetVal);


void __RPC_STUB _GLScript_Context_glRenderMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRotated_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double angle,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z);


void __RPC_STUB _GLScript_Context_glRotated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glRotatef_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float angle,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z);


void __RPC_STUB _GLScript_Context_glRotatef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glScaled_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z);


void __RPC_STUB _GLScript_Context_glScaled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glScalef_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z);


void __RPC_STUB _GLScript_Context_glScalef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glScissor_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int width,
    /* [in] */ int height);


void __RPC_STUB _GLScript_Context_glScissor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glSelectBuffer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int size,
    /* [in] */ _GLScript_Array *buffer);


void __RPC_STUB _GLScript_Context_glSelectBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glShadeModel_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mode);


void __RPC_STUB _GLScript_Context_glShadeModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glStencilFunc_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int func,
    /* [in] */ int ref,
    /* [in] */ unsigned int mask);


void __RPC_STUB _GLScript_Context_glStencilFunc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glStencilMask_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int mask);


void __RPC_STUB _GLScript_Context_glStencilMask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glStencilOp_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int fail,
    /* [in] */ unsigned int zfail,
    /* [in] */ unsigned int zpass);


void __RPC_STUB _GLScript_Context_glStencilOp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double s);


void __RPC_STUB _GLScript_Context_glTexCoord1d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord1dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float s);


void __RPC_STUB _GLScript_Context_glTexCoord1f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord1fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int s);


void __RPC_STUB _GLScript_Context_glTexCoord1i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord1iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short s);


void __RPC_STUB _GLScript_Context_glTexCoord1s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord1sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord1sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double s,
    /* [in] */ double t);


void __RPC_STUB _GLScript_Context_glTexCoord2d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord2dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float s,
    /* [in] */ float t);


void __RPC_STUB _GLScript_Context_glTexCoord2f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord2fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int s,
    /* [in] */ int t);


void __RPC_STUB _GLScript_Context_glTexCoord2i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord2iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short s,
    /* [in] */ short t);


void __RPC_STUB _GLScript_Context_glTexCoord2s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord2sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord2sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double s,
    /* [in] */ double t,
    /* [in] */ double r);


void __RPC_STUB _GLScript_Context_glTexCoord3d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord3dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float s,
    /* [in] */ float t,
    /* [in] */ float r);


void __RPC_STUB _GLScript_Context_glTexCoord3f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord3fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int s,
    /* [in] */ int t,
    /* [in] */ int r);


void __RPC_STUB _GLScript_Context_glTexCoord3i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord3iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short s,
    /* [in] */ short t,
    /* [in] */ short r);


void __RPC_STUB _GLScript_Context_glTexCoord3s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord3sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord3sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double s,
    /* [in] */ double t,
    /* [in] */ double r,
    /* [in] */ double q);


void __RPC_STUB _GLScript_Context_glTexCoord4d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord4dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float s,
    /* [in] */ float t,
    /* [in] */ float r,
    /* [in] */ float q);


void __RPC_STUB _GLScript_Context_glTexCoord4f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord4fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int s,
    /* [in] */ int t,
    /* [in] */ int r,
    /* [in] */ int q);


void __RPC_STUB _GLScript_Context_glTexCoord4i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord4iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short s,
    /* [in] */ short t,
    /* [in] */ short r,
    /* [in] */ short q);


void __RPC_STUB _GLScript_Context_glTexCoord4s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoord4sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glTexCoord4sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexCoordPointer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int size,
    /* [in] */ unsigned int type,
    /* [in] */ int stride,
    /* [in] */ _GLScript_Array *pointer);


void __RPC_STUB _GLScript_Context_glTexCoordPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexEnvf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glTexEnvf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexEnvfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexEnvfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexEnvi_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glTexEnvi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexEnviv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexEnviv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGend_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ double param);


void __RPC_STUB _GLScript_Context_glTexGend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGendv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexGendv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGenf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glTexGenf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGenfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexGenfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGeni_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glTexGeni_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexGeniv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int coord,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexGeniv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexImage1D_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ int internalformat,
    /* [in] */ int width,
    /* [in] */ int border,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glTexImage1D_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexImage2D_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ int internalformat,
    /* [in] */ int width,
    /* [in] */ int height,
    /* [in] */ int border,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glTexImage2D_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexParameterf_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ float param);


void __RPC_STUB _GLScript_Context_glTexParameterf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexParameterfv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexParameterfv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexParameteri_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ int param);


void __RPC_STUB _GLScript_Context_glTexParameteri_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexParameteriv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ unsigned int pname,
    /* [in] */ _GLScript_Array *params);


void __RPC_STUB _GLScript_Context_glTexParameteriv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexSubImage1D_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ int xoffset,
    /* [in] */ int width,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glTexSubImage1D_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTexSubImage2D_Proxy( 
    _GLScript_Context * This,
    /* [in] */ unsigned int target,
    /* [in] */ int level,
    /* [in] */ int xoffset,
    /* [in] */ int yoffset,
    /* [in] */ int width,
    /* [in] */ int height,
    /* [in] */ unsigned int format,
    /* [in] */ unsigned int type,
    /* [in] */ _GLScript_Array *pixels);


void __RPC_STUB _GLScript_Context_glTexSubImage2D_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTranslated_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z);


void __RPC_STUB _GLScript_Context_glTranslated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glTranslatef_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z);


void __RPC_STUB _GLScript_Context_glTranslatef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y);


void __RPC_STUB _GLScript_Context_glVertex2d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex2dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y);


void __RPC_STUB _GLScript_Context_glVertex2f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex2fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y);


void __RPC_STUB _GLScript_Context_glVertex2i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex2iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB _GLScript_Context_glVertex2s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex2sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex2sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z);


void __RPC_STUB _GLScript_Context_glVertex3d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex3dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z);


void __RPC_STUB _GLScript_Context_glVertex3f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex3fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int z);


void __RPC_STUB _GLScript_Context_glVertex3i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex3iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ short z);


void __RPC_STUB _GLScript_Context_glVertex3s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex3sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex3sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4d_Proxy( 
    _GLScript_Context * This,
    /* [in] */ double x,
    /* [in] */ double y,
    /* [in] */ double z,
    /* [in] */ double w);


void __RPC_STUB _GLScript_Context_glVertex4d_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4dv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex4dv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4f_Proxy( 
    _GLScript_Context * This,
    /* [in] */ float x,
    /* [in] */ float y,
    /* [in] */ float z,
    /* [in] */ float w);


void __RPC_STUB _GLScript_Context_glVertex4f_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4fv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex4fv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4i_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int z,
    /* [in] */ int w);


void __RPC_STUB _GLScript_Context_glVertex4i_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4iv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex4iv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4s_Proxy( 
    _GLScript_Context * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ short z,
    /* [in] */ short w);


void __RPC_STUB _GLScript_Context_glVertex4s_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertex4sv_Proxy( 
    _GLScript_Context * This,
    /* [in] */ _GLScript_Array *v);


void __RPC_STUB _GLScript_Context_glVertex4sv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glVertexPointer_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int size,
    /* [in] */ unsigned int type,
    /* [in] */ int stride,
    /* [in] */ _GLScript_Array *pointer);


void __RPC_STUB _GLScript_Context_glVertexPointer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE _GLScript_Context_glViewport_Proxy( 
    _GLScript_Context * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int width,
    /* [in] */ int height);


void __RPC_STUB _GLScript_Context_glViewport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___GLScript_Context_INTERFACE_DEFINED__ */

#endif /* __LIBGLScript_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


