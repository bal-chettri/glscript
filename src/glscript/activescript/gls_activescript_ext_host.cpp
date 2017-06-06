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

#if defined(WIN32)
#include <glscript/gls_macros.h>
#include <glscript/activescript/gls_activescript_host.h>
#include <glscript/activescript/gls_ext_lib.h>

using namespace gls;

// GLScript_ExtensionHost class definition...

GLScript_ExtensionHost::GLScript_ExtensionHost (GLScriptHost_Win32 *parent) : 
    m_parent(parent), 
    m_pfn_render_proc(NULL), 
    m_render_proc_context(NULL)
{ }

GLScript_ExtensionHost::~GLScript_ExtensionHost () {
    UnloadAllExtensions ();
}

// GLExtensionHost interface implementation...

unsigned short GLScript_ExtensionHost::GetInterfaceVersion () {
    return GLS_EXTENSION_HOST_INTERFACE_VERSION;
}

GLS_ENVIRONMENT_TYPE GLScript_ExtensionHost::GetEnvironmentType (void) {
    return GLS_ENVIRONMENT_PLAYER;
}

unsigned long GLScript_ExtensionHost::GetToolkitVersion () {
    return GLS_VERSION_MAKE_LONG(0,0,0,1);
}

unsigned long GLScript_ExtensionHost::GetPlayerVersion () {
    return GLS_VERSION_MAKE_LONG(0,0,0,1);
}

bool GLScript_ExtensionHost::GetScriptInfo (GLS_SCRIPT_INFO *p_out_script_info) {
    // #TODO: implementation
    return false;
}

// Loads an extension and returns its main interface
Extension *GLScript_ExtensionHost::LoadExtension (const char *path, unsigned long load_options) {
    GLS_EXTENSION_MODULE *pExtMod = LoadExtensionInternal (path, load_options);
    
    return pExtMod ? pExtMod->pExtInterface : NULL;
}

// Loads a lib extension and returns its lib interface
void *GLScript_ExtensionHost::LoadLibraryExtension (const char *path) {
    GLS_EXTENSION_MODULE *pExtMod = LoadExtensionInternal (path, GLS_EXTENSION_LIBRARY);
    if (pExtMod == NULL) {
        return NULL;
    }

    reinterpret_cast<_GLScriptExtLib *>(pExtMod->pLibInterface)->AddRef ();

    return pExtMod->pLibInterface;
}

GLS_TIMER_PROC GLScript_ExtensionHost::HookTimerProc (GLS_TIMER_PROC p_timer_proc, void *pContext) {
    return NULL;
}

GLS_RENDER_PROC GLScript_ExtensionHost::HookRenderProc (GLS_RENDER_PROC p_render_proc, void *pContext) {
    GLS_RENDER_PROC prev_render_proc = m_pfn_render_proc;

    m_pfn_render_proc = p_render_proc;
    m_render_proc_context = pContext;

    return prev_render_proc;
}

void *GLScript_ExtensionHost::GetHostObject (const char *name) {
    IUnknown *pUnknown;
    IDispatch *pDispatch;
    HRESULT hr;

    if (name == NULL) {
        return NULL;
    }

    // convert name to wide string
    size_t name_length = strlen (name);
    wchar_t *olesz_name_buff = new wchar_t [name_length + 1];
    ::mbstowcs (olesz_name_buff, name, name_length);
    olesz_name_buff [name_length] = L'\0';

    // get the named item info from the script host's site object
    hr = m_parent->m_site.GetItemInfo (olesz_name_buff, SCRIPTINFO_IUNKNOWN, 
                                        &pUnknown, NULL);

    // free wide string buffer when done
    delete olesz_name_buff;

    if (SUCCEEDED(hr)) {
        // Query the IDispatch interface    
        hr = pUnknown->QueryInterface (IID_IDispatch, (void **)&pDispatch);

        // release the IUnknown interface. Note that the object still exists
        // if QueryInterface for the IDispatch interface was successful
        pUnknown->Release ();
    }

    if (SUCCEEDED(hr)) {
        // The caller extension should release the IDispatch interface when done
        return pDispatch;
    }

    // named object not found or the interface was not returned!
    return NULL;
}

void *GLScript_ExtensionHost::GetArrayRawData (void *pTypedArray) {
    if (!pTypedArray) {
        return NULL;
    }

    GLScript_Array *pObjArray = reinterpret_cast<GLScript_Array *>(pTypedArray);
    return (void *)pObjArray->GetInternalData ();
}

// public methods...

void GLScript_ExtensionHost::UnloadAllExtensions () {
    std::list<GLS_EXTENSION_MODULE *>::iterator 
            it = m_list_extensions_modules.begin(),
            it_end = m_list_extensions_modules.end();

    // unload all extension modules
    for (; it != it_end; it++) {
        GLS_EXTENSION_MODULE *p_extension_module = *it;
        gls_extension_unload (p_extension_module);
    }
    
    // remove all extension modules from the list
    m_list_extensions_modules.clear ();

    // always clear the render proc state when the extensions are unloaded
    m_pfn_render_proc = NULL;
    m_render_proc_context = NULL;
}

// internal private methods...

GLS_EXTENSION_MODULE *GLScript_ExtensionHost::LoadExtensionInternal (const char *name, unsigned long load_options) {
    // look for this extension before we load it.
    GLS_EXTENSION_MODULE *p_extentsion_module = LookupExtension (name);

    if (p_extentsion_module != NULL) {
        // extension is already loaded. check if all load options are supported.
        if ( (p_extentsion_module->pExtInterface->GetCapabilities() & load_options) != load_options ) {
            return NULL;
        }

        // all capabilites supported, return the extension
        return p_extentsion_module;
    }
    
    // load the extension using our standard API
    p_extentsion_module = gls_extension_load (name, load_options, this);
    if (NULL == p_extentsion_module) {
        return NULL;
    }

    // check existence of libname for a library extension
    if (load_options & GLS_EXTENSION_LIBRARY) {
        if ( LookupExtensionByLibName (p_extentsion_module->libInfo.name) ) {
            // libname already in use. abort loading extension.
            gls_extension_unload (p_extentsion_module);
            return NULL;
        }
    }

    // register the extension in our lookup table
    m_list_extensions_modules.push_back (p_extentsion_module);
    return p_extentsion_module;
}

GLS_EXTENSION_MODULE *GLScript_ExtensionHost::LookupExtension (const char *path) {
    std::list<GLS_EXTENSION_MODULE *>::iterator 
            it = m_list_extensions_modules.begin(),
            it_end = m_list_extensions_modules.end();

    for (; it != it_end; it++) {
        GLS_EXTENSION_MODULE *pExt = *it;
        if ( !strcmp(path,pExt->path) ) {
            return pExt;
        }
    }

    return NULL;
}

GLS_EXTENSION_MODULE *GLScript_ExtensionHost::LookupExtensionByLibName (const char *libname) {
    std::list<GLS_EXTENSION_MODULE *>::iterator 
            it = m_list_extensions_modules.begin(),
            it_end = m_list_extensions_modules.end();

    for (; it != it_end; it++) {
        GLS_EXTENSION_MODULE *pExt = *it;
        if (pExt->capabilities & GLS_EXTENSION_LIBRARY) {
            if ( ::strcmp(libname,pExt->libInfo.name) == 0 ) {
                return pExt;
            }
        }
    }

    return NULL;
}

#endif // WIN32
