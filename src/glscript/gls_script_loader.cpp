//
// gls_script_loader.cpp  glscript script loader interfaces and classes.
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
#include <glscript/gls_script_loader.h>
#include <io.h> // for _filelength()

// define getfileno for portability
#ifdef WIN32
#define getfileno(_H) _fileno(_H)
#else
#define getfileno(_H)
#endif

// define getfilelength for portability
#ifdef WIN32
#define getfilelength(_H) _filelength(_H)
#else
#define getfilelength(_H)
#endif

#if defined(DEBUG) || defineed(_DEBUG)
#define ASSERT assert
#else
#define ASSERT
#endif

using namespace gls;

// internal structures...
struct FILE_SOURCE_LOADER_RESULT : public ASYNCH_CALL_RESULT {
    sys_tchar path [260];
};

// prototypes of internal functions...

static sys_wchar *LoadFileScriptSourceSync (const sys_tchar *path);

#ifdef WIN32
static DWORD WINAPI LoadFileScriptSourceAsync (LPVOID param);
#endif

// ScriptFileSourceLoader implementation...

///////////////////////////////////////////////////////////////////////////////
//
sys_wchar *ScriptFileSourceLoader::LoadScriptSource (const sys_tchar *url) {
    if (!url) {
        return NULL;
    }
    return LoadFileScriptSourceSync (url);
}
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// ScriptFileSourceLoader:: LoadScriptSource
//
// Loads script source from a disk file
//
// url:         filesystem path of the script source.
// callback:    Callback to invoke when the loading of file completes.
// context:     Context for the source loader to be passed back to the callback.
//
// Returns true if successfuly, false otherwise.
//
bool ScriptFileSourceLoader::LoadScriptSource (const sys_tchar *url, const ASYNCH_CALLBACK callback,
                                                 void *context)
{
    // make sure we have all valid arguments. context may be NULL by default.
    if (!url || !callback) {
        return false; // invalid arguments provided
    }

    // initialize result for the file loader thread
    FILE_SOURCE_LOADER_RESULT *pResult;
    pResult = (FILE_SOURCE_LOADER_RESULT *) asynch_create_result (sizeof(FILE_SOURCE_LOADER_RESULT), 
                                                                        callback, context);
    if (pResult == NULL) {
        return false;
    }
    
    sys_tstrcpy (pResult->path, url);
    
#ifdef WIN32
    // Start the file loader thread
    HANDLE hThread = ::CreateThread (NULL, 
                                    0/*default stack size*/, 
                                    LoadFileScriptSourceAsync, 
                                    (LPVOID)pResult, 
                                    0/*creation flags*/, 
                                    NULL);
    if (hThread == NULL) {
        return false; // failed to start the background thread
    }
#else
    // #TODO: create thread on non Win32 paltforms
#endif

    // thread was successfully started that will return the script 
    // source using the callback
    return true;
}
///////////////////////////////////////////////////////////////////////////////

// internal functions...

///////////////////////////////////////////////////////////////////////////////
//
static sys_wchar *LoadFileScriptSourceSync (const sys_tchar *path) {
    ASSERT(path);

    // open the script file
    FILE *fp = ::_tfopen (path, _tx("rb"));
    if (fp == NULL) {
        return NULL;
    }

    // get file length
    long file_size = getfilelength ( getfileno(fp) );

    // file buffer 
    char *ascii_buffer;
    if (file_size == 0)  {
        ascii_buffer = new char [1];
    } else {
        // allocate buffer to read the file contents
        ascii_buffer = new char [file_size + 1];
    }
    if (ascii_buffer == NULL) {
        // failed to allocate memory for the file buffer
        fclose (fp);
        return NULL;
    }

    // read script file content into the ascii buffer
    if (file_size == 0)  {
        ascii_buffer [0] = '\0';
    } else {
        // read file contents
        fread (ascii_buffer, file_size, 1, fp);
        ascii_buffer [file_size] = '\0';
    }

    // close the file when done
    fclose (fp);

    // convert ascii script to wide string format
    wchar_t *wstr_buff = NULL;
    if (ascii_buffer) {
        // allocate buffer for wide string
        wstr_buff = new wchar_t [file_size + 1];
        if (wstr_buff == NULL) {
            delete ascii_buffer;
            return NULL;
        }
        // convert ascii to wide string
        size_t dummy;
        ::mbstowcs_s (&dummy, wstr_buff, file_size + 1, 
                        reinterpret_cast<const char *>(ascii_buffer), 
                        file_size);
        // delete the ascii buffer when done
        delete ascii_buffer;
    }

    // return the script source
    return wstr_buff;
}
///////////////////////////////////////////////////////////////////////////////


#ifdef WIN32
///////////////////////////////////////////////////////////////////////////////
//
static DWORD WINAPI LoadFileScriptSourceAsync (LPVOID param) {
    DWORD ret;
    // retrieve the asynch result
    FILE_SOURCE_LOADER_RESULT *asynch_result;
    asynch_result = reinterpret_cast<FILE_SOURCE_LOADER_RESULT*>(param);

    // load the script source using synchronous loader function
    wchar_t *wstr_buff = LoadFileScriptSourceSync (asynch_result->path);
    if (wstr_buff == NULL) {
        asynch_result->status = 0;
        asynch_result->data = NULL;
        ret = -1;
    } else {
        asynch_result->status = 1;
        asynch_result->data = wstr_buff;        
        ret = 0;
    }   
    
    // post the asynch result and return
    asynch_post_result (asynch_result);
    return ret;
}
///////////////////////////////////////////////////////////////////////////////
#endif
