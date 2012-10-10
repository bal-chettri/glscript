//
// gls_script_loader.h  glscript script loader interfaces and classes.
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

#ifndef __GLSCRIPT_SCRIPT_LOADER_H__
#define __GLSCRIPT_SCRIPT_LOADER_H__

// include required headers..
#include <glscript/gls_obj.h>
#include <glscript/gls_types.h>
#include <asynch/asynch.h>
#include <sysport/sysport.h>

namespace gls {

/**
 * ScriptSourceLoader interface. Defines the interface for all script source loaders. 
 * The interface provides two versions of script source loading methods: synchronous and
 * asynchronous.
 */ 
class ScriptSourceLoader : public RefObject {
public:
	/** Load the script code from a source */
	virtual sys_wchar *LoadScriptSource (const sys_tchar *url) = 0;

	/** 
	 * Load the script code from a source asynchronously. 
	 * @param url URL of the source from which the script source is loaded
	 * @param callback Callback to invoke on completion of the task
	 * @param context Pointer to contextual data passed to the callback (may be NULL)
	 */
	virtual bool LoadScriptSource (const sys_tchar *url, const ASYNCH_CALLBACK callback, 
									void *context = NULL) = 0;
};

/** class ScriptFileSourceLoader. Script source loader that loads from a local file system. */
class ScriptFileSourceLoader : public ScriptSourceLoader {
public:
	sys_wchar *LoadScriptSource (const sys_tchar *url);

	bool LoadScriptSource (const sys_tchar *url, const ASYNCH_CALLBACK callback, 
							void *context = NULL);
};

/* class ScriptHTTPSourceLoader. Script source loader that loads from a HTTP URL. */
class ScriptHTTPSourceLoader : public ScriptSourceLoader {
public:
	virtual sys_wchar *LoadScriptSource (const sys_tchar *url) = 0;

	bool LoadScriptSource (const sys_tchar *url, const ASYNCH_CALLBACK callback, 
							void *context = NULL);
};

}; // gls namespace

#endif /* __GLSCRIPT_SCRIPT_LOADER_H__ */
