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

// include necessary headers...
#include <assert.h>

#include <glscript/gls_script_preprocessor.h>
#include <glsrun/mainwnd.h>
#include <glsrun/aboutdlg.h>
#include <glsrun/glscript-run-config.h>
#include "../../builds/glsrun/resource.h"
#include <sysutils/sysutils.h>

extern HINSTANCE _hAppInstance;
using namespace gls;

////////////////////////////////////////////////////////////////////////////////

// FullScreenContainerWnd class definition...

BOOL FullScreenContainerWnd::Create () {
    int cx, cy;
    cx = ::GetSystemMetrics (SM_CXSCREEN);
    cy = ::GetSystemMetrics (SM_CYSCREEN);
    return Window::Create (0, 0, cx, cy, NULL);
}

void FullScreenContainerWnd::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
    dwStyle = WS_POPUP;
    dwExStyle = WS_EX_TOPMOST;
}

void FullScreenContainerWnd::OnKeyPress (int virt_key, int repeat_count) {
    if (virt_key == 27) {
        mainWnd.EnterFullScreenMode (FALSE);
    }
}

////////////////////////////////////////////////////////////////////////////////

// MainWnd class definition...

MainWnd::MainWnd () : MainWindow (IDR_GLSCRIPT), m_fullScreenContWnd(*this) {
    // Create the script host driver
    m_pScriptHostDriver = new ScriptHostDriver ();

    // create GL view
    m_pGLView = new GLView (m_pScriptHostDriver);

    m_scriptLoaded = FALSE;
    m_paused = FALSE;
    m_scriptPath = _T("");
    m_windowTitle = _T("");
}

MainWnd::~MainWnd () {
    delete m_pGLView;

    // Release the script host driver
    m_pScriptHostDriver->Release ();
}

void MainWnd::OpenScript (LPCTSTR lpszScriptPath) {
    // close the script first
    CloseScript ();

    // Set script directory path as current working directiory
    sys_tchar base_path [MAX_PATH];
    sysutils_path_get_base (lpszScriptPath, base_path, sizeof(base_path));
    ::SetCurrentDirectory (base_path);

    // Set new script path  
    m_scriptPath = lpszScriptPath;
    
    // update the UI
    UpdateUI ();

    // run the script now
    RunScript ();
}

void MainWnd::CloseScript () {
    m_scriptLoaded = FALSE;

    m_scriptPath = _T("");
    m_windowTitle = _T("");

    // unload the script from the script host
    m_pScriptHostDriver->GetScriptHost()->UnloadScript ();
}

bool MainWnd::RunScript () {
    // reset vars
    m_scriptLoaded = FALSE;
    m_windowTitle = _T(""); 

    // reset the GL view and redraw the blank scene
    m_pGLView->ResetView ();
    m_pGLView->RedrawView ();

    ScriptSource *pScriptSource;
    int ret;

    // preprocess the script source
    sys_tchar inc_path[MAX_PATH], base_inc_path[MAX_PATH];
    GetModuleFileName ( (HMODULE)_hAppInstance, inc_path, sizeof(inc_path)/sizeof(inc_path[0]) );
    sysutils_path_get_base (inc_path, base_inc_path, sizeof(base_inc_path)/sizeof(base_inc_path[0]) );
    _tcscat (base_inc_path, _tx("include\\"));

    std::vector<wingui_tstring> search_paths;
    search_paths.push_back (base_inc_path);
    pScriptSource = ScriptPreprocessor::PreprocessScript (m_scriptPath.c_str(), NULL, 
                                                            search_paths, ret);
    if (ret != kPrepErrorNone) {
        const sys_tchar *error_msg = ScriptPreprocessor::TranslateErrorCode (ret);
        ::MessageBox (GetHandle(), error_msg, GLSRUN_APP_TITLE, MB_ICONERROR);
        // preprocessing failed!
        return false;
    }
    
    // Load the preprocessed script source using the script host managed by the script host driver
    m_scriptLoaded = m_pScriptHostDriver->GetScriptHost()->SetScriptSource (pScriptSource);
    m_paused = false;

    pScriptSource->Release ();
    UpdateUI ();

    return m_scriptLoaded ? true : false;
}

