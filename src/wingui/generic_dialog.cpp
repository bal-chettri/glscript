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
#include <wingui/generic_dialog.h>

extern HINSTANCE _hAppInstance;

GenericDialog::GenericDialog (int resourceId) {
    m_resourceId = resourceId;
    m_flagModal = FALSE;
    m_pParent = NULL;

    GenericWindow::m_isDialog = TRUE;
}

INT_PTR GenericDialog::ShowModal (GenericWindow *pParent) {
    m_flagModal = TRUE;
    m_pParent = pParent;

    return ::DialogBoxParam (_hAppInstance, MAKEINTRESOURCE(m_resourceId),
                                pParent ? pParent->GetHandle() : NULL,
                                (DLGPROC)GenericWindow::_dlgProc, 
                                (LPARAM) this );    
}

void GenericDialog::ShowModalLess (GenericWindow *pParent)
{
    if (!m_hWnd) {
        m_flagModal = FALSE;
        m_pParent = pParent;
        ::CreateDialogParam ( _hAppInstance, MAKEINTRESOURCE(m_resourceId),
                                    pParent ? pParent->GetHandle() : NULL, 
                                    (DLGPROC)_dlgProc, (LPARAM) this );
    }
}

void GenericDialog::CloseDialog (INT_PTR result) {
    if (IsModal()) {
        ::EndDialog (m_hWnd, result);
    } else {
        ::DestroyWindow (m_hWnd);
    }
}

void GenericDialog::SetControlText (int id, LPCTSTR lpszText) {
    WINGUI_ASSERT (
        ::SetDlgItemText (m_hWnd, id, lpszText)
        );
}

void GenericDialog::GetControlText (int id, LPTSTR lpszBuff, int maxLength) {
    WINGUI_ASSERT (
        GetDlgItemText (m_hWnd, id, lpszBuff, maxLength)
        );
}

void GenericDialog::CenterDialog () {
    HWND m_hWndDlg = m_hWnd;
    HWND hWndParent = NULL;

    if (m_pParent) hWndParent = m_pParent->GetHandle();
    if (!hWndParent) hWndParent = ::GetDesktopWindow ();

    if (hWndParent) {
        RECT rectDlg, rectParent;
        ::GetWindowRect ( m_hWndDlg, &rectDlg );
        ::GetWindowRect ( hWndParent, &rectParent );

        POINT offset = {
            rectParent.left + (rectParent.right - rectParent.left) / 2 - (rectDlg.right - rectDlg.left) / 2,
            rectParent.top + (rectParent.bottom - rectParent.top) / 2 - (rectDlg.bottom - rectDlg.top) / 2
        };

        ::MoveWindow (m_hWndDlg, offset.x, offset.y, rectDlg.right - rectDlg.left,
                        rectDlg.bottom - rectDlg.top, 
                        IsWindowVisible(m_hWndDlg) );
    }
}

INT_PTR GenericDialog::HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_INITDIALOG:
        return OnInitDialog ();

    default:
        return GenericWindow::HandleDialogMessage (msg, wParam, lParam);
    }

    return TRUE;
}

/* message handlers */

void GenericDialog::OnCommand (int cmdId) {
    if (cmdId == IDOK)
        OnOkButton ();
    else if (cmdId == IDCANCEL)
        OnCancelButton ();
    else
        GenericWindow::OnCommand (cmdId);
}

INT_PTR GenericDialog::OnInitDialog () {
    // Set WS_EX_LAYERED on this window 
    /*SetWindowLong(m_hWnd, 
              GWL_EXSTYLE, 
              GetWindowLong(m_hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);

    // Make this window 70% alpha
    SetLayeredWindowAttributes(m_hWnd, 0, (255 * 50) / 100, LWA_ALPHA);
    */

    CenterDialog ();

    if (!IsModal () && !::IsWindowVisible(m_hWnd)) {
        ::ShowWindow (m_hWnd, SW_SHOW);
        ::UpdateWindow (m_hWnd);
    }

    return TRUE;
}
