//
//  File:   Sprite.cpp
//  Class:  Sprite
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10-2012
//

#include "Sprite.hpp"
#include "../Helper/Logger.hpp"

Sprite::Sprite(float x, float y, float w, float h, int textureID)
{
    m_vertex = new const Vertex[4] {
        Vertex(x        , y + h),
        Vertex(x + w    , y + h),
        Vertex(x        , y),
        Vertex(x + w    , y),
    };
    
    m_textureID = textureID;
}
Sprite::Sprite(Sprite* sprite)
{
    m_vertex = sprite->m_vertex;
    m_textureID = sprite->m_textureID;
}

Sprite::~Sprite()
{
    
}

const Vertex* Sprite::getTextureVertexData()
{
    return m_vertex;
}
int Sprite::getTextureID()
{
    return m_textureID;
}