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

/* analyzer-obj.cpp     Implements the objparser::AnalyzerOBJ class */

#include "stdafx.h"
#include "objparser.h"

using namespace objparser;

// AnalyzerOBJ class definition...

int AnalyzerOBJ::Analyze (FILE *fp) {
    // constants..
    const int LINE_BUFF_SIZE = 1024;

    // local vars...
    char line_buff [LINE_BUFF_SIZE + 1];
    const char *line;
    VERTEX vertex;
    TEXTURE_VERTEX tex_vertex;
    // max index groups per face that we can handle
    INDEX indices [MAX_INDICES_PER_FACE];
    
    // reset current state and rewind the file pointer to begin analysis
    Reset ();
    rewind (fp);

    // analyze each line in the OBJ file
    while (!feof (fp)) {
        // read next line from the file
        if ( !(line = fgets(line_buff, LINE_BUFF_SIZE, fp)) ) {
            break;
        }

        // trim comments and skip the leading white space
        Utils::TrimComment (line_buff);
        line = Utils::SkipWhite (line);

        // continue if we reached the end of line i.i. no more characters?
        if (Utils::IsEndOfLine (line)) {
            continue;
        }

        // check type of command and process it...

        if (strstr(line, "mtllib") == line) {
            // ignore mtlib
        }

        else if (strstr(line, "usemtl") == line) {
            // ignore usemtl
        }

        else if (*line == 'v' && *(line + 1) == 'n') {
            // analyze vn (vertex normal)
            line+= 2;
            if ( !Utils::ParseVertex(line, vertex) ) {
                m_error_code = objparserInvalidVertex;
                return m_error_code;
            } else {
                ++m_count_normals;
            }
        }
        
        else if (*line == 'v' && *(line + 1) == 't') {
            // analyze vt (vertex texture)
            line+= 2;
            if ( !Utils::ParseVertex2D(line, tex_vertex.x, tex_vertex.y) ) {
                m_error_code = objparserInvalidVertex;
                return m_error_code;
            } else {
                ++m_count_texture_vertices;
            }
        }
        
        else if (*line == 'v') {
            // analyze v (vertex)
            if ( !Utils::ParseVertex(++line, vertex) ) {
                m_error_code = objparserInvalidVertex;
                return m_error_code;
            } else {
                ++m_count_vertices;
            }
        }

        else if (*line == 'f') {
            // analyze f (face)
            unsigned count = 0;
            memset (indices, 0, sizeof(indices));
            if ( (m_error_code = ScanFaces(++line, count, indices)) != 0 ) {
                return m_error_code;
            } else {
                m_count_faces+= count;
            }
        }

        else if (*line == 'g') {
            // #TODO: analyze g
        }

        else if (*line == 's') {
            // #TODO: analyze smoothing group
        }

        else {
            // unknown command
            m_error_code = objparserInvalidKeyword;
            return m_error_code;
        }
    } // while

    // calculate the requierd memory size for the model if analysis
    // was successfull
    if (m_error_code == 0) {
        CalculateRequiredMemory ();
    }

    return m_error_code;
}

/**
 * Scans faces. A face definition can take any of the forms below:
 * 
 * v            vt,vn are missing
 * v/vt         vn is missing
 * v//vn        vt is missing
 * v/vt/vn      all present
 *
 * Face indices are returned in indices buffer. Since objparser supports only
 * triangular face, faces with indices more than 3 are converted to triangular face.
 * The buffer must be large enough to hold MAX_INDICES_PER_FACE index groups.
 * Error is returned, if more than MAX_INDICES_PER_FACE indices is encountered for a single 
 * face definition.
 */
int AnalyzerOBJ::ScanFaces (const char *s, unsigned &face_count, INDEX *indices) {
    unsigned index_count = 0; // INDEX count
    GLshort vi, ti, ni; // temp vars for one INDEX data i.e. v/vt/vn group

    face_count = 0;

    while ( !Utils::IsEndOfLine(s) ) {
        // skip the leadinjg white space
        s = Utils::SkipWhite(s);
        if (Utils::IsEndOfLine(s)) {
            break;
        }

        // assume all types of index data are missing. At least, v index must
        // be defined, however.
        vi = ti = ni = INDEX_MISSING;

        // scan for one INDEX i.e. v/vt/vn group...

        // scan v
        if (!Utils::ParseInt (&s, vi)) {
            return objparserInvalidFace;
        }

        // check for duplicate vertex index
        if (index_hash.IsSet (vi)) {
            vi = (m_count_vertices + m_count_extra_vertices) + 1;
            ++m_count_extra_vertices;
        }
        index_hash.Set (vi);

        if (index_count == MAX_INDICES_PER_FACE) {
            return objparserInvalidFace;
        }

        indices [index_count].vi = vi;
        if (*s == '/') {
            // scan vt
            if (Utils::ParseInt (&(++s), ti)) {
                indices [index_count].ti = ti;
            }
            if (*s == '/') {
                // scan vn
                if (Utils::ParseInt (&(++s), ni)) {
                    indices [index_count].ni = ni;
                }
            }
        }

        // If a white space or end of line is reached, increment the INDEX count
        // Note that MAX INDEX count is 3 for a triangular face.
        if (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') {          
            ++index_count;
        } else {
            // Unexpected character found after an INDEX group i.e. v/vt/vn data
            // Usually, end of line or space is expected
            return objparserInvalidFace;
        }
    } // while

    // make sure we have atleast 3 indices for a valid triangular face
    if (index_count < 3) {
        return objparserInvalidFace;
    }

    // calculate the number for faces required
    face_count = 1 + (index_count - 3);

    return 0; // ok!
}
