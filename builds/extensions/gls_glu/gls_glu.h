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
/** gls_glu.h */
#ifndef __GLS_GLU_H
 #define __GLS_GLU_H

#include <gls_sdk/glscript/gls_extension.h>
#include "gls_glu_ext.h"

class GLSExtensionLife {
public:
	GLSExtensionLife ();
	~GLSExtensionLife ();
};

typedef struct _GLS_EXT_DATA {
	gls::ExtensionHost *pExtensionHost;
	GLSExtensionImp *pExtension;
}GLS_EXT_DATA;

#endif /* __GLS_GLU_H */
