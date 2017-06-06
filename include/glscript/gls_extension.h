//
// gls_extension.h   glscript extension header. Contains types, enumerations, 
// interfaces and function prototypes used by gls extensions.
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
//   Version: 0.1
//
#ifndef __GLSCRIPT_EXTENSION_H__
#define __GLSCRIPT_EXTENSION_H__

#include <glscript/gls_types.h>

namespace gls {

//
// define GLS_EXTENSION_API, This allows us to statically link with extensions. For dynamic 
// extension modules, extension functions must be exported by names.
//
#if defined(GLS_PLUGIN_EXPORT) && defined(WIN32)
#define GLS_EXTENSION_API __declspec(dllexport)
#else
#define GLS_EXTENSION_API /* we're in core */
#endif

/* define constants */
#define GLS_EXTENSION_INTERFACE_VERSION             GLS_VERSION_MAKE_SHORT(0,1)
#define GLS_EXTENSION_HOST_INTERFACE_VERSION        GLS_VERSION_MAKE_SHORT(0,2)
#define GLS_EXTENSION_MAX_PATH_LEN                  260
#define GLS_EXTENSION_MAX_AUTHOR_NAME_LEN           255
#define GLS_EXTENSION_MAX_VENDOR_NAME_LEN           255
#define GLS_EXTENSION_MAX_LIB_NAME_LEN              32

/* define glScript extension capabilities */
#define GLS_EXTENSION_LIBRARY                       0x00000001L
#define GLS_EXTENSION_GUIPLUGIN                     0x00000002L
#define GLS_EXTENSION_RENDERER                      0x00000004L

/* define glScript event types */
#define GLS_EVENT_TYPE_TOOLKIT                      0x00000001L
#define GLS_EVENT_TYPE_PLAYER                       0x00000001L
#define GLS_EVENT_TYPE_SCRIPT                       0x00000001L
#define GLS_EVENT_TYPE_GUIPLUGIN                    0x00000001L

/* define glScript event codes */
#define GLS_EVENT_SCRIPT_LOAD                       0x00000001L
#define GLS_EVENT_SCRIPT_RUN                        0x00000002L
#define GLS_EVENT_SCRIPT_TERMINATE                  0x00000003L

/* Define function types */
typedef void (* GLS_TIMER_PROC) (void *p_context);
typedef void (* GLS_RENDER_PROC) (void *p_context);

/** GLS_ENVIRONMENT_TYPE enum. glScript environment types */
enum GLS_ENVIRONMENT_TYPE {
    GLS_ENVIRONMENT_TOOLKIT = 0,                    /** Toolkit environment */
    GLS_ENVIRONMENT_PLAYER = 1                      /** Player environment */
};

/** GLS_SCRIPT_INFO structure */
struct GLS_SCRIPT_INFO {
    /** flag indicates if the script has a valid path */
    bool has_path;

    /** source path of the script */
    char *path;

    /** extension of the script file name */
    char *extension;

    /** mime-type of the script */
    char *mime_type;

    /** flag indicates if the script is modified since loaded */
    bool is_dirty;
};


/** GLS_EVENT struct */
struct GLS_EVENT {
    /** event type */
    int type;
    /** event code */
    int code;
    /** event data 1 */
    void *data1;
    /** event data 2 */
    void *data2;
#ifdef WIN32
    /** Win32 window handle */
    HWND hWnd;
    /** Win32 msg */
    UINT msg;
    /** Win32 msg parameter 1 */
    WPARAM wParam;
    /** Win32 msg parameter 2 */
    LPARAM lParam;
#endif
};


/** GLS_EXTENSION_LIB_INFO struct */
struct GLS_EXTENSION_LIB_INFO {
    /** extension library name e.g. 'obj' for gls_obj. keep enough space for ext name. */
    char name [GLS_EXTENSION_MAX_LIB_NAME_LEN + 5];
    
    /** library version number  */
    unsigned short version;
};


/** 
 * Extension interface. Extension defines the interface for gls extension. All gls extensions 
 * must support and provide this interface. gls engine commnicates with the extension using this 
 * interface.
 */
class Extension {
    /* GLS EXTENSION INTERFACE ver 0.1 { */
public: 

    /** Returns version number of the interface */
    virtual unsigned short GetInterfaceVersion () = 0;
 
    /** Returns version number of the extension */
    virtual unsigned long GetExtensionVersion () = 0;
    
