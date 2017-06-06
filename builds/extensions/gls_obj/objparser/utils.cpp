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
#include "objparser.h"

using namespace objparser;

// Utils class definition...

/* skip wite space in single line */
const char *Utils::SkipWhite (const char *s) {
    while ( *s && (*s == ' ' || *s == '\t') ) {
        s++;
    }
    return s;
}

/* skip all blank lines */
const char *Utils::SkipBlankLines (const char *s) {
    while ( *s && 
            (*s == '\r' && *(s+1) == '\n') ||
            (*s == '\n' && *(s+1) == '\r') ||
            (*s == '\r') || 
            (*s == '\n')
            ) {
        ++s;
        if (*s == '\r' || *s == '\n') {
            ++s;
        }
    }
    return s;
}

/* skips a single line i.e. moves s to start of the next line */
const char *Utils::SkipLine (const char *s) {
    while ( *s ) {
        if (
            (*s == '\r' && *(s+1) == '\n') ||
            (*s == '\n' && *(s+1) == '\r') ||
            (*s == '\r') || 
            (*s == '\n')
            ) {

            ++s;
            if (*s == '\r' || *s == '\n') {
                ++s;
            }
            break;
        }
        ++s;
    }

    return s;
}

/* returns a flag to indicate if s points to end of line */
bool Utils::IsEndOfLine (const char *s) {
    if (
        (*s == '\r' && *(s+1) == '\n') ||
        (*s == '\n' && *(s+1) == '\r') ||
        (*s == '\r') || 
        (*s == '\n') ||
        (*s == '\0')
        ) {
        
        return true;
    }

    return false;
}

char *Utils::TrimComment (char *str) {
    char *s = str;
    while (*s && *s != '#') {
        ++s;
    }
    if (*s == '#') {
        *s = '\0';
    }
    return str;
}

/* parses a GLshort integer */
bool Utils::ParseInt (const char **ps, GLshort &value) {
    const char *s = *ps;
    int int_value;

    while ( ::isdigit(*s) ) {
        ++s;
    }

    size_t length = (s - *ps);
    if (length) {
        int_value = atoi (*ps);
        
        // #TODO bounds check on value for GLshort
        value = GLshort (int_value);

        *ps = s;
        return true;
    }

    return false;
}

// parses a vertex
bool Utils::ParseVertex (const char *s, VERTEX &v) {
    s = Utils::SkipWhite (s);

    int status = sscanf (s, "%f %f %f", &v.x, &v.y, &v.z);

    if (status == EOF || status != 3) {
        return false;
    }

    return true;
}

bool Utils::ParseVertex2D (const char *s, GLfloat &x, GLfloat &y) {
    s = Utils::SkipWhite (s);

    int status = sscanf (s, "%f %f", &x, &y);

    if (status == EOF || status != 2) {
        return false;
    }

    return true;
}
