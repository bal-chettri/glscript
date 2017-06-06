//
// 
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
#include "gls_obj.h"
#include <gls_sdk/glscript/gls_ext_lib_i.c>

// global data
DWORD _tlsIndex;
GLSExtensionLife _life;
HINSTANCE _hAppInstance;
DWORD _comLockCount;
DWORD _comObjCount;

//
// GLSExtensionLife Life time management
//
GLSExtensionLife::GLSExtensionLife () {
    _tlsIndex = ::TlsAlloc ();
}

GLSExtensionLife::~GLSExtensionLife () {
    ::TlsFree (_tlsIndex);
}

//
// GLSExtension function definitions
//

// gls_extension_initialize. Initializes the extension.
GLS_EXTENSION_API bool GLS_API_CALL gls_extension_initialize (gls::ExtensionHost *pExtensionHost) {
    // Allocate and initialize thread specific data
    GLS_EXT_DATA *pData = new GLS_EXT_DATA ();
    if (!pData) {
        return false;
    }
    pData->pExtensionHost = pExtensionHost;
    pData->pExtension = NULL;

    // Save thread specific data in the TLS
    ::TlsSetValue (_tlsIndex, (LPVOID)pData);

    return true;
}

// gls_extension_get_interface. Returns the extension interface
GLS_EXTENSION_API gls::Extension *GLS_API_CALL gls_extension_get_interface () {
    LPVOID pVoid = ::TlsGetValue (_tlsIndex);

    GLS_EXT_DATA *pData = reinterpret_cast<GLS_EXT_DATA *>(pVoid);

    if (pData->pExtension == NULL) {
        pData->pExtension = new GLSExtensionImp (pData->pExtensionHost);
    }

    return pData->pExtension;
}

// gls_extension_terminate. Terminates the extension
GLS_EXTENSION_API void GLS_API_CALL gls_extension_terminate (void) {

    LPVOID pVoid = ::TlsGetValue (_tlsIndex);

    GLS_EXT_DATA *pData = reinterpret_cast<GLS_EXT_DATA *>(pVoid);

    if (pData->pExtension) {
        delete pData->pExtension;
    }

    if (pData) {
        delete  pData;
    }

    ::TlsSetValue (_tlsIndex, NULL);
}

// DLLMain. Defines the DLL Entry point
BOOL WINAPI DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        _hAppInstance = hinstDLL;

        ::DisableThreadLibraryCalls ( (HMODULE)hinstDLL );
    }

    return TRUE;
}
