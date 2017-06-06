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
#include <tchar.h>
#include "gls_img_image.h"
#include "SOIL\soil.h"

GLS_IMG_Image::GLS_IMG_Image () {
    // m_bmp_width = m_bmp_height = 0;
    m_x = m_y = 0.0f;
    m_width = m_height = 1.0f;
    m_textid = -1;
    m_initialized = false;
}

GLS_IMG_Image::~GLS_IMG_Image () {
    if (m_initialized) {
        ::glDeleteTextures (1, &m_textid);
    }
}

HRESULT STDMETHODCALLTYPE GLS_IMG_Image::get_x (float *x) {
    *x = m_x;
    return NOERROR;
}
HRESULT STDMETHODCALLTYPE GLS_IMG_Image::put_x (float x) {
    m_x = x;
    SetupVertices ();
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLS_IMG_Image::get_y (float *y) {
    *y = m_y;
    return NOERROR;
}
HRESULT STDMETHODCALLTYPE GLS_IMG_Image::put_y (float y) {
    m_y = y;
    SetupVertices ();
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLS_IMG_Image::get_width (float *width) {
    *width = m_width;
    return NOERROR;
}
HRESULT STDMETHODCALLTYPE GLS_IMG_Image::put_width (float width) {
    m_width = width;
    SetupVertices ();
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLS_IMG_Image::get_height (float *height) {
    *height = m_height;
    return NOERROR;
}
HRESULT STDMETHODCALLTYPE GLS_IMG_Image::put_height (float height) {
    m_height = height;
    SetupVertices ();
    return NOERROR;
}

HRESULT STDMETHODCALLTYPE GLS_IMG_Image::render () {
    if (m_initialized) {
        glPushMatrix ();
            glTranslatef (m_x, m_y, 0.0f);

            glBindTexture ( GL_TEXTURE_2D, m_textid );

            // setup vertex array...
            glEnableClientState (GL_VERTEX_ARRAY);
            glEnableClientState (GL_TEXTURE_COORD_ARRAY);

            glVertexPointer (2, GL_FLOAT, 0, m_vertices);
            glTexCoordPointer (2, GL_FLOAT, 0, m_texture_vertices);

            glDrawArrays (GL_QUADS, 0, 4);

            // disable arrays...
            glDisableClientState (GL_TEXTURE_COORD_ARRAY);
            glDisableClientState (GL_VERTEX_ARRAY);
        glPopMatrix ();
    }

    return NOERROR;
}

// internal public methods...

#define BMP_SIG     (unsigned short)'MB'

bool GLS_IMG_Image::_Init (const char *lpsz_image_path) {
    // set bitmap size

    m_textid = SOIL_load_OGL_texture (
        lpsz_image_path,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | /*SOIL_FLAG_INVERT_Y |*/ SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    /* check for an error during the load process */
    if( 0 == m_textid ) {
        printf ( "SOIL loading error: '%s'\n", SOIL_last_result() );
        return false;
    }

    // m_bmp_width = (short)bmphdr.biWidth;
    // m_bmp_height = (short)bmphdr.biHeight;   
    // m_width = m_bmp_width;
    // m_height = m_bmp_height;
    
    // setup vertices array...
    SetupVertices ();
    SetupTextureVertices ();

    m_initialized = true;

    return true;
}

#if 0
bool GLS_IMG_Image::_Init (const char *lpsz_image_path) {
    // bitmap data  
    FILE *fp;
    BITMAPFILEHEADER hdr;
    BITMAPINFO bmpinfo;
    BITMAPINFOHEADER &bmphdr = bmpinfo.bmiHeader;

    // open texture file
    fp = fopen ( lpsz_image_path, "rb" );
    if (fp == NULL) {
        return false;
    }

    // check magic bytes
    fread (&hdr, sizeof(hdr), 1, fp);
    if (hdr.bfType != BMP_SIG) {
        fclose (fp);
        return false;
    }

    // must be 24 bits RGB
    fread (&bmpinfo, sizeof(bmpinfo), 1, fp);
    if (bmphdr.biBitCount != 24) {
        fclose (fp);
        return false;
    }

    // read texture data
    int size = bmphdr.biWidth * bmphdr.biHeight * 3;
    BYTE *pBits = new BYTE [size];
    if (!pBits){
        fclose (fp);
        return false;
    }
    
    // read pixels
    int pad;
    char padbuff[3];
    BYTE *ptr, temp;
    
    pad = (bmphdr.biWidth * 3) % 4;
    pad = 4 - (pad == 0 ? 4 : pad);
    fseek (fp, hdr.bfOffBits, SEEK_SET);
    ptr = pBits;
    for (int i=0; i<bmphdr.biHeight; i++) {
        for (int j=0; j<bmphdr.biWidth; j++) {
            fread (ptr, 3, 1, fp);
            temp = ptr[0];
            ptr[0] = ptr[2];
            ptr[2] = temp;
            ptr+= 3;
        }
        fread (padbuff, pad, 1, fp);
    }
    // close file
    fclose (fp);

    // set bitmap size
    m_bmp_width = (short)bmphdr.biWidth;
    m_bmp_height = (short)bmphdr.biHeight;

    // fix the inverted bitmap
    FixBMPUpDown (pBits, m_bmp_width, m_bmp_height);

    // make Open GL texture 
    glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

    // generate single texture and bind it
    glGenTextures ( 1, &m_textid);
    glBindTexture ( GL_TEXTURE_2D, m_textid );  

    m_width = m_bmp_width;
    m_height = m_bmp_height;
    
    // set texture parameters
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR/*GL_NEAREST*/);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR/*GL_NEAREST*/);

    // set texture environemnt
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);   

    // define texture image
    glTexImage2D ( GL_TEXTURE_2D,
                    0, /* mipmap level 0 */
                    3, /* internal format */
                    bmphdr.biWidth, bmphdr.biHeight, 
                    0, /* border */ 
                    GL_RGB, 
                    GL_UNSIGNED_BYTE,
                    pBits );

    // do cleanup
    delete [] pBits;

    // setup vertices array...
    SetupVertices ();
    SetupTextureVertices ();

    m_initialized = true;

    return true;
}
#endif

void GLS_IMG_Image::SetupVertices () {
    m_vertices[0] = -m_width / 2.0f;
    m_vertices[1] = m_width / 2.0f;

    m_vertices[2] = m_width / 2.0f;
    m_vertices[3] = m_width / 2.0f;

    m_vertices[4] = m_width / 2.0f;
    m_vertices[5] = -m_width / 2.0f;

    m_vertices[6] = -m_width / 2.0f;
    m_vertices[7] = -m_width / 2.0f;
}

void GLS_IMG_Image::SetupTextureVertices () {
    m_texture_vertices[0] = 0.0f;
    m_texture_vertices[1] = 1.0f;

    m_texture_vertices[2] = 1.0f;
    m_texture_vertices[3] = 1.0f;

    m_texture_vertices[4] = 1.0f;
    m_texture_vertices[5] = 0.0f;

    m_texture_vertices[6] = 0.0f;
    m_texture_vertices[7] = 0.0f;
}

void GLS_IMG_Image::FixBMPUpDown (BYTE *pBits, short width, short height) {
    const int BYTES_PER_LINE = (width * 3);
    // const int pad = (width * 3) % 4;

    BYTE *pTempBuffer = new BYTE [width * 3];
    
    for (int i=0; i < height / 2; i++) {
        BYTE *pSrc = pBits + (i * BYTES_PER_LINE);
        BYTE *pDst = pBits + ((height - 1 - i) * BYTES_PER_LINE);
        memcpy (pTempBuffer, pSrc, width * 3);
        memcpy (pSrc, pDst, width * 3);
        memcpy (pDst, pTempBuffer, width * 3);
    }

    delete pTempBuffer;
}

/* externs */
const IID *_GLS_IMG_Image_IIDs[] = 
{
    &IID_IUnknown,
    &IID_IDispatch,
    &IID__Image,
    NULL
};

ClassFactory<GLS_IMG_Image> GLS_IMG_Image_Factory;
