//
// dispatch.h    Provides support for Automation IDispatch interface. 
// 
// This file is part of glScript project.
//
//   glScript is free software: you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   glScript is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU Lesser General Public License for more details.
//
//   You should have received a copy of the GNU Lesser General Public License
//   along with glScript. If not, see <http://www.gnu.org/licenses/>.
//
//   Copyright (c) 2012 Bal Bahadur Chettri
//
//   Author: Bal Bahadur Chettri (balu.chettri@gmail.com)
//
//   Version: 1.0
//
//   Last Updated: Mon, Oct 31, 2011
//                 Sat, Jun 32, 2012
//
#ifndef __com_dispatch_h
 #define __com_dispatch_h

/* External vars: This header requries you to define these variables somewhere 
   in your project. */
extern DWORD _comLockCount;
extern DWORD _comObjCount;
extern HINSTANCE _hAppInstance;

/**
 * AutomationComObject template class. This class provides implementation for basic
 * COM interfaces IUnknown and IDispatch. It supports automation using type library,
 * which needs to be embedded in your EXE/DLL resource. If you need to support 
 * automation, embed your type library file as a TYPELIB resource with ID TYPELIB1 = 1.
 *
 * @param _BaseInterface The base COM interface derived from IDispatch (or IUnknown atleast)
 * the class is implementing.
 *
 * @param _IID_Interfacess Pointer to array of IID pointers containing the interface
 * IDs supported by the automation COM object. The array must be NULL terminated.
 *
 * @param _IID_TypeLib Pointer to interface identifier (IID) for which to load the 
 * type library (may be NULL). This will usually be IID of the _BaseInterface.
 */
template <class _BaseInterface, const IID **_IID_Interfaces, const IID *_IID_TypeLib = NULL>
class AutomationComObject : public _BaseInterface {
public:
    /* IUnknown implementation */

    /**
     * QueryInterface() method. Returns an interface supported by this COM class. Supported
     * interfaces must be specified in the _IID_Interfaces template argument.
     */
    virtual HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, LPVOID *ppV) {
        const IID **p_iids = _IID_Interfaces;
        
        // check if the requested inteface is supported
        for (int i=0; p_iids[i]; i++) {
            if ( IsEqualIID (riid, *p_iids[i]) ) {
                *ppV = (LPVOID *) this;
                this->AddRef ();
                return NOERROR;
            }
        }

        // no interface found!
        *ppV = NULL;
        return E_NOINTERFACE;
    }

    /**
     * AddRef() method. Increments the refefence count.
     */
    virtual ULONG STDMETHODCALLTYPE AddRef () {
        return ++m_ref_count;
    }

    /**
     * Release() method. Decrements the reference count thereby releasing the reference 
     * and deletes the object when the ref count reaches 0
     */
    virtual ULONG STDMETHODCALLTYPE Release () {
        // decrement the reference count and check if it reached 0
        if ( --m_ref_count == 0 )
        {           
            // no references to this object now so delete this object from heap
            delete this;

            // decrement the object count
            ::InterlockedDecrement ((LONG *)&_comObjCount);

            return 0;
        }

        // return the new referenc count
        return m_ref_count;
    }

    /* IDispatch implementation */

    /**
     * GetTypeInfoCount() method. Returns count of type info for the object.
     */
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount (UINT FAR* pctinfo) {
        if (!pctinfo) {
            return E_POINTER;
        }
        *pctinfo = 1;
        return NOERROR;
    }

    /**
     * GetTypeInfo () method. Returns the type info i.e. the ITypeInfo interface for the object.
     */
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo (unsigned int iTInfo, LCID lcid, 
                                                   ITypeInfo FAR* FAR* ppTInfo) 
    {
        *ppTInfo = NULL;

        if (iTInfo != 0) {
            return ResultFromScode (DISP_E_BADINDEX);
        }

        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return S_FALSE;
            }
        }

        m_pTypeInfo->AddRef ();
        *ppTInfo = m_pTypeInfo;

        return NOERROR;
    }

    /**
     * GetIDsOfNames () method. Returns the dispatch IDs of names in the type info.
     */
    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames (REFIID riid, OLECHAR FAR* FAR* rgszNames, 
                                                     unsigned int cNames, LCID lcid, 
                                                     DISPID FAR* rgDispId ) 
    {
        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return E_FAIL;
            }
        }
        
        return ::DispGetIDsOfNames (m_pTypeInfo, rgszNames, cNames, rgDispId);
    }

    /**
     * Invoke () method. Invokes a method using its DISPID (dispatch identifier).
     */
    virtual HRESULT STDMETHODCALLTYPE Invoke (DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, 
                                              DISPPARAMS FAR* pDispParams, VARIANT FAR* pVarResult, 
                                              EXCEPINFO FAR* pExcepInfo, unsigned int FAR* puArgErr )
    {
        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return E_FAIL;
            }
        }
        
        HRESULT hr = ::DispInvoke (this, m_pTypeInfo, dispIdMember, wFlags, pDispParams, pVarResult, 
                                   pExcepInfo, puArgErr);
        return hr;
    }

