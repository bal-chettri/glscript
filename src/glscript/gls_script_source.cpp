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
#include <glscript/gls_script_source.h>

using namespace gls;

// ScriptSource class definition...

///////////////////////////////////////////////////////////////////////////////
//
ScriptSource::ScriptSource ( const sys_tchar *base_url, 
                                const sys_tchar *filename, 
                                const sys_wchar *code, size_t code_length,
                                bool auto_free_code /*= true*/ ) 
: m_str_base_url(base_url),
  m_str_file_name(filename),
  m_wstr_code(code),
  m_code_length(code_length),
  m_auto_free_code(auto_free_code),
  m_language(_tx(""))
{ }
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
ScriptSource::~ScriptSource () {
    if (m_auto_free_code) {
        delete m_wstr_code;
    }
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
const tstring ScriptSource::GetFileExtensionName () const {
    // check for the script file extension
    size_t npos = m_str_file_name.find (_tx("."));
    if (npos < 0) {
        return tstring(_tx(""));
    }

    const tstring ret = m_str_file_name.substr (npos + 1);  
    return ret;
}
///////////////////////////////////////////////////////////////////////////////
