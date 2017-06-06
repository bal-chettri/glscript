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

/* analyzer.cpp     Implements the objparser::Analyzer base abstract class */

#include "stdafx.h"
#include "objparser.h"

using namespace objparser;

// Analyzer class definition...

Analyzer::Analyzer () {
    // Reset is virtual so don't call it here to do these
    m_count_vertices = 0;
    m_count_extra_vertices = 0;
    m_count_normals = 0;
    m_count_texture_vertices = 0;
    m_count_faces = 0;  
    m_required_memory = 0;
    m_error_code = 0;
}

Analyzer::~Analyzer () {
    Reset ();
}

void Analyzer::Reset () {
    m_count_vertices = 0;
    m_count_extra_vertices = 0;
    m_count_normals = 0;
    m_count_texture_vertices = 0;
    m_count_faces = 0;
    m_required_memory = 0;
    m_error_code = 0;

    index_hash.Reset ();

    m_external_references.clear ();
}

void Analyzer::CalculateRequiredMemory () {
    size_t count_elements = m_count_faces * 3;

    m_required_memory =
        (m_count_vertices + m_count_extra_vertices ) * sizeof(VERTEX_DATA) +
        (count_elements * sizeof(GLushort));
}