void MainWnd::UpdateUI () {
    // update title bar text
    tstring title = _T("");
    title.reserve (255);

    // if (m_scriptLoaded) {
    if (m_scriptPath.length () > 0) {
        // if windowTitle has been set by the script, use it
        if (m_scriptLoaded && m_windowTitle.length() > 0) {
            title = m_windowTitle;
        } else {
            // set title from the script's file name and app name
            const TCHAR *path = m_scriptPath.c_str();
            TCHAR file_name [MAX_PATH];
            
            // split file name only for titlebar display
            sysutils_path_get_filename (path, file_name, sizeof(file_name) / sizeof(file_name[0]));
            title = file_name;

            title.append (_T(" - "));
            title.append (GLSRUN_APP_TITLE);
        }
    } else {
        // format title bar text just with the app name
        title = GLSRUN_APP_TITLE;
    }

    // update the title bar text
    SetTitleText ( title.c_str() );

    // update menu items...
    HMENU hMenu = ::GetMenu (GetHandle());

    ::EnableMenuItem (hMenu, ID_CONTROL_REPLAY, 
                        m_scriptLoaded ? MF_ENABLED : MF_DISABLED
                        );

    // update menu item captions
    if (m_paused) {
        ::ModifyMenu (hMenu, ID_CONTROL_PAUSE, MF_BYCOMMAND, ID_CONTROL_PAUSE, _T("Res&ume"));
    } else {
        ::ModifyMenu (hMenu, ID_CONTROL_PAUSE, MF_BYCOMMAND, ID_CONTROL_PAUSE, _T("P&ause"));   
    }
    
    ::EnableMenuItem (hMenu, ID_CONTROL_PAUSE, 
                        m_scriptLoaded ? MF_ENABLED : MF_DISABLED
                        );

    // update menu checked status
    UINT console_menu_checked;
    if (m_consoleWnd.GetHandle() == NULL || !::IsWindowVisible(m_consoleWnd.GetHandle()))
        console_menu_checked = MF_UNCHECKED;
    else
        console_menu_checked = MF_CHECKED;

    ::CheckMenuItem (GetMenu(GetHandle()), ID_VIEW_CONSOLE, console_menu_checked);
}

void MainWnd::EnterFullScreenMode (BOOL flag) {
    if (flag) {
        // create the full screen container window if requierd
        if (!m_fullScreenContWnd.IsValid()) {
            m_fullScreenContWnd.Create ();
        }

        // hide the main window
        Hide ();

        // add the GL view to the full screen container window and show it
        m_fullScreenContWnd.AddChild (m_pGLView);

        m_pGLView->CenterView (&m_fullScreenContWnd);
        m_fullScreenContWnd.Show ();
    } else {
        // Hide the full screen window
        m_fullScreenContWnd.Hide ();

        // add GL view back to the main window. This removes the GL view from 
        // the full screen container window.        
        AddChild (m_pGLView);
        m_pGLView->CenterView (this);
        
        // Reshow the main window
        Show ();
    }
}

// ToggleConsoleWindowView. Shows or hides the console window.
void MainWnd::ToggleConsoleWindowView () {
    bool console_wnd_visible;

    if (m_consoleWnd.GetHandle() == NULL || !::IsWindowVisible(m_consoleWnd.GetHandle()) ) {
        if (m_consoleWnd.GetHandle() == NULL) {
    
            m_consoleWnd.Create ();
        }
        m_consoleWnd.Show ();
#ifdef DEBUG
        m_consoleWnd.LogMessage (_T("test message"));
        m_consoleWnd.LogWarning (_T("test warning"));
        m_consoleWnd.LogError (_T("test error"));
#endif
        console_wnd_visible = true;
    } else {
        m_consoleWnd.Hide ();
        console_wnd_visible = false;
    }

    // update menu checked status
    CheckMenuItem (GetMenu(GetHandle()), ID_VIEW_CONSOLE, 
                    console_wnd_visible ? MF_CHECKED : MF_UNCHECKED
                    );
}

