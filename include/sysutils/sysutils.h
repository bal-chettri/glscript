//
// sysutils.h  system utilities.
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
#ifndef __SYSUTILS_H
 #define __SYSUTILS_H

#include <sysport/sysport.h>

// define file path separator symbol
#if defined(WIN32)
 #define SYSUTILS_PATH_SEPARATOR                _tx('\\')
#elif defined(_LINUX_) || defined(_MACH_)
 #define SYSUTILS_PATH_SEPARATOR                _tx('/')
#else
 #define SYSUTILS_PATH_SEPARATOR                _tx('/')
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* sysutils path utility functions */

/**
 * sysutils_path_is_absolute ()
 * Checks if specified file system path is an absolute path.
 *
 * @param path path to check for absoluteness.
 *
 * @return 1 if path is absolute
 * @return 0 if path is relative
 *
 * @remarks Path is absolute if it begins with a drive letter, for e.g., d:a.js or d:\a.js
 * Otherwise, path is relative to current directory or directory path of some file.
 * For e.g., a.js, \b.js, .\c.js, ..\d.js are all relative paths. If a path is simply a filename
 * then it is relative to the current direcroy. If a path begins with a \ symbol then it is 
 * relative to the root directory of the current drive. A path beginning with .\ is relative
 * to the current directory and a path beginning with ..\ is relative to the parent of the 
 * current directory.
 */
int sysutils_path_is_absolute (const sys_tchar *path);

/**
 * sysutils_path_get_base ()
 * Returns the base path portion for specified path.
 * 
 * @param path absolute or relative path for which base path is returned
 * @param base_path_buff pointer to the base path buffer
 * @param max_buff_length maximum length of buffer in characters including space for 
 * null character
 */
sys_tchar *sysutils_path_get_base (const sys_tchar *path, sys_tchar *base_path_buff, 
                                   size_t max_buff_length);

/**
 * sysutils_path_get_filename ()
 * Returns the file name portion for specifed path.
 */
sys_tchar *sysutils_path_get_filename (const sys_tchar *path, sys_tchar *filename_buff, 
                                        size_t max_buff_length);


/**
 * sysutils_path_file_exists ()
 * Checks if the specified file exists on local file system or not.
 * @return 1 if path exists
 * @return 0 if path does not exists
 */
int sysutils_path_file_exists (const sys_tchar *path);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* __SYSUTILS_H */
