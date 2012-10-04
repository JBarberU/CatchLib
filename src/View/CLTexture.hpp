//
//  SCLTexture.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/1/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__SCLTexture__
#define __CatchiOS__SCLTexture__


//  CLTexture
//  A struct used to represent an Image in a way that is
//  relevant to OpenGL. It contains:
//  - internalFormat, which must be one of the following:
//          GL_ALPHA, GL_RGB, GL_RGBA, GL_LUMINANCE, GL_LUMINANCE_ALPHA
//  - width, the width of the image in pixels.
//  - height, the height of the image in pixels.
//  - type, can be one of the following:
//          GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_5_6_5,
//          GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_5_5_5_1
//  - data, a pointer to the image data in memory.
class CLTexture{
private:
    unsigned char*  m_data;
    int             m_width;
    int             m_height;
    
public:
    void setData(unsigned char* newData, int width, int height);
    unsigned char* getData();
    int getWidth();
    int getHeight();
    
};

#endif /* defined(__CatchiOS__SCLTexture__) */
