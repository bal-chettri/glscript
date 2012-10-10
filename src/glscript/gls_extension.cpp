//
// gls_extension.cpp   glscript extension support.
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
#include <glscript/gls_extension.h>
#include <glscript/gls_macros.h>
#if defined(WIN32)
#include <glscript/activescript/gls_ext_lib.h>
#endif
#include <sysport/sysport.h>

using namespace gls;

//
// #TODO: In DEBUG builds, 'name' parameter in gls_extension_load () function
// is used as absolute path of the extension so as to load the extension using 
// its full path (for facilitating debugging). This needs to be undefined to 
// treat 'name' parameter as simply module name in the release builds.
//
#if defined (DEBUG) || defined (_DEBUG)
// #define GLS_EXTENSION_LOAD_TREAT_NAME_AS_PATH
#endif

// define gls extension name prefix
#if defined(WIN32)
	#define EXT_MOD_NAME_PREFIX				"gls_"
#else
	#define EXT_MOD_NAME_PREFIX				"lib"
#endif

// define extension name for gls extension modules
#if defined(WIN32)
	#define EXT_MOD_EXT_NAME				"dll"
#else
	#define EXT_MOD_EXT_NAME				"so"
#endif

// Define extension specific macros
#if defined(WIN32)
	#define EXT_LOAD(N)				::LoadLibraryA(libPath);
#else
	#define EXT_LOAD(N)				NULL
#endif

#if defined(WIN32)
	#define EXT_UNLOAD(M)			::FreeLibrary(M)
#else
	#define EXT_UNLOAD(M)			
#endif

// Returns entry point of function in the extension module
#if defined(WIN32)
	#define EXT_ENTRY_POINT(M,P,N)	P = (pfn_##N)::GetProcAddress(M, #N)
#else
	#define EXT_ENTRY_POINT(P,N)	P = NULL
#endif

///////////////////////////////////////////////////////////////////////////////
// loads a gls extension. #TODO: Robust name to path resolution.
GLS_EXTENSION_MODULE *gls::gls_extension_load (
												const char *name, 
												unsigned long req_options, 
												ExtensionHost *pHost
												) 
{
	// validate name
	size_t lenName = strlen(name);
	if (lenName == 0 || lenName > GLS_EXTENSION_MAX_PATH_LEN) {
		return NULL;
	}

	// make lib path; keep enough space for path expanding {
	// char libPath [GLS_EXTENSION_MAX_LIB_NAME_LEN + 50];
	char libPath [MAX_PATH];
#ifdef GLS_EXTENSION_LOAD_TREAT_NAME_AS_PATH
	strcpy (libPath, name);
#else
	sprintf (libPath, "extensions\\%s%s.%s", 
			EXT_MOD_NAME_PREFIX, name, EXT_MOD_EXT_NAME
			);
#endif
	// } make lib path

	// load the extension module	
#ifdef WIN32
	HMODULE hExtMod = EXT_LOAD(libPath);
#else
	void *hExtMod = NULL;
#endif

	if (hExtMod == NULL) {
		return NULL; // failed to load the module
	}

	// get extension module entry points
	pfn_gls_extension_initialize		pfn_ext_init;
	pfn_gls_extension_terminate			pfn_ext_term;
	pfn_gls_extension_get_interface		pfn_ext_get_int;	

	EXT_ENTRY_POINT (hExtMod, pfn_ext_init, gls_extension_initialize);
	EXT_ENTRY_POINT (hExtMod, pfn_ext_term, gls_extension_terminate);
	EXT_ENTRY_POINT (hExtMod, pfn_ext_get_int, gls_extension_get_interface);

	// check for missing exports
	if (!pfn_ext_init || !pfn_ext_term || !pfn_ext_get_int) {
		EXT_UNLOAD(hExtMod);
		return NULL;
	}

	// try to initialize the extension
	if (!pfn_ext_init (pHost)) {
		EXT_UNLOAD(hExtMod);
		return NULL; // failed to initialize the extension
	}

	// get the extension interface and query extension capabilities
	Extension *pExtension = pfn_ext_get_int ();
	if (pExtension == NULL) {
		EXT_UNLOAD(hExtMod);
		return NULL;
	}
	
	// get extension's interface version
	unsigned short ext_int_ver = pExtension->GetInterfaceVersion ();
	unsigned char ext_int_ver_maj, ext_int_ver_min;
	ext_int_ver_maj = GLS_VERSION_GET_MAJOR(ext_int_ver);
	ext_int_ver_min = GLS_VERSION_GET_MINOR(ext_int_ver);

	// check for minimum interface version; extension's interface version
	// must be atleast equal to the required interface version
	unsigned char req_int_ver_maj, req_int_ver_min;
	req_int_ver_maj = 0;
	req_int_ver_min = 1;
	if ( (ext_int_ver_maj < req_int_ver_maj) ||
		 (ext_int_ver_maj == req_int_ver_maj && ext_int_ver_min < req_int_ver_min)
		 ) {
		EXT_UNLOAD(hExtMod); // extension interface version is lower than required
		return NULL;
	}

	// query extension capabilities
	unsigned long capabilities = pExtension->GetCapabilities ();
	if ( (capabilities & req_options) != req_options ) {
		EXT_UNLOAD(hExtMod); // one or more capability not supported
		return NULL;
	}

	// query lib features
	GLS_EXTENSION_LIB_INFO libInfo;
	void *pLibInterface;
	if (req_options & GLS_EXTENSION_LIBRARY) {
		pExtension->GetLibInfo (&libInfo);
		pLibInterface = pExtension->GetLibInterface ();
		if (pLibInterface == NULL) {
			EXT_UNLOAD(hExtMod); // library interface not returned
			return NULL;
		}
	}

	// alloc a new extension module instance and return it
	GLS_EXTENSION_MODULE *pExtMod = new GLS_EXTENSION_MODULE ();
	memset (pExtMod, 0, sizeof(GLS_EXTENSION_MODULE));

	strcpy ( pExtMod->path, name );
	pExtMod->interfaceVersion = ext_int_ver;
	pExtMod->capabilities = capabilities;
	pExtMod->hModule = (void *)hExtMod;
	pExtMod->pExtInterface = pExtension;

	if (req_options & GLS_EXTENSION_LIBRARY) {
		memcpy (&pExtMod->libInfo, &libInfo, sizeof(GLS_EXTENSION_LIB_INFO));
		// pExtMod->pLibInterface = reinterpret_cast<_GLScriptExtLib *> (pLibInterface);
		pExtMod->pLibInterface = pLibInterface;
	}

	return pExtMod;
}
///////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
// unloads a gls extension
void gls::gls_extension_unload (GLS_EXTENSION_MODULE *pExtMod) {
	// Relese Library interface if requried
	if (pExtMod->pLibInterface != NULL) {
#ifdef WIN32
		reinterpret_cast<_GLScriptExtLib *>(pExtMod->pLibInterface)->Release ();
#endif
	}

	HMODULE hExtMod = (HMODULE)pExtMod->hModule;

	// pExtMod->pExtInterface has no reference management and need not be released.

	// tell the extension to terminate
	pfn_gls_extension_terminate pfn_ext_term;
	EXT_ENTRY_POINT (hExtMod, pfn_ext_term, gls_extension_terminate);
	pfn_ext_term ();

	// free the extension module
	EXT_UNLOAD(hExtMod);

	// delete module instance
	delete pExtMod;
}
///////////////////////////////////////////////////////////////////////////////
