//
// gls_activescript_ext_host.h  glscript extension host implementation class.
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
#ifndef __GLSCRIPT_ACTIVESCRIPT_EXT_HOST_H__
#define __GLSCRIPT_ACTIVESCRIPT_EXT_HOST_H__

// prevent direct inclusion of this header file.
#ifndef __GLSCRIPT_ACTIVESCRIPT_HOST_H__
#error "Do not include this header directly. Include gls_activescript_host.h instead."
#endif

// GLScript_ExtensionHost class. ActiveScript implementation of the ExtensionHost interface.
class GLScript_ExtensionHost : public gls::ExtensionHost {
public:
	GLScript_ExtensionHost (GLScriptHost_Win32 *pParent);
	~GLScript_ExtensionHost ();

public:
	/* GLExtensionHost implementation 0.1 */
	unsigned short GetInterfaceVersion ();
	gls::GLS_ENVIRONMENT_TYPE GetEnvironmentType (void);
	unsigned long GetToolkitVersion ();
	unsigned long GetPlayerVersion ();
	bool GetScriptInfo (gls::GLS_SCRIPT_INFO *p_out_script_info);
	gls::Extension * LoadExtension (const char *path, unsigned long load_options);
	void *LoadLibraryExtension (const char *path);
	gls::GLS_TIMER_PROC HookTimerProc (gls::GLS_TIMER_PROC p_timer_proc, void *pContext);
	gls::GLS_RENDER_PROC HookRenderProc (gls::GLS_RENDER_PROC p_render_proc, void *pContext);
	/* GLExtensionHost implementation 0.1 */

	/* GLExtensionHost implementation 0.2 */
	void *GetHostObject (const char *name);
	void *GetArrayRawData (void *pTypedArray);
	/* GLExtensionHost implementation 0.2 */

public:
	// unloads all extensions
	void UnloadAllExtensions ();

	gls::GLS_RENDER_PROC GetHookedRenderProc (void **context) {
		*context = m_render_proc_context;
		return m_pfn_render_proc;
	}

	gls::GLS_EXTENSION_MODULE *LoadExtensionInternal (const char *name, unsigned long load_options);	
	gls::GLS_EXTENSION_MODULE *LookupExtension (const char *path);
	gls::GLS_EXTENSION_MODULE *LookupExtensionByLibName (const char *libname);

private:
	GLScriptHost_Win32 *			m_parent;
	gls::GLS_RENDER_PROC			m_pfn_render_proc;
	void *							m_render_proc_context;
	list<gls::GLS_EXTENSION_MODULE *> m_list_extensions_modules;
};

#endif /* __GLSCRIPT_ACTIVESCRIPT_EXT_HOST_H__ */
