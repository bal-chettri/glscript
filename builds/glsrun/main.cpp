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
#include <asynch/asynch.h>
#include <glsrun/mainwnd.h>
#include <glsrun/glscript-run-config.h>
#include <sysutils/sysutils.h>
#include "resource.h"

// define extern vars...
DWORD _comObjCount, _comLockCount;
HINSTANCE _hAppInstance;
MainWnd _mainWindow;

void ProcessCommandLine ();

// WinMain. Application entry point. Here we do our application initialization and 
// create the main window
int APIENTRY WinMain (HINSTANCE hAppInstance, HINSTANCE, LPSTR, int) {
	_hAppInstance = hAppInstance;

	// initialze COM runtime library
	::CoInitialize (NULL);	
	
	// init common controls 6.0 for WinXP theme support
	::InitCommonControls ();

	// adjust the main window frame to fit the default GL view size
	RECT rtWndFrame = { 0, 0, DEF_GLS_VIEW_WIDTH, DEF_GLS_VIEW_HEIGHT };
	DWORD dwStyle = WS_OVERLAPPEDWINDOW;
	::AdjustWindowRect (&rtWndFrame, dwStyle, TRUE);

	// create the main application window
	if (!_mainWindow.Create (0, 0, rtWndFrame.right - rtWndFrame.left, 
								rtWndFrame.bottom - rtWndFrame.top, 
								GLSRUN_APP_TITLE)) 
	{
		// failed to create the main window
		return -1;
	}
	
	// center the window on desktop and show it
	_mainWindow.CenterWindow ();
	_mainWindow.Show ();
	::UpdateWindow (_mainWindow.GetHandle());

	// open file specified at command line 
	ProcessCommandLine ();

	// load accelerators
	HACCEL hAccel = ::LoadAccelerators (_hAppInstance, (LPCTSTR)IDR_GLSRUN);

	// main message loop for application. Here we get all messages from the message queue
	// and dispatch them to their callbacks. asynch messages are also handled and dispatched
	// using asynch_dispatch_result function.
	MSG msg;
	while (::GetMessage (&msg, NULL, 0, 0)) {

		// translate acclerator keys...
		if (!::TranslateAccelerator (msg.hwnd, hAccel, &msg)) {		

			// dispatch any asynch message arrived 
			if (msg.message == ASYNCH_CALL_MSG) {
				asynch_dispatch_result ((ASYNCH_CALL_RESULT *)msg.lParam);
				continue;
			}

			// dispatch general Win32 messages
			::TranslateMessage (&msg);
			::DispatchMessage (&msg);
		}
	}

	// terminate COM ad return to the OS
	::CoUninitialize ();

	return (int)msg.wParam;
}

// process command line
void ProcessCommandLine () {
	#define argc	::__argc
	#define argv	::__argv

	if (argc > 1) {
#ifdef _UNICODE
		size_t length = strlen(argv[1]);
		wchar_t *path = new wchar_t[length + 1];
		::mbstowcs (path, argv[1], length);
		path [length] = L'\0';
#else
		const char *path = argv[1];
#endif
		if (sysutils_path_file_exists(path)) {
			_mainWindow.OpenScript (path);
		}
#ifdef _UNICODE
		delete path;
#endif
	}
}
