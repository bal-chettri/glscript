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
#include <assert.h>
#include <commdlg.h>
#include <wingui/main_window.h>

extern HINSTANCE _hAppInstance;

MainWindow::MainWindow (int resourceId) {
	m_showToolbar = TRUE;
	m_showStatusbar = TRUE;

	m_resourceId = resourceId;

	m_isMainWnd = TRUE;
}

MainWindow::~MainWindow () {
}

/* operations */
void MainWindow::ShowToolbar (BOOL flag) {
	if (m_showToolbar != flag) {
		if (m_showToolbar = flag) {

		} else {

		}
	}
}

void MainWindow::ShowStatusbar (BOOL flag) {
	if (m_showStatusbar != flag) {
		if (m_showStatusbar = flag) {

		} else {

		}
	}
}

BOOL MainWindow::GetOpenFilePath (LPTSTR filePathBuffer, int maxFilePathBuffer, LPCTSTR lpstrFilter, 
									int filterIndex, LPCTSTR lpszDefExt)
{
	filePathBuffer[0] = _T('\0');

	OPENFILENAME openFileStruct;
	memset (&openFileStruct, 0, sizeof(openFileStruct));
	openFileStruct.lStructSize = sizeof(openFileStruct);
	openFileStruct.hwndOwner = GetHandle ();
	openFileStruct.hInstance = _hAppInstance;
	openFileStruct.lpstrFilter = lpstrFilter;
	openFileStruct.nFilterIndex = filterIndex;
	openFileStruct.lpstrFile = filePathBuffer;
	openFileStruct.nMaxFile = maxFilePathBuffer;
	openFileStruct.lpstrInitialDir = NULL;
	openFileStruct.lpstrTitle = NULL;
	openFileStruct.Flags = OFN_ENABLESIZING | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
	openFileStruct.lpstrDefExt = lpszDefExt;

	BOOL ret = ::GetOpenFileName (&openFileStruct);
	return ret;
}

BOOL MainWindow::GetSaveAsFilePath (LPTSTR filePathBuffer, int maxFilePathBuffer, LPCTSTR lpstrFilter, 
									int filterIndex, LPCTSTR lpszDefExt)
{
	OPENFILENAME openFileStruct;

	filePathBuffer[0] = _T('\0');

	memset (&openFileStruct, 0, sizeof(openFileStruct));
	openFileStruct.lStructSize = sizeof(openFileStruct);
	openFileStruct.hwndOwner = GetHandle ();
	openFileStruct.hInstance = _hAppInstance;
	openFileStruct.lpstrFilter = lpstrFilter;
	openFileStruct.nFilterIndex = filterIndex;
	openFileStruct.lpstrFile = filePathBuffer;
	openFileStruct.nMaxFile = maxFilePathBuffer;
	openFileStruct.lpstrInitialDir = NULL;
	openFileStruct.lpstrTitle = NULL;
	openFileStruct.Flags = OFN_ENABLESIZING | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
	openFileStruct.lpstrDefExt = lpszDefExt;

	return ::GetSaveFileName (&openFileStruct);
}

void MainWindow::UpdateUI () {
}

// overridables
void MainWindow::GetClassStyle (WNDCLASSEX &wcex) {
	// fill in defaults
	GenericWindow::GetClassStyle (wcex);

	wcex.lpszClassName = _T("_gls_main_window");
	wcex.lpszMenuName = MAKEINTRESOURCE(m_resourceId);
	wcex.hIcon = ::LoadIcon (_hAppInstance, MAKEINTRESOURCE(m_resourceId));
	wcex.hIconSm = ::LoadIcon (_hAppInstance, MAKEINTRESOURCE(m_resourceId));
}

BOOL MainWindow::CreateToolbar () {
	return TRUE;
}

// protected
BOOL MainWindow::CreateStatusbar () {
	return TRUE;
}

void MainWindow::OnCreate () {
	GenericWindow::OnCreate ();

	UpdateUI ();
}

void MainWindow::OnResize (int cx, int cy) {
	GenericWindow::OnResize (cx, cy);
}
