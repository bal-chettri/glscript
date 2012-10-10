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

#include <glsrun/consolewnd.h>
#include <glsrun/mainwnd.h>

extern HINSTANCE _hAppInstance;
extern MainWnd _mainWindow;

// Internal constants...

#define CONSOLEWND_MAX_LINES						200
#define CONSOLEWND_MESSAGE_COLOR					RGB(0,0,0)
#define CONSOLEWND_WARNING_COLOR					RGB(200,100,0)
#define CONSOLEWND_ERROR_COLOR						RGB(200,0,0)

// Define Context menu item IDs
#define TEXTEDIT_CONTEXT_MENU_ITEM_CUT				0x5000
#define TEXTEDIT_CONTEXT_MENU_ITEM_COPY				0x5001
#define TEXTEDIT_CONTEXT_MENU_ITEM_PASTE			0x5002
#define TEXTEDIT_CONTEXT_MENU_ITEM_SEPARATOR		0x0000
#define TEXTEDIT_CONTEXT_MENU_ITEM_CLEAR			0x5003
#define TEXTEDIT_CONTEXT_MENU_ITEM_COPY_ALL			0x5004
#define TEXTEDIT_CONTEXT_MENU_ITEM_CLEAR_ALL		0x5005
#define TEXTEDIT_CONTEXT_MENU_ITEM_SELECTALL		0x5006

// Settings...

// Enable this to scroll the messages on conole window when it is full, which means
// the first line is deleted and new message is added to the bottom.
// Disabling this will cause the console window to be cleared when it is full.
#define CONSOLEWND_SCROLL_ON_FULL

// Enable this to add line numbers to the logged messages
// #define CONSOLEWND_ADD_LINE_NUM

// Enable this to add time stamp to the logged messages
#define CONSOLEWND_ADD_TIMESTAMP

// ConsoleWnd class definition...

// ctor
ConsoleWnd::ConsoleWnd () {
	// init members...
	m_lineCount = 0;

	m_hWndEdit = NULL;
	m_hContextMenu = NULL;
	m_prevEditWndProc = NULL;

	// create font for console edit window
	m_hFont.Create ( _T("Courier New"), 9 );
}

// dtor
ConsoleWnd::~ConsoleWnd () {
}

BOOL ConsoleWnd::Create () {
	return GenericWindow::Create (0, 0, 500, 200, _T("Console"));
}

// Log. General method to log of any type.
void ConsoleWnd::Log (LPCTSTR lpszText, LogType logType) {
	// clear the console window if max number of lines have already been 
	// outputted
	if (m_lineCount == CONSOLEWND_MAX_LINES) {
		Clear ();
	}

	// increment the line counter
	++m_lineCount;

#if defined(CONSOLEWND_ADD_LINE_NUM) || defined(CONSOLEWND_ADD_TIMESTAMP)
	TCHAR buff [255]; // buffer for line number and/or timestamp
#endif

#ifdef CONSOLEWND_ADD_LINE_NUM
	// format the line number to display
	::_stprintf (buff, _T("%u: "), m_lineCount);
	Output (buff);
#endif

#ifdef CONSOLEWND_ADD_TIMESTAMP
	// format the timestamp to display
	SYSTEMTIME sys_time;
	::GetSystemTime (&sys_time);	
	::_stprintf (buff, _T("%u:%u:%u "), sys_time.wHour, sys_time.wMinute, sys_time.wSecond);
	Output (buff);
#endif

	// position the cursor at the end of line and set text attributes for new log
	PositionCursorAtEnd ();
	SetOutputTextAttributes (logType);

	// output the new log
	Output (lpszText);
	OutputEnd ();

	// position the cursor at the end of line when new log is outputted. This
	// keeps the new log visible as they are outputted.
	PositionCursorAtEnd ();
}

// Clear. Clears the console.
void ConsoleWnd::Clear () {
	::SetWindowText ( m_hWndEdit, NULL );
	m_lineCount = 0;
}

// copies the selected text or whole to the system clipboard
void ConsoleWnd::CopyToClipboard (BOOL copyAll) {
	if (copyAll) {
		HGLOBAL hGlobalMemory;
		LPTSTR lpszTextToCopy;

		if (!::OpenClipboard ( NULL ))
			return;

		::EmptyClipboard ();

		int length = GetWindowTextLength (m_hWndEdit);
		size_t memSize = (length + 1) * sizeof(TCHAR);
		hGlobalMemory = GlobalAlloc (GMEM_MOVEABLE, memSize);
		if (!hGlobalMemory) {
			CloseClipboard ();
			return;
		}

		// get text
		lpszTextToCopy = (LPTSTR) GlobalLock (hGlobalMemory);
		GetWindowText ( m_hWndEdit, lpszTextToCopy, length + 1 );
		lpszTextToCopy [length] = _T('\0');
		GlobalUnlock (hGlobalMemory);

		#ifdef _UNICODE
			SetClipboardData (CF_UNICODETEXT, hGlobalMemory);
		#else
			SetClipboardData (CF_TEXT, hGlobalMemory);
		#endif		

		CloseClipboard ();
	} else {
		SendMessage (m_hWndEdit, WM_COPY, 0, 0);
	}
}

// SetOutputTextAttributes. Internal method to set output text attributes before logging.
void ConsoleWnd::SetOutputTextAttributes (LogType logType) {
	// #TODO: formatting requires rich text control
}

// Output. Internal method to append the text at current cursor position.
void ConsoleWnd::Output (LPCTSTR lpszText) {
	::SendMessage (m_hWndEdit, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM) lpszText);
}

// OutputEnd. Internal method to terminate the current message line and begin a new line.
void ConsoleWnd::OutputEnd () {
	Output (_T("\r\n"));
}

// ScrollMessages. Scrolls the messages deleting the first line.
void ConsoleWnd::ScrollMessages () {
}

// positions the cursor at the end of line
void ConsoleWnd::PositionCursorAtEnd () {
	int textLength = ::GetWindowTextLength (m_hWndEdit);
	::SendMessage (m_hWndEdit, EM_SETSEL, textLength, textLength);
}

void ConsoleWnd::SelectAll () {
	// position the cursor at the beginning
	int textLength = ::GetWindowTextLength (m_hWndEdit);
	::SendMessage (m_hWndEdit, EM_SETSEL, 0, textLength);
}

// overrides...

// override to customize the window styles for the console window
void ConsoleWnd::GetCreateStyle (DWORD &dwStyle, DWORD &dwExStyle) {
	dwStyle = WS_OVERLAPPEDWINDOW;
	dwExStyle = WS_EX_PALETTEWINDOW;
}

// message handlers...

void ConsoleWnd::OnCreate () {
	RECT rt;
	GetClientRect(rt);

	// create and initialize the context menu
	m_hContextMenu = ::CreatePopupMenu ();
	::AppendMenu (m_hContextMenu, MF_STRING, TEXTEDIT_CONTEXT_MENU_ITEM_SELECTALL, _T("Select &All"));
	::AppendMenu (m_hContextMenu, MF_SEPARATOR, TEXTEDIT_CONTEXT_MENU_ITEM_SEPARATOR, NULL);
	::AppendMenu (m_hContextMenu, MF_STRING, TEXTEDIT_CONTEXT_MENU_ITEM_COPY, _T("&Copy"));	
	::AppendMenu (m_hContextMenu, MF_STRING, TEXTEDIT_CONTEXT_MENU_ITEM_CLEAR, _T("C&lear"));

	// create the internal EDIT window for console text display
	m_hWndEdit = ::CreateWindowEx (0, _T("EDIT"), NULL, 
							WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL, 
							rt.left, rt.top, 
							rt.right - rt.left, 
							rt.bottom - rt.top, 
							GetHandle(), NULL, _hAppInstance, NULL);

	// subclass the edit window for processing key events and other filtering tasks
	SetWindowLongPtr (m_hWndEdit, GWLP_USERDATA, (LONG_PTR) this);

	m_prevEditWndProc = (WNDPROC) ::GetWindowLongPtr (m_hWndEdit, GWLP_WNDPROC);
	::SetWindowLongPtr (m_hWndEdit, GWLP_WNDPROC, (LONG_PTR) EditWindowProc);

	// set font for the edit window
	LPARAM lParam = MAKELPARAM (TRUE,0);
	::SendMessage (m_hWndEdit, WM_SETFONT, (WPARAM)(HFONT)m_hFont, lParam );
}

void ConsoleWnd::OnPreDestroy () {
	// restore the old window procedure for the edit window
	SetWindowLongPtr (m_hWndEdit, GWLP_USERDATA, (LONG_PTR) m_prevEditWndProc);

	// destroy the edit window
	::DestroyWindow (m_hWndEdit);
	m_hWndEdit = NULL;

	// destroy the context menu
	::DestroyMenu (m_hContextMenu);
}

void ConsoleWnd::OnResize (int cx, int cy) {
	::MoveWindow (m_hWndEdit, 0, 0, cx, cy, TRUE);
}

void ConsoleWnd::OnGotFocus () {
	SetFocus (m_hWndEdit);
}

void ConsoleWnd::OnClose (BOOL &cancel) {
	// hide the console window without destroying the handle. This keeps the 
	// messages alive in the window.
	cancel = TRUE;
	
	this->Hide ();
	
	// tell the main window to update its UI when the console window is closed.
	// For e.g. the main window will uncheck the View > Console menu item.
	_mainWindow.UpdateUI ();
}

void ConsoleWnd::OnCommand (int cmdId) {
	switch (cmdId)
	{
	case TEXTEDIT_CONTEXT_MENU_ITEM_COPY: // copy
		SendMessage (m_hWndEdit, WM_COPY, 0, 0);
		break;
	case TEXTEDIT_CONTEXT_MENU_ITEM_CLEAR: // clear
		Clear ();
		break;
	case TEXTEDIT_CONTEXT_MENU_ITEM_SELECTALL: // select all
		SelectAll ();
		break;
	}
}

/*static*/
LRESULT CALLBACK ConsoleWnd::EditWindowProc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ConsoleWnd *pConsoleWnd = (ConsoleWnd *)::GetWindowLongPtr (hWnd, GWLP_USERDATA);

	switch (msg) {	
	// prevent user from entering new characters in the EDIT window. 
	case WM_CHAR:
	case WM_PASTE:
	case WM_CUT:		
		break;		

	// handled messages
	case WM_CONTEXTMENU:
		{
			POINT pt;
			::GetCursorPos (&pt);
			::TrackPopupMenu (pConsoleWnd->m_hContextMenu, TPM_LEFTALIGN | TPM_TOPALIGN,
								pt.x, pt.y, 0, pConsoleWnd->GetHandle(), NULL);
		}
		break;

	// default messages
	case WM_COPY:
	default:
		// call the default window callback procedure for the EDIT window that we saved during 
		// hooking our own callback procedure to process other messages
		return ::CallWindowProc ( pConsoleWnd->m_prevEditWndProc, hWnd, msg, wParam, lParam );
	}

	return 0; // message was handled here.
}
