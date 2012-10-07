//
//  File:   SCLTexture.cpp
//  Class:  CLTexture
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   1/10/12
//

#include "CLTexture.hpp"

void CLTexture::setData(unsigned char* newData, int width, int height)
{
    m_width = width;
    m_height = height;
    
    delete [] m_data;
    
    this->m_data = new unsigned char[m_width * m_height * 4];
    
    for (int i = 0; i < m_width * m_height * 4; i++) {
        m_data[i] = newData[i];
    }
}
unsigned char* CLTexture::getData()
{
    return this->m_data;
}
int CLTexture::getWidth()
{
    return m_width;
}
int CLTexture::getHeight()
{
    return m_height;
}