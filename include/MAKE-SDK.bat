@echo off

mkdir gls_sdk
mkdir gls_sdk\com
mkdir gls_sdk\glscript

copy com\*.* 				gls_sdk\com\

copy glscript\gls_types.h		gls_sdk\glscript\
copy glscript\gls_macros.h		gls_sdk\glscript\

copy glscript\activescript\gls_core.idl 		gls_sdk\glscript\
copy glscript\activescript\gls_core.h 			gls_sdk\glscript\
copy glscript\activescript\gls_core_i.c 		gls_sdk\glscript\
copy glscript\activescript\gls_core_p.c 		gls_sdk\glscript\

copy glscript\activescript\gls_ext_lib.idl 		gls_sdk\glscript\
copy glscript\activescript\gls_ext_lib.h 		gls_sdk\glscript\
copy glscript\activescript\gls_ext_lib_i.c 		gls_sdk\glscript\
copy glscript\activescript\gls_ext_lib_p.c 		gls_sdk\glscript\

copy glscript\gls_extension.h		gls_sdk\glscript\
pause
