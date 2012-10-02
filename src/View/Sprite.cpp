//
//  Sprite.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(float x, float y,
               float w, float h,
               int textureID)
{
    
    const Vertex vert[] = {
        {{x,y},         {1.0f, 1.0f, 1.0f, 1.0f}},
        {{x + w,y},     {1.0f, 1.0f, 1.0f, 1.0f}},
        {{x + w,y + h}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{x,y + h},     {1.0f, 1.0f, 1.0f, 1.0f}},
    };
    
    m_vertex = vert;
    
    m_textureID = textureID;
}
Sprite::~Sprite()
{
    
}

const Vertex* Sprite::getVertexData()
{
    return m_vertex;
}
int Sprite::getTextudeID()
{
    return m_textureID;
}