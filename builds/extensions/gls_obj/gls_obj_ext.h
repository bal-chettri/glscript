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
/** gls_obj_ext.h */
#ifndef __GLS_OBJ_EXT_H
 #define __GLS_OBJ_EXT_H

#include <gls_sdk/glscript/gls_extension.h>

class GLSExtensionImp : public gls::Extension {
	gls::ExtensionHost *m_pHost;

public:
	GLSExtensionImp (gls::ExtensionHost *pHost) {
		m_pHost = pHost;
	}

	/* GLS_EXTENSION_INTERFACE ver 0.1 { */

	/* get version number of the interface */
	unsigned short GetInterfaceVersion ();
 
	/* get full version number of the extension */
	unsigned long GetExtensionVersion ();
	
	/* get capabilities of the extension */
	unsigned long GetCapabilities (void);

	/* get the author's name */
	const wchar_t *GetAuthorName (void);

	/* get vendor's name */
	const wchar_t *GetVendorName (void);

	/* create the plugin window */
	void *CreatePluginWindow (void);

	/* handle the glScript event */
	long HandleEvent (gls::GLS_EVENT *p_event);
	
	/* get extension library info */
	void GetLibInfo (gls::GLS_EXTENSION_LIB_INFO *p_lib_info);

	/* get interface to the extension library. In Win platforms this should return 
	_GLScriptExtLib interface for the library. */
	void *GetLibInterface ();

	/** Return the timer callback procedure. @see GetRenderProc */
	virtual gls::GLS_TIMER_PROC GetTimerProc ();

	/** Returns the render callback procedure. @see GetTimerProc */
	virtual gls::GLS_RENDER_PROC GetRenderProc ();

	/* } GLS_EXTENSION_INTERFACE ver 0.1 */
};

#endif /* __GLS_OBJ_EXT_H */
