//
// gls_activescript_array.cpp   glscript Array class definition.
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
#include "stdafx.h"

// compile under WIN32 only!
#ifdef WIN32

#include <glscript/activescript/gls_activescript_array.h>
#include <glscript/activescript/gls_activescript_marshal.h>

// define externs...
const IID *GLScript_Array_IIDs[] = {
	&IID_IUnknown,
	&IID_IDispatch,
	&IID__GLScript_Array,
	NULL
};

ClassFactory<GLScript_Array> GLScriptArray_Factory;

// GLScript_Array class definition...

GLScript_Array::GLScript_Array () {
	m_type = -1; /* type invalid : no data */
	m_data = NULL;
	m_length = 0;
}

GLScript_Array::~GLScript_Array () {
	FreeArray ();
}

/* _GLScript_Array methods */

HRESULT STDMETHODCALLTYPE GLScript_Array::get_type (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}

	*pValue = m_type;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Array::get_length (int *pValue) {
	if (!pValue) {
		return E_POINTER;
	}

	*pValue = m_length;
	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Array::get (int index, VARIANT *pValue) {
	if (m_type == -1) {
		return E_FAIL;
	}
	if (index < 0 || index >= m_length) {
		return E_INVALIDARG;
	}
	if (!pValue) {
		return E_POINTER;
	}

	switch (m_type) {
	case GL_BYTE:
		pValue->vt = VT_I1;
		pValue->cVal = (reinterpret_cast<GLbyte *>(m_data)) [index];
		break;

	case GL_UNSIGNED_BYTE:
		pValue->vt = VT_UI1;
		pValue->bVal = (reinterpret_cast<GLubyte *>(m_data)) [index];
		break;

	case GL_SHORT:
		pValue->vt = VT_I2;
		pValue->iVal = (reinterpret_cast<GLshort *>(m_data)) [index];
		break;

	case GL_UNSIGNED_SHORT:
		pValue->vt = VT_UI2;
		pValue->uiVal = (reinterpret_cast<GLushort *>(m_data)) [index];
		break;

	case GL_INT:
		pValue->vt = VT_INT;
		pValue->intVal = (reinterpret_cast<GLint *>(m_data)) [index];
		break;

	case GL_UNSIGNED_INT:	
		pValue->vt = VT_UINT;
		pValue->uintVal = (reinterpret_cast<GLuint *>(m_data)) [index];
		break;

	case GL_FLOAT:
		pValue->vt = VT_R4;
		pValue->fltVal = (reinterpret_cast<GLfloat *>(m_data)) [index];
		break;

	case GL_DOUBLE:
		pValue->vt = VT_R8;
		pValue->dblVal = (reinterpret_cast<GLdouble *>(m_data)) [index];
		break;
	}

	return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLScript_Array::put (int index, VARIANT value) {
	if (m_type == -1) {
		return E_FAIL;
	}
	if (index < 0 || index >= m_length) {
		return E_INVALIDARG;
	}
	
	bool result = false;

	switch (m_type) {
	case GL_BYTE:
		result = ::gls_comvariant_get_char_value (&value, reinterpret_cast<GLbyte *>(m_data) + index );
		break;

	case GL_UNSIGNED_BYTE:
		result = ::gls_comvariant_get_byte_value (&value, reinterpret_cast<GLubyte *>(m_data) + index );
		break;

	case GL_SHORT:
		result = ::gls_comvariant_get_short_value (&value, reinterpret_cast<GLshort *>(m_data) + index );
		break;

	case GL_UNSIGNED_SHORT:
		result = ::gls_comvariant_get_ushort_value (&value, reinterpret_cast<GLushort *>(m_data) + index );
		break;

	case GL_INT:
		result = ::gls_comvariant_get_int_value (&value, reinterpret_cast<GLint *>(m_data) + index );
		break;

	case GL_UNSIGNED_INT:
		result = ::gls_comvariant_get_uint_value (&value, reinterpret_cast<GLuint *>(m_data) + index );
		break;

	case GL_FLOAT:
		result = ::gls_comvariant_get_float_value (&value, reinterpret_cast<GLfloat *>(m_data) + index );
		break;

	case GL_DOUBLE:
		result = ::gls_comvariant_get_double_value (&value, reinterpret_cast<GLdouble *>(m_data) + index );
		break;
	}
	
	if (!result) {
		return E_INVALIDARG;
	}

	return NOERROR;
}

/* internal public member function */

HRESULT GLScript_Array::CreateWithTypeAndLength (int type, int length) {
	if (!CheckArrayType(type)) {
		return E_INVALIDARG;;
	}
	if (length < 0) {
		return E_INVALIDARG;
	}

	// release old array data
	FreeArray ();

	// set new array data
	m_data = AllocArray (type, length);

	if (m_data == NULL) {
		return E_OUTOFMEMORY;
	}

	m_length = length;
	m_type = type;

	return NOERROR;
}

HRESULT GLScript_Array::CreateWithTypeAndElements (int type, BSTR pArrayConfig) {
	if (!CheckArrayType(type)) {
		return E_INVALIDARG;
	}
	if (!pArrayConfig) {
		return E_INVALIDARG;
	}

	return ScanArray (type, pArrayConfig);
}

/* private member functions */

BOOL GLScript_Array::CheckArrayType (int type) {
	if (type == GL_BYTE || 
		type == GL_UNSIGNED_BYTE || 
		type == GL_SHORT || 
		type == GL_UNSIGNED_SHORT || 
		type == GL_INT || 
		type == GL_UNSIGNED_INT || 
		type == GL_FLOAT || 
		type == GL_DOUBLE )
	{
		return TRUE;
	}

	return FALSE;
}

void GLScript_Array::FreeArray () {
	if (m_data) {
		delete [] m_data;
		m_data = NULL;
	}

	m_length = 0;
	m_type = -1; /* type invalid : no data */
}

void *GLScript_Array::AllocArray (int type, int length) {
	void *ptr = NULL;

	switch (type) {
	case GL_BYTE:
		ptr = new GLbyte [length];
		break;
	
	case GL_UNSIGNED_BYTE:
		ptr = new GLubyte [length];
		break;
	
	case GL_SHORT:
		ptr = new GLshort [length];
		break;

	case GL_UNSIGNED_SHORT:
		ptr = new GLushort [length];
		break;

	case GL_INT:
		ptr = new GLint [length];
		break;

	case GL_UNSIGNED_INT:
		ptr = new GLuint [length];
		break;

	case GL_FLOAT:
		ptr = new GLfloat [length];
		break;

	case GL_DOUBLE:
		ptr = new GLdouble [length];
		break;
	}

	return ptr;
}

HRESULT GLScript_Array::ScanArray (int type, BSTR pArrayConfig) {
	// make a temp copy of the array config string 
	wchar_t *pTempArrayConfig = (wchar_t *)::SysAllocString (pArrayConfig);
	if (pTempArrayConfig == NULL) {
		return E_OUTOFMEMORY;
	}

	// scan array config for elements
	wchar_t *ptr = pTempArrayConfig;
	int length = 0;
	while (*ptr != _T('\0')) {
		// if its , symbol terminate
		if (*ptr == _T(',')) {
			*ptr = _T('\0');
			++length;
		}
		++ptr; // next character
	}
	if (ptr > pTempArrayConfig)
		++length;

	// allocate new data array if required
	void *ptrData = NULL;

	if (length >= 0) {
		ptrData = AllocArray (type, length);
		if (!ptrData) {
			// free temp array config string
			::SysFreeString (pTempArrayConfig);
			return E_OUTOFMEMORY;
		}

		// convert array elements
		if (!ConvertArrayElements (type, pTempArrayConfig, length, ptrData)) {
			// do cleanup and return error
			::SysFreeString (pTempArrayConfig);
			delete [] pTempArrayConfig;
			return E_INVALIDARG;
		}
	}

	// release old array data
	FreeArray ();

	// set new array data
	m_data = ptrData;
	m_length = length;
	m_type = type;

	// free the temp copy of array config string
	::SysFreeString (pTempArrayConfig);
	return NOERROR;
}

BOOL GLScript_Array::ConvertArrayElements (int type, wchar_t *ptr, int length, void *buff) {
	int i = 0;
	
	switch (type) {
	case GL_BYTE:
		for (; i < length; i++) {
			reinterpret_cast<GLbyte *>(buff) [i] = (GLbyte)::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_UNSIGNED_BYTE:
		for (; i < length; i++) {
			reinterpret_cast<GLubyte *>(buff) [i] = (GLubyte)::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_SHORT:
		for (; i < length; i++) {
			reinterpret_cast<GLshort *>(buff) [i] = (GLshort)::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_UNSIGNED_SHORT:
		for (; i < length; i++) {
			reinterpret_cast<GLushort *>(buff) [i] = (GLushort)::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_INT:
		for (; i < length; i++) {
			reinterpret_cast<GLint *>(buff) [i] = (GLint) ::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_UNSIGNED_INT:
		for (; i < length; i++) {
			reinterpret_cast<GLuint *>(buff) [i] = (GLuint) ::_wtoi (ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_FLOAT:
		for (; i < length; i++) {
			reinterpret_cast<GLfloat *>(buff) [i] = (GLfloat)::_wtof(ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	case GL_DOUBLE:
		for (; i < length; i++) {
			reinterpret_cast<GLdouble *>(buff) [i] = (GLdouble)::_wtof(ptr);
			ptr+= ::wcslen(ptr) + 1;
		}
		break;

	default:
		return FALSE;
	}
	
	return TRUE;
}

#endif // WIN32