protected:
    // ctor() is protected as you don't create the direct object
    // of this class; you must inherit from this class
    AutomationComObject () {
        m_ref_count = 0;
        m_pTypeInfo = NULL;
    }

    // dtor()
    virtual ~AutomationComObject () {
        if (m_pTypeInfo) {
            m_pTypeInfo->Release ();
            m_pTypeInfo = NULL;
        }
    }

    /**
     * LoadTypeLib () method. Internal helper method to load the type library. The interface
     * identifier IID for the type library must be specified in the _IID_TypelLib template 
     * parameter.
     */
    BOOL LoadTypeLib () {
        if (!_IID_TypeLib) {
            return FALSE;
        }
        
        HRESULT hr;
        ITypeLib *pTypeLib;

        TCHAR modulePath [256];     
        // ::GetModuleFileName (_hAppInstance, modulePath, sizeof(modulePath)/sizeof(modulePath[0]));
        GetModuleFileNameEx ( ::GetCurrentProcess(), (HMODULE)_hAppInstance, modulePath, sizeof(modulePath)/sizeof(modulePath[0]) );

        #if defined (_UNICODE) || defined(UNICODE)
            hr = ::LoadTypeLib (modulePath, &pTypeLib);
        #else
            OLECHAR wModulePath [256];
            ::mbstowcs (wModulePath, modulePath, sizeof(modulePath)/sizeof(modulePath[0]));
            hr = ::LoadTypeLib (wModulePath, &pTypeLib);
        #endif
        
        if (FAILED(hr)) {
            return FALSE;
        }

        hr = pTypeLib->GetTypeInfoOfGuid (*_IID_TypeLib, &m_pTypeInfo);

        UINT count = pTypeLib->GetTypeInfoCount ();

        pTypeLib->Release ();

        if (FAILED(hr)) {
            return FALSE;
        }
        return TRUE;
    }

private:
    /** reference count of the COM object */
    DWORD m_ref_count;
    /** type info interface */
    ITypeInfo *m_pTypeInfo;
};

/**
 * AutomationContainedComObject template class. This class provides implementation for basic
 * COM interfaces IUnknown and IDispatch useful for a contained or aggregated COM object. 
 * For a normal / parent COM object, use AutomationComObject. It supports automation using 
 * type library, which needs to be embedded in your EXE/DLL resource. If you need to support 
 * automation, then you must embed your type library file as a TYPELIB resource with 
 * resource ID TYPELIB1 = 1.
 *
 * @param _BaseInterface The base interface derived from IDispatch (or IUnknown atleast)
 * the class is implementating.
 *
 * @param _IID_Interfacess Pointer to array of IID pointers containing the interface
 * IDs supported by the automation COM object. The array must be NULL terminated.
 *
 * @param _IID_TypeLib Pointer to interface identifier (IID) for which to load the 
 * type library (may be NULL).
 */
