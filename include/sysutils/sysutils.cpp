//
// sysutils.cpp  system utilities.
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
#include <sysutils/sysutils.h>
#include <string.h>
#include <tchar.h>
#include <stdio.h>

static const sys_tchar *sysutils_skip_white (const sys_tchar *path);

int sysutils_path_is_absolute (const sys_tchar *path) {
	/* skip leading white spaces */
	path = sysutils_skip_white (path);

	/* check for driver letter followed by a colon symbol */
	if ( _istalpha(*path) && *(path+1) == _tx(':') ) {
		return 1;
	}

	return 0; /* path is not absolute */
}

sys_tchar *sysutils_path_get_base (const sys_tchar *path, sys_tchar *base_path_buff, 
								   size_t max_buff_length) 
{
	/* skip leading white spaces */
	path = sysutils_skip_white (path);
	
	/* point to the end of path */
	const sys_tchar *ptr = path + sys_tstrlen(path);

	/* skip backwards until path separator (\) or drive separator (:) is found */
	while ( ptr > path && *ptr != SYSUTILS_PATH_SEPARATOR && *ptr != _tx(':') ) {
		--ptr;
	}

	*base_path_buff = _tx('\0');

	/* check if separator was found, d:\test */
	if ( *ptr == _tx(':') || *ptr == SYSUTILS_PATH_SEPARATOR ) {
		size_t length = ptr - path + 1;

		sys_tstrncpy (base_path_buff, path, length);
		base_path_buff[length] = _tx('\0');

		if (*ptr == _tx(':')) {
			base_path_buff [length] = SYSUTILS_PATH_SEPARATOR;
			base_path_buff [length + 1] = _tx('\0');
		}
	}

	return base_path_buff;
}

sys_tchar *sysutils_path_get_filename (const sys_tchar *path, sys_tchar *filename_buff, 
									   size_t max_buff_length) 
{
	/* skip leading white spaces */
	path = sysutils_skip_white (path);
	
	/* point to the end of path */
	const sys_tchar *ptr = path + sys_tstrlen(path);

	/* skip backwards until path separator (\) or drive separator (:) is found */
	while ( ptr > path && *ptr != SYSUTILS_PATH_SEPARATOR && *ptr != _tx(':') ) {
		--ptr;
	}

	*filename_buff = _tx('\0');

	/* check if separator was found, d:\test */
	if (*ptr == _tx(':') || *ptr == _tx('\\')) {
		++ptr;		
	}

	sys_tstrncpy (filename_buff, ptr, max_buff_length);
	filename_buff[max_buff_length - 1] = _tx('\0');	

	return filename_buff;
}

int sysutils_path_file_exists (const sys_tchar *path) {
	FILE *fp = _tfopen (path, _tx("rb"));
	if (fp) {
		fclose (fp);
		return 1;
	}
	return 0;
}

static const sys_tchar *sysutils_skip_white (const sys_tchar *path) {
	while ( *path && 
			(*path == _tx(' ') || (*path == _tx('\t')))
			) 
	{
		++path;
	}
	return path;
}
