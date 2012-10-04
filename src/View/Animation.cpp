//
//  Animation.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation()
{
    
}

Animation::~Animation()
{
    
}

int Animation::getTextureID()
{
    return m_currentSprite->getTextudeID();
}
const Vertex* Animation::getTextureVertexData()
{
    return m_currentSprite->getTextureVertexData();
}
void Animation::update(float dt)
{
    // Update code goes here
}