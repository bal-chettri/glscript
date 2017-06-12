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
#ifndef __wingui_generic_dialog_h
  #define __wingui_generic_dialog_h

#include "window.h"

namespace wingui {

/* A base generic dialog window */
class Dialog : public Window 
{
public:
    /* ctors */
    
    // construct from resource id
    Dialog (int resourceId);

public:
    // operations
    BOOL IsModal () const {
        return m_flagModal;
    }

    // INT_PTR ShowModal (Window *pParentWindow = NULL);
    // #TODO: Move szTtile to ctor. 
    INT_PTR ShowModal (Window *pParentWindow = NULL, const char *szTitle = NULL);

    void ShowModalLess (Window *pParent = NULL);
    void CloseDialog (INT_PTR result = 0);
    virtual void CenterDialog();

    // Returns handle to the dialogbox control
    inline HWND GetControl (int controlId) {
        return GetDlgItem (GetHandle(), controlId);
    }
    
    void SetControlText (int id, LPCTSTR lpszText);
    void GetControlText (int id, LPTSTR lpszBuff, int maxLength);
    int GetControlInt (int id);
    float GetControlFloat (int id);

    wingui_tstring GetControlString(int id)
    {
        HWND hCtrl = GetControl(id);
        int length = GetWindowTextLength(hCtrl);
        if (length > 0)
        {
            TCHAR *pBuffer = new TCHAR[length + 1];
            GetDlgItemText(GetHandle(), id, pBuffer, length + 1);
            wingui_tstring str(pBuffer);
            delete [] pBuffer;
            return str;
        }
        return wingui_tstring(_T(""));
    }

protected:
    virtual INT_PTR HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam);

    virtual void OnCommand (int cmdId, int notifMsg);
    virtual INT_PTR OnInitDialog ();
    virtual void OnOkButton () { CloseDialog (IDOK); }
    virtual void OnCancelButton () { CloseDialog (IDCANCEL); }  

private:
    int m_resourceId;
    BOOL m_flagModal;
    Window *m_pParent;
};

}; // wingui namespace

#endif /* __wingui_generic_dialog_h */
