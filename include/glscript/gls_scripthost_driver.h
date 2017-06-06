//
// gls_scripthost_driver.h  glscript script host driver.
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
#ifndef __GLSCRIPT_SCRIPTHOST_DRIVER_H__
#define __GLSCRIPT_SCRIPTHOST_DRIVER_H__

#include <glscript/gls_types.h>
#include <glscript/gls_obj.h>
#include <glscript/gls_scripthost.h>

namespace gls {

/** 
 * ScriptHostDriver class. Manages the underlying platform specific script host. 
 * This class abstracts the creation of the actual script host. 
 */
class ScriptHostDriver : public RefObject {
public:
    /** ctor */
    ScriptHostDriver ();

protected:
    /** protected dtor to disallow object creation on stack */
    ~ScriptHostDriver ();

public:
    /**
     * Returns the GLS script host interface. Note that ScriptHost pointer is valid till
     * ScriptHostDriver object is alive. You should not use the ScriptHost object after the 
     * ScriptHostDriver object is destroyed.
     */
    ScriptHost *GetScriptHost ();
    
protected:
    /** loads the script host */
    bool LoadScriptHost ();

    /** script host object */
    ScriptHost *m_pGLScriptHost;
};

}; // gls namespace

#endif /* !__GLSCRIPT_SCRIPTHOST_DRIVER_H__ */
