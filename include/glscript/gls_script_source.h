//
// gls_script_source.h  glscript script source.
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
#ifndef __GLSCRIPT_SCRIPT_SOURCE_H
 #define __GLSCRIPT_SCRIPT_SOURCE_H

#include <glscript/gls_types.h>
#include <glscript/gls_obj.h>
#include <sysport/sysport.h>

namespace gls {

/** ScriptSource class. Manages script source code. */
class ScriptSource : public RefObject {
public:
    /** 
     * ScriptSource constructor. 
     * @param strBaseURL base URL of the script's content source
     * @param strFileName File name of the script source
     * @param wstrCode Pointer to the script source code
     * @param codeLength length of the script source code in characters
     * @param autoFreeCode Flag to indicate the code should be freed automatically
     */
    ScriptSource (const sys_tchar *base_url, const sys_tchar *filename, 
                    const sys_wchar *code, size_t code_length,
                    bool auto_free_code = true);

    /** ScriptSource destructor. The destructor automatically frees the code
        if autoFreeCode paramter is true in the constructor otherwise the caller
        need to free it explicitly. */
    virtual ~ScriptSource ();

    // public methods...
public:

    /** Returns the base URL of the script's content source */
    const tstring &GetBaseURL () const {
        return m_str_base_url;
    }
    
    /** Returns the file name of the script source */
    const tstring &GetFileName () const {
        return m_str_file_name;
    }

    /** Returns the extension name of the script source's file */
    const tstring GetFileExtensionName () const;

    /** Returns the base pointer to the script source code */
    const sys_wchar *GetCode() {
        return m_wstr_code;
    }

    /** Returns the length of the script source code in characters */
    size_t GetLength () const {
        return m_code_length;
    }

    /** Returns the langauge of the script */
    const tstring &GetLanguage () const {
        return m_language;
    }

    /** Sets the lagnauge of the script */
    void SetLanguage (const sys_tchar *language) {
        m_language = language;
    }
    void SetLanguage (const tstring &language) {
        m_language = language;
    }

private:
    tstring     m_str_base_url;             /** base URL of script's content source */
    tstring     m_str_file_name;            /** file name of the script source */
    tstring     m_language;                 /** language of the script */
    const       sys_wchar *m_wstr_code;     /** base pointer the script source code */
    size_t      m_code_length;              /** length of the code in characters */
    bool        m_auto_free_code;           /** auto free flag */
};

}; // gls namesapce 

#endif /* __GLSCRIPT_SCRIPT_SOURCE_H */
