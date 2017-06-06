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

#include "generic_window.h"

/* A base generic dialog window */
class GenericDialog : public GenericWindow {
public:
    /* ctors */
    
    // construct from resource id
    GenericDialog (int resourceId);

public:
    // operations
    BOOL IsModal () const {
        return m_flagModal;
    }

    INT_PTR ShowModal (GenericWindow *pParentWindow = NULL);
    void ShowModalLess (GenericWindow *pParent = NULL);
    void CloseDialog (INT_PTR result = 0);
    void SetControlText (int id, LPCTSTR lpszText);
    void GetControlText (int id, LPTSTR lpszBuff, int maxLength);

protected:
    void CenterDialog ();

protected:
    virtual INT_PTR HandleDialogMessage (UINT msg, WPARAM wParam, LPARAM lParam);

    virtual void OnCommand (int cmdId);
    virtual INT_PTR OnInitDialog ();
    virtual void OnOkButton () { }
    virtual void OnCancelButton () { CloseDialog (IDCANCEL); }

private:
    int m_resourceId;
    BOOL m_flagModal;
    GenericWindow *m_pParent;
};

#endif /* __wingui_generic_dialog_h */