template <class _BaseInterface, const IID **_IID_Interfacess, const IID *_IID_TypeLib = NULL>
class AutomationContainedComObject : public _BaseInterface {
public:
    // IUnknown methods
    virtual HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, LPVOID *ppV) {
        const IID **p_iids = _IID_Interfacess;

        for (int i=0; p_iids[i]; i++) {
            if ( IsEqualIID (riid, *p_iids[i]) )  {
                *ppV = (LPVOID *) this;
                AddRef ();
                return NOERROR;
            }
        }

        *ppV = NULL;
        return E_NOINTERFACE;
    }
    
    virtual ULONG STDMETHODCALLTYPE AddRef () {
        return m_pParent->AddRef ();
    }

    virtual ULONG STDMETHODCALLTYPE Release () {
        return m_pParent->Release ();
    }

    /* IDispatch implementation */
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount (UINT FAR* pctinfo) {
        if (!pctinfo)
            return E_POINTER;
        *pctinfo = 1;
        return NOERROR;
    }

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo (unsigned int iTInfo, LCID lcid, 
                                                   ITypeInfo FAR* FAR* ppTInfo) 
    {
        *ppTInfo = NULL;

        if (iTInfo != 0) {
            return ResultFromScode (DISP_E_BADINDEX);
        }

        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return S_FALSE;
            }
        }

        m_pTypeInfo->AddRef ();
        *ppTInfo = m_pTypeInfo;

        return NOERROR;
    }

    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames (REFIID riid, OLECHAR FAR* FAR* rgszNames, 
                                                     unsigned int cNames, LCID lcid, 
                                                     DISPID FAR* rgDispId ) 
    {
        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return E_FAIL;
            }
        }

        return ::DispGetIDsOfNames (m_pTypeInfo, rgszNames, cNames, rgDispId);
    }

    virtual HRESULT STDMETHODCALLTYPE Invoke (DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, 
                                              DISPPARAMS FAR* pDispParams, VARIANT FAR* pVarResult, 
                                              EXCEPINFO FAR* pExcepInfo, unsigned int FAR* puArgErr )
    {
        if (!m_pTypeInfo) {
            // lazy load the type library
            if (!LoadTypeLib()) {
                return E_FAIL;
            }
        }
        
        return ::DispInvoke (this, m_pTypeInfo, dispIdMember, wFlags, pDispParams, pVarResult, 
                             pExcepInfo, puArgErr);
    }

protected:
    ITypeInfo *m_pTypeInfo;

    IUnknown *GetParent () {
        return m_pParent;
    }   

    AutomationContainedComObject ( IUnknown *pParent ) {
        m_pParent = pParent;
        m_pTypeInfo = NULL;
    }

    virtual ~AutomationContainedComObject () {
        if (m_pTypeInfo) {
            m_pTypeInfo->Release ();
            m_pTypeInfo = NULL;
        }
    }

    BOOL LoadTypeLib () {
        if (!_IID_TypeLib) {
            return FALSE;
        }

        HRESULT hr;
        ITypeLib *pTypeLib;

        TCHAR modulePath [256];     
        // ::GetModuleFileName (_hAppInstance, modulePath, sizeof(modulePath)/sizeof(modulePath[0]));
        GetModuleFileNameEx ( ::GetCurrentProcess(), (HMODULE)_hAppInstance, 
                              modulePath, sizeof(modulePath)/sizeof(modulePath[0]) 
                             );

        #if defined (_UNICODE) || defined(UNICODE)
            hr = ::LoadTypeLib (modulePath, &pTypeLib);
        #else
            OLECHAR wModulePath [256];
            ::mbstowcs (wModulePath, modulePath, sizeof(modulePath)/sizeof(modulePath[0]));
            hr = ::LoadTypeLib (wModulePath, &pTypeLib);
        #endif
        
        if (FAILED(hr)) {
            return FALSE;
        }

        UINT count = pTypeLib->GetTypeInfoCount ();

        hr = pTypeLib->GetTypeInfoOfGuid (*_IID_TypeLib, &m_pTypeInfo);

        pTypeLib->Release ();

        if (FAILED(hr)) {
            return FALSE;
        }
        return TRUE;
    }

private:
    IUnknown *m_pParent;
};

#endif /* __com_dispatch_h */