    /** Returns capabilities of the extension */
    virtual unsigned long GetCapabilities () = 0;

    /** Returns author's name */
    virtual const wchar_t *GetAuthorName () = 0;

    /** Returns vendor's name */
    virtual const wchar_t *GetVendorName () = 0;

    /** Creates and returns the plugin window */
    virtual void *CreatePluginWindow () = 0;

    /** 
     * Handles the glScript event 
     * @para p_event Pointer to the GLS_EVENT structure that contains the event details.
     */
    virtual long HandleEvent (GLS_EVENT *p_event) = 0;
    
    /** 
     * Returns information about library extension's library.
     * @param p_lib_info Pointer to GLS_EXTENSION_LIB_INFO structure that will contain
     * the lib information on return.
     */
    virtual void GetLibInfo (GLS_EXTENSION_LIB_INFO *p_lib_info) = 0;

    /** 
     * Returns lib or library interface of the library extension. 
     * @return If the extension supports GLS_EXTENSION_LIBRARY capability, returns the lib interface,
     * otherwise NULL. 
     * @remarks On Win platforms the lib interface is actually _GLScriptExtLib interface. Note that
     * _GLScriptExtLib is a COM interface and you must take care of releasing the interface when done
     * with it. 
     */
    virtual void *GetLibInterface () = 0;

    /** Return the timer callback procedure. @see GetRenderProc */
    virtual GLS_TIMER_PROC GetTimerProc () = 0;

    /** Returns the render callback procedure. @see GetTimerProc */
    virtual GLS_RENDER_PROC GetRenderProc () = 0;

    /* } GLS_EXTENSION_INTERFACE ver 0.1 */
}; /* Extension */


/* 
 * GLS_EXTENSION_MODULE structure. Extension Module structure contains details of the loaded
 * extension. 
 */
struct GLS_EXTENSION_MODULE {
    /** full path of the extension */
    char path [GLS_EXTENSION_MAX_PATH_LEN + 1];

    /** interface version number */
    unsigned short interfaceVersion;
    
    /** capability bitmask of the extension */
    unsigned long capabilities;

    /** OS specific handle to the extension module */
    void *hModule;

    /** extension interface */
    Extension *pExtInterface;

    /** extension's lib info */
    GLS_EXTENSION_LIB_INFO libInfo;

    /** extension's lib interface */
    void *pLibInterface;
};


/** 
 * ExtensionHost interface. ExtensionHost defines the the interface for extension's host.
 * gls Extensions can use this interface to communicate with the host and perform various
 * operations like requesting environment specific information, version details and loading 
 * other extensions.
 */ 
class ExtensionHost {
    /* GLS EXTENSION HOST INTERFACE ver 0.1 { */
public:
    /** Returns version number of the interface */
    virtual unsigned short GetInterfaceVersion () = 0;

    /** Returns environment type in which the extension is loaded */
    virtual GLS_ENVIRONMENT_TYPE GetEnvironmentType (void) = 0;

    /** Returns the toolkit's version */
    virtual unsigned long GetToolkitVersion () = 0;

    /** Returns the player's version */
    virtual unsigned long GetPlayerVersion () = 0;

    /** 
     * Returns information about the active / running script 
     * @param p_out_script_info Pointer to GLS_SCRIPT_INFO structure where the 
     * details of running script is returned.
     */
    virtual bool GetScriptInfo (GLS_SCRIPT_INFO *p_out_script_info) = 0;

    /** 
     * Loads an extension.
     * @param path Path or name of the extension is load
     * @param load_options Bitmask of extension loading options
     */
    virtual Extension *LoadExtension (const char *path, unsigned long load_options) = 0;

    /** 
     * LoadLibraryExtension () method. Loads a library extension.
     * @param path Path or name of library extension to load
     * @return On success, returns lib interface of the library extension, otherwise NULL. 
     * @remarks On Windows, the return value is _GLScriptExtLib interface. The return value, 
     * if not NULL, may be casted to _GLScriptExtLib * for use. Note that _GLScriptExtLib is a 
     * COM interface so you must take care of relesing the interface when done with it.
     */
    virtual void *LoadLibraryExtension (const char *path) = 0;

    /** 
     * Hook timer callback procedure
     * @param p_timer_proc Pointer the the timer procedure callback to hook
     * @param pContext Pointer to contextual data that will be passed back to the 
     *        timer procedure callback
     */
    virtual GLS_TIMER_PROC HookTimerProc (GLS_TIMER_PROC p_timer_proc, void *pContext) = 0;