// message handlers...

void MainWnd::OnCreate () {
    MainWindow::OnCreate ();

    // enable as file drop target
    EnableDropTarget (TRUE);

    // create the open gl view
    m_pGLView->Create (0, 0, DEF_GLS_VIEW_WIDTH, DEF_GLS_VIEW_HEIGHT, this);
    AddChild (m_pGLView);
    m_pGLView->Show ();

    // get the script host for initialization
    ScriptHost *pScriptHost = m_pScriptHostDriver->GetScriptHost ();

    // set the window context
    GLSCRIPT_WINDOW_CONTEXT windowContext;
    windowContext.hdc = m_pGLView->GetCachedDC ();
    windowContext.hWnd = m_pGLView->GetHandle ();
    windowContext.hglrc = NULL;
    pScriptHost->SetWindowContext (&windowContext);

    // listen for script host events
    pScriptHost->SetEventListener (this);

    // do inital UI update
    UpdateUI();
}

void MainWnd::OnPreDestroy () {
    // close current script before we go off
    CloseScript ();

    // destroy the console window if required
    if (m_consoleWnd.IsValid())
        m_consoleWnd.Destroy ();

    // destroy the full screen container window if required
    if (m_fullScreenContWnd.IsValid())
        m_fullScreenContWnd.Destroy ();

    // call the base implementation so it can do its clanup
    MainWindow::OnPreDestroy ();
}

void MainWnd::OnResize (int cx, int cy) {
    // call the base implementation to it can dot its layout
    MainWindow::OnResize (cx, cy);

    // center the gl view if required
    if (m_pGLView->GetHandle() != NULL) {
        m_pGLView->CenterView (this);
    }
}

void MainWnd::OnGotFocus () {
    SetFocus (m_pGLView->GetHandle());
}

void MainWnd::OnDropFiles (HDROP hDrop) {
    const UINT QUERY_FILE_COUNT = 0xFFFFFFFF;

    // first, query for the number of files dropped
    UINT count_files_dropped = ::DragQueryFile (hDrop, QUERY_FILE_COUNT, NULL, 0);

    // can handle only one file at a time; show an error message if more than one file is 
    // dropped
    if (count_files_dropped > 1) {
        ::MessageBox (GetHandle(),
                     _T("Only one file can be dropped at a time."), GLSRUN_APP_TITLE, 
                     MB_ICONEXCLAMATION);
        return;
    }

    // query for the size of buffer requierd to store the file path
    UINT file_path_length = ::DragQueryFile (hDrop, 0, NULL, 0);

    file_path_length++; // for '\0' character

    // allocate buffer file file path
    TCHAR *file_path = new TCHAR [file_path_length];

    // retrieve the file path now
    ::DragQueryFile (hDrop, 0, file_path, file_path_length);

    // process the file now
    OpenScript (file_path);

    delete file_path;
}

// OnCommand. Handles command messages.
void MainWnd::OnCommand (int cmdId, int notifMsg) {
    switch (cmdId) {

    case ID_FILE_OPENSCRIPT:
        {
            TCHAR pathBuff[MAX_PATH];
            if (this->GetOpenFilePath (pathBuff, sizeof(pathBuff)/sizeof(pathBuff[0]), 
                                        GLSRUN_APP_CMNDLG_FILTERS, 1, GLSRUN_APP_CMNDLG_DEFEXT))
            {
                OpenScript (pathBuff);
            }
        }
        break;

    case ID_FILE_EXIT:
        this->Destroy ();
        break;

    // View 
    case ID_VIEW_CONSOLE:
        ToggleConsoleWindowView ();
        break;

    case ID_VIEW_FULLSCREEN:
        EnterFullScreenMode ();
        break;

    case ID_CONTROL_REPLAY:
        RunScript ();
        break;

    case ID_CONTROL_PAUSE:
        if (m_paused) {
            m_paused = !m_pScriptHostDriver->GetScriptHost()->ResumeRenderLoop ();
        } else {
            m_paused = m_pScriptHostDriver->GetScriptHost()->PauseRenderLoop ();            
        }
        this->UpdateUI ();
        break;

    case ID_HELP_ABOUT:
    {
        AboutDialog dlgAbout;
        dlgAbout.ShowModal (this);
    }
    break;

    default:
        MainWindow::OnCommand (cmdId, notifMsg);
    }
}

