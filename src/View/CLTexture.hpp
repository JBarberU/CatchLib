//
//  File:   SCLTexture.hpp
//  Class:  CLTexture
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   1/10/12
//
//  Description:
//  This class is used to store width, height and pixel data
//  of an OpenGL texture.
//

#ifndef __CatchiOS__SCLTexture__
#define __CatchiOS__SCLTexture__

class CLTexture{
private:
    unsigned char*  m_data;
    int             m_width;
    int             m_height;
    
public:
    //  Set the data for the texture. Has to be done together with
    //  width and height to prevent the risk of setting data for a
    //  texture with an incompatible size.
    void setData(unsigned char* newData, int width, int height);
    
    //  Get a pointer to the pixel data.
    unsigned char* getData();
    
    //  Get the width.
    int getWidth();
    
    //  Get the height.
    int getHeight();
    
};

#endif /* defined(__CatchiOS__SCLTexture__) */
