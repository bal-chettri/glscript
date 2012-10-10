;-------------------------------------------------------------------------------
; glscript-0.8-beta.nsi
;
; NSIS script for glScript 0.8 beta release setup.
;
; Author: Bal Bahadur Chettri (balu.chettri@gmail.com)
;-------------------------------------------------------------------------------

; configuration

!define VERSION			'0.8-beta'
!define VERSION_TITLE		'0.8 - Beta'
!define BUILD			'release'
!define BUILD_TITLE		'Release'

;-------------------------------------------------------------------------------
; name of the program to install
Name "glScript"

; caption of the setup / installer
Caption "glScript-${VERSION_TITLE}-${BUILD_TITLE}"

; The file to write i.e. setup file
OutFile ".\..\packages\glscript-${VERSION}-${BUILD}.exe"

Icon "${NSISDIR}\Contrib\Graphics\Icons\modern-install-full.ico"

; set compression type
SetCompressor /SOLID lzma

; installation directory and registry key
InstallDir $PROGRAMFILES\glscript
InstallDirRegKey HKLM "Software\glscript" "Install_Dir"

;XPStyle on

RequestExecutionLevel admin
;-------------------------------------------------------------------------------


; header file includes

!include "MUI2.nsh"
!include "fileassoc.nsh"

;-------------------------------------------------------------------------------
; Pages
!define MUI_HEADERIMAGE
; !define MUI_HEADERIMAGE_BITMAP ".\header.bmp"
; !define MUI_WELCOMEFINISHPAGE_BITMAP ".\welcome.bmp"

!define MUI_WELCOMEPAGE_TITLE \
"Welcome to the glScript ${VERSION_TITLE} Setup Wizard"

!define MUI_WELCOMEPAGE_TEXT \
"This wizard will guide you through the installation of glScript ${VERSION_TITLE}. \
Before you continue, please make sure you have uninstalled the existing version of \
glScript from your system."

!define MUI_FINISHPAGE_RUN "$INSTDIR\glsrun.exe"

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ".\..\docs\README.txt"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

;uninstallation pages
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "English"
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; The stuff to install
;-------------------------------------------------------------------------------
Section "Main"

  SectionIn RO
  
  ; copy root files
  SetOutPath $INSTDIR
  File ".\..\docs\README.txt"
  File ".\..\docs\RELEASE-NOTES.txt"
  File ".\..\bin\glsrun.exe"

  ; copy extensions
  SetOutPath $INSTDIR\extensions
  File ".\..\bin\extensions\gls_glu.dll"
  File ".\..\bin\extensions\gls_obj.dll"
  File ".\..\bin\extensions\gls_img.dll"

  ; copy models
  SetOutPath $INSTDIR\models
  File ".\..\bin\models\shuttle.obj"
  File ".\..\bin\models\teapot.obj"
  File ".\..\bin\models\lamp.obj"
  File ".\..\bin\models\gourd.obj"
  File ".\..\bin\models\LICENSE.txt"

  ; copy textures
  SetOutPath $INSTDIR\textures
  File ".\..\bin\textures\logo.png"
  File ".\..\bin\textures\leaves.bmp"
  File ".\..\bin\textures\pastel.bmp"
  File ".\..\bin\textures\stones.bmp"

  ; copy include files
  SetOutPath $INSTDIR\include
  File ".\..\bin\include\opengl-constants.js"
  File ".\..\bin\include\opengl-constants.vbs"

  ; copy sample files
  SetOutPath $INSTDIR\samples\js
  File ".\..\bin\samples\js\rotating-cube-demo.gls"
  File ".\..\bin\samples\js\cross-line-demo.gls"
  File ".\..\bin\samples\js\events-demo.gls"
  File ".\..\bin\samples\js\hello-demo.gls"
  File ".\..\bin\samples\js\threed-demo.gls"
  File ".\..\bin\samples\js\rotating-sun-demo.gls"
  File ".\..\bin\samples\js\array-demo.gls"
  File ".\..\bin\samples\js\glu-demo.gls"
  File ".\..\bin\samples\js\obj-demo.gls"
  File ".\..\bin\samples\js\img-demo.gls"

  SetOutPath $INSTDIR\samples\vbs
  File ".\..\bin\samples\vbs\rotating-cube-demo.gls"
  File ".\..\bin\samples\vbs\cross-line-demo.gls"
  File ".\..\bin\samples\vbs\events-demo.gls"
  File ".\..\bin\samples\vbs\hello-demo.gls"
  File ".\..\bin\samples\vbs\threed-demo.gls"
  File ".\..\bin\samples\vbs\rotating-sun-demo.gls"
  File ".\..\bin\samples\vbs\array-demo.gls"
  File ".\..\bin\samples\vbs\glu-demo.gls"
  File ".\..\bin\samples\vbs\obj-demo.gls"
  File ".\..\bin\samples\vbs\img-demo.gls"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM "Software\glscript" "Install_Dir" "$INSTDIR"

  ; Do file extension associatation...
  ; !macro APP_ASSOCIATE_EX EXT FILECLASS DESCRIPTION ICON VERB DEFAULTVERB SHELLNEW COMMANDTEXT COMMAND

  !insertmacro APP_ASSOCIATE "gls" "glsrun.glscript" "glScript Files" \
  "$INSTDIR\glsrun.exe,0" "Open" "$INSTDIR\glsrun.exe $\"%1$\""

  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\glscript" \
		"DisplayName" \
		"glScript-${VERSION_TITLE}-${BUILD_TITLE}"

  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\glscript" \
		"UninstallString" \
		'"$INSTDIR\uninstall.exe"'

  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\glscript" \
		"NoModify" \
		1

  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\glscript" \
		"NoRepair" \
		1

  WriteUninstaller "uninstall.exe"
SectionEnd
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"
  SetOutPath $INSTDIR

  CreateDirectory "$SMPROGRAMS\glScript"

  CreateShortCut "$SMPROGRAMS\glScript\README.lnk" \
		 "$INSTDIR\README.txt" \
		 "" "$INSTDIR\README.txt"

  CreateShortCut "$SMPROGRAMS\glScript\RELEASE-NOTES.lnk" \
		 "$INSTDIR\RELEASE-NOTES.txt" \
		 "" "$INSTDIR\RELEASE-NOTES.txt"

  CreateShortCut "$SMPROGRAMS\glScript\glsrun.lnk" \
		 "$INSTDIR\glsrun.exe" \
		 "" \
		 "$INSTDIR\glsrun.exe" \
		 0 \
		 SW_SHOWNORMAL \
		 "" \
		 "glScript script runner tool"

  CreateShortCut "$SMPROGRAMS\glScript\Uninstall.lnk" \
		 "$INSTDIR\uninstall.exe" \
		 "" \
		 "$INSTDIR\uninstall.exe" \
		 0
SectionEnd
;-------------------------------------------------------------------------------


;-------------------------------------------------------------------------------
; Uninstaller
Section "Uninstall"

  ; Unregister file extension associations
  !insertmacro APP_UNASSOCIATE "gls" "glsrun.glscript"

  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\glscript"

  DeleteRegKey HKLM SOFTWARE\glscript

  ; Remove files and uninstaller
  Delete $INSTDIR\include\*.*
  Delete $INSTDIR\samples\js\*.*
  Delete $INSTDIR\samples\vbs\*.*
  Delete $INSTDIR\extensions\*.*
  Delete $INSTDIR\models\*.*
  Delete $INSTDIR\textures\*.*
  Delete $INSTDIR\README.txt
  Delete $INSTDIR\RELEASE-NOTES.txt
  Delete $INSTDIR\glsrun.exe
  Delete $INSTDIR\uninstall.exe

  ; Remove installation directories
  RMDir $INSTDIR\include
  RMDir $INSTDIR\samples\js
  RMDir $INSTDIR\samples\vbs
  RMDir $INSTDIR\samples
  RMDir $INSTDIR\extensions
  RMDir $INSTDIR\models
  RMDir $INSTDIR\textures

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\glScript\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\glScript"
  RMDir "$INSTDIR"
SectionEnd
;-------------------------------------------------------------------------------