// GLScriptHostEvents implementation...

void MainWnd::ScriptHost_OnError (ScriptHost *pHost, const sys_tchar *errorMessage) {
    ::MessageBox (GetHandle(), errorMessage, GLSRUN_APP_TITLE, MB_ICONASTERISK);
}

void MainWnd::ScriptHost_OnChangeState (ScriptHost *pHost, GLSCRIPT_HOST_STATE from_state, 
                                        GLSCRIPT_HOST_STATE to_state) {
    if (from_state == kScriptHostStateReady && to_state == kScriptHostStateLoaded) {

        // Run the script in configuration phase 
        pHost->ExecuteScriptConfigurationPhase ();

        UpdateUI();

    } else if (to_state == kScriptHostStateConfigured) {
        
        // Run the script in render phase 
        pHost->ExecuteScriptRenderPhase ();

        UpdateUI();
    }   
}

void MainWnd::ScriptHost_OnConfigureWindow (const GLSCRIPT_WINDOW_CONFIG &config) {
    m_windowTitle = config.title;
        
    // hide the window before resizing it
    m_pGLView->Hide ();

    // Set new view port 
    m_pGLView->SetViewPort (config.vpx, config.vpy, config.vpcx, config.vpcy);

    m_pGLView->SetOrtho (config.ortho);

    // resize GL surface window based on configuration
    RECT rt;
    m_pGLView->GetClientRect (rt);

    if (rt.right == config.wincx && rt.bottom == config.wincy)
        m_pGLView->SetupGLView ((int)config.wincx, (int)config.wincy);
    else
        // ::MoveWindow (m_pGLView->GetHandle(), 0, 0, (int)config.wincx, (int)config.wincy, FALSE);    
        m_pGLView->Move (0, 0, (int)config.wincx, (int)config.wincy, false);
    
    // adjust the window rect to exactly fit the GL view
    GetWindowRect (rt);
    if ( (rt.right - rt.left) != config.wincx || (rt.bottom - rt.top) != config.wincy) {
        RECT rtWndFrame = { 0, 0, config.wincx, config.wincy };
        DWORD dwStyle = WS_OVERLAPPEDWINDOW;

        ::AdjustWindowRect (&rtWndFrame, dwStyle, TRUE);
        ::MoveWindow (GetHandle(), rt.left, rt.top, 
                        rtWndFrame.right - rtWndFrame.left, 
                        rtWndFrame.bottom - rtWndFrame.top, 
                        TRUE);
    }

    // show the GL view
    m_pGLView->CenterView (this);
    m_pGLView->Show ();
}

void MainWnd::ScriptHost_OnLogMessage (const sys_tchar *message, gls::GLSCRIPT_LOGTYPE log_type)
{
    if (m_consoleWnd.GetHandle() == NULL) {
        m_consoleWnd.Create ();
    }

    ConsoleWnd::LogType console_log_type;

    switch (log_type) {     
    case GLScriptLogTypeWarning:
        console_log_type = ConsoleWnd::logWarning;
        break;
    case GLScriptLogTypeError:
        console_log_type = ConsoleWnd::logError;
        break;

    /*case GLScriptLogTypeMessage:
        console_log_type = ConsoleWnd::logMessage;
        break;*/
    default:
        console_log_type = ConsoleWnd::logMessage;
    }

    m_consoleWnd.Log (message, console_log_type);
}

void MainWnd::ScriptHost_OnLogClear () {
    m_consoleWnd.Clear ();
}