    /** 
     * Hooks render callback procedure 
     * @param p_render_proc Pointer the the render procedure callback to hook
     * @param pContext Pointer to contextual data that will be passed back to the 
     *        render procedure callback
     */
    virtual GLS_RENDER_PROC HookRenderProc (GLS_RENDER_PROC p_render_proc, void *pContext) = 0;

    /* } GLS EXTENSION HOST INTERFACE ver 0.1 */

    /* GLS EXTENSION HOST INTERFACE ver 0.2 { */

    /**
     * Returns the host defined object
     * @param name Name of the object to access.
     * @return On Win32 platforms, returned value is an IDispatch interface of the object.
     *         The interface must be released after use.
     */
    virtual void *GetHostObject (const char *name) = 0;

    /**
     * Returns a base pointer to the arrays's internal data elements.
     * @param pTypedArray gls typed array object for which to access the internal raw data.
     *        On Win32 platforms, this must be the _GLScript_Array interface returned by 
     *        one of the array creation methods of gls object.
     * @remarks The returned pointer to array's raw data is only valid till the array object
     *          exists.
     */
    virtual void *GetArrayRawData (void *pTypedArray) = 0;

    /* } GLS EXTENSION HOST INTERFACE ver 0.2 */
}; /* ExtensionHost */


/************************************ GLS extension APIs **********************************/

/** 
 * gls_extension_load function (). gls_extension_load loads an extension with spcefied name and load
 * options.
 * @param name Name of the extension (for e.g. 'obj' for 'gls_obj' extension) or path (relative or absolute)
 * @param load_options Requried options or capabilities of the extension
 * @param pHost Extension Host interface
 * @return Returns a pointer to the extension module instance if successfuly, otherwise NULL.
 */
GLS_EXTENSION_MODULE *gls_extension_load (const char *name, unsigned long load_options, 
                                          ExtensionHost *pHost);

/**
 * gls_extension_unload () function. Unloads a gls extension module loaded with gls_extension_load API. 
 * @param pExtMod Pinter to the extension module instance to unload.
 */
void gls_extension_unload (GLS_EXTENSION_MODULE *pExtMod);

}; // gls namesapce

/**************************** GLS Extension Export Functions *****************************/

/* These functions must be exported by gls extensions. */

/** 
 * gls_extension_initialize () function. gls_extension_initialize function is called to initialize the 
 * extension. gls engine calls this function after loading the extension passing it a pointer to the
 * extension host.
 * @param pExtensionHost The extension host interface. The extension can save the host interface for
 * later use to communicate with the host.
 * @return Returns true if successful, otherwise false. If initialization succeeds, your extension should
 * return a true value, otherwise false. In case of failure, you should also perform neccessary cleanup
 * before returning from this function.
 * @remarks Note: This function can be called multiple times for different threads. For extensions to be
 * thread safe, you must initialize thread specific data in this function and save it in your TLS (Thread
 * Local Storage). For a single thread, this function will be called only once. 
 */
GLS_EXTENSION_API bool GLS_API_CALL gls_extension_initialize (gls::ExtensionHost *pExtensionHost);

/** 
 * gls_extension_get_interface () function. gls_extension_get_interface function is called to
 * get the extension's interface. This function should alwasy return the highest version of the 
 * interface.
 * @return Returns the extension interface. This function should always return the highest version
 * of Extension interface. NULL return value will cause the extension to be terminated and unloaded.
 */
GLS_EXTENSION_API gls::Extension *GLS_API_CALL gls_extension_get_interface (void);

/** 
 * gls_extension_terminate () function. gls_extension_terminate function is called to terminate the
 * extension. This function is called before the extension is unloaded so it should perform cleanup
 * and free allocated resources.
 * @remarks Note that this function is never called if your extension fails to initialization i.e.
 * gls_extension_initialze returns false.
 */
GLS_EXTENSION_API void GLS_API_CALL gls_extension_terminate (void);

//////////////////////////// typedefs for GLS extension functions /////////////////////////////////

typedef bool (GLS_API_CALL *pfn_gls_extension_initialize) (gls::ExtensionHost *pExtensionHost);
typedef gls::Extension * (GLS_API_CALL *pfn_gls_extension_get_interface) (void);
typedef void (GLS_API_CALL *pfn_gls_extension_terminate) (void);

#endif /* __GLSCRIPT_EXTENSION_H__ */
