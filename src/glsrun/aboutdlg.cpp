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

#include <shellapi.h>

#include <glscript/gls_types.h>
#include <glsrun/aboutdlg.h>
#include <glsrun/glscript-run-config.h>

#include "../../builds/glsrun/resource.h"

// WebAPIFactory
class WebAPIFactory {
public:
    static LPCTSTR GetSupportPageURL ( LPTSTR lpszBuff );
    static LPCTSTR GetUpdatesPageURL ( LPTSTR lpszBuff );
    static LPCTSTR GetSharePageURL ( LPTSTR lpszBuff );
};

LPCTSTR WebAPIFactory::GetSupportPageURL ( LPTSTR lpszBuff ) {
    lstrcpy (lpszBuff, WEBSITE_URL_BASE);
    ::_tcscat (lpszBuff, _T("v=synopsis"));
    
    return lpszBuff;
}

LPCTSTR WebAPIFactory::GetUpdatesPageURL ( LPTSTR lpszBuff ) {
    // TCHAR lpszFilePath [MAX_PATH];
    TCHAR verBuff[100];

    // get product verion number
    ::_stprintf (verBuff, 
        _T("client_ver_maj=%d&client_ver_min=%d&client_ver_rev=%d&client_ver_build=%d"), 
        GLSRUN_APP_VER_MAJ, GLSRUN_APP_VER_MIN, GLSRUN_APP_VER_REV, GLSRUN_APP_VER_BUILD
        );

    size_t len = lstrlen (verBuff);

    lstrcpy (lpszBuff, WEBSITE_URL_BASE);   
    ::_tcscat (lpszBuff, _T("v=download&show_updates=1&"));
    ::_tcscat (lpszBuff, verBuff);

    return lpszBuff;
}

LPCTSTR WebAPIFactory::GetSharePageURL ( LPTSTR lpszBuff ) {
    lstrcpy (lpszBuff, WEBSITE_URL_BASE);
    ::_tcscat (lpszBuff, _T("v=share"));    

    return lpszBuff;
}
// WebAPIFactory

////////////////////////////////////////////////////////////////////////////

static LPCTSTR unobfuscate (LPCTSTR lpsz_obfuscated, LPTSTR buff);

AboutDialog::AboutDialog () : wingui::Dialog(IDD_ABOUT)
{
}

INT_PTR AboutDialog::OnInitDialog () {
    TCHAR strbuff[255]; 
    tstring strTemp;

    // title
    static const TCHAR _title [] = GLSRUN_ABOUT_TITLE;
    LPCTSTR title = unobfuscate (_title, strbuff);
    ::SetDlgItemText ( GetHandle(), IDC_ABOUT_TITLE, title );

    // title bar
    strTemp = _T("About ");
    strTemp+= title;
    ::SetWindowText ( GetHandle(), strTemp.c_str() );

    // version string
    static const TCHAR _strver [] = GLSRUN_APP_VER_STRING;  
    LPCTSTR strver = unobfuscate (_strver, strbuff);
    strTemp = _T("Version ");
    strTemp+= strver;
    ::SetDlgItemText ( GetHandle(), IDC_ABOUT_VERSION, strTemp.c_str() );
    
    // dev name
    static const TCHAR _dev [] = GLSRUN_DEV_NAME;
    LPCTSTR dev = unobfuscate (_dev, strbuff);
    strTemp = _T("Developed by - ");
    strTemp+= dev;
    ::SetDlgItemText ( GetHandle(), IDC_ABOUT_DEVELOPER, strTemp.c_str() );

    // desc
    static const TCHAR _desc [] = GLSRUN_ABOUT_DESC;
    LPCTSTR desc = unobfuscate (_desc, strbuff);
    ::SetDlgItemText ( GetHandle(), IDC_ABOUT_DESC, desc );
    
    return wingui::Dialog::OnInitDialog ();
}

void AboutDialog::OnCommand (int cmdId, int notifMsg) {
    TCHAR urlBuff [512];    

    switch ( cmdId ) {
    case IDOK:
        CloseDialog (IDOK);
        break;

    case IDC_ABOUT_SUPPORT_WEBSITE:
        OpenURL ( WebAPIFactory::GetSupportPageURL(urlBuff) );
        break;

    case IDC_ABOUT_SHARE_APP:
        OpenURL ( WebAPIFactory::GetSharePageURL(urlBuff) );
        break;

    case IDC_ABOUT_CHECK_FOR_UPDATES:
        OpenURL ( WebAPIFactory::GetUpdatesPageURL(urlBuff) );
        break;

    default:
        wingui::Dialog::OnCommand (cmdId, notifMsg);
    }
}

void AboutDialog::OpenURL (LPCTSTR lpszUrl) {
    ::ShellExecute (NULL, _T("open"), lpszUrl, NULL, NULL, SW_SHOW);
}


static LPCTSTR unobfuscate (LPCTSTR lpsz_obfuscated, LPTSTR buff) {
    const TCHAR *ptr = lpsz_obfuscated;
    LPCTSTR ret = buff;
    while (*ptr) {
        *buff = *ptr ^ GLSRUN_APP_OBFUSCATOR_KEY;
        ++buff;
        ++ptr;
    }
    *buff = _T('\0');
    return ret;
}
