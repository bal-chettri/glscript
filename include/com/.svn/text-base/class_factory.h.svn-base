//
// class_factory.h    Provides support for COM IClassFactory interface.
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
#ifndef __com_class_factory_h
 #define __com_class_factory_h

/* External vars: This header requires you to define these variables somewhere in your project. */
extern DWORD _comLockCount;
extern DWORD _comObjCount;

/**
 * Provides template based implementation for IClassFacory COM interface.
 * 
 * @param _T The class implementing the IClassFactory interface.
 */
template <class _T>
class ClassFactory : public IClassFactory {
public:
	/* IUnknown implementation */

	/** Queries for requested interface and returns it if it is implemented. */
	virtual HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, LPVOID *ppV) {
		if ( IsEqualIID (riid, IID_IUnknown) || IsEqualIID (riid, IID_IClassFactory) ) {
			*ppV = this;
			return NOERROR;
		}

		*ppV = NULL;
		return E_NOINTERFACE;
	}

	/** Increments the reference count. */
	virtual ULONG STDMETHODCALLTYPE AddRef () {
		return 1;
	}

	/** Decrements the reference count. */
	virtual ULONG STDMETHODCALLTYPE Release () {
		return 1;
	}

	/* IClassFactory implementation */

	/** Creates an instance of template type _T and returns the requested interface if the object implements it. */
	virtual HRESULT STDMETHODCALLTYPE CreateInstance (LPUNKNOWN pUnkOuter, REFIID riid, LPVOID *ppV) {
		*ppV = NULL;

		if (pUnkOuter != NULL) {
			return CLASS_E_NOAGGREGATION;
		}

		_T *pObj =  new _T;
		if (!pObj) {
			return E_OUTOFMEMORY;
		}

		// increment global object count
		::InterlockedIncrement ((LONG *)&_comObjCount);

		pObj->AddRef ();
		HRESULT hr = pObj->QueryInterface (riid, ppV);	
		pObj->Release ();

		return hr;
	}

	/** Increments or decrements the object lock counter. */
	virtual HRESULT STDMETHODCALLTYPE LockServer (BOOL fLock) {
		if (fLock) {
			InterlockedIncrement ((LONG *)&_comLockCount);
		} else {
			InterlockedDecrement ((LONG *)&_comLockCount);
		}

		return NOERROR;
	}
};

#endif /* __com_class_factory_h */
