//
//  Animation.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Animation.hpp"
#include "../Helper/Logger.hpp"

Animation::Animation(SpriteArray* sprites, Sprite* currentSprite, float timePerFrameMillis, bool looping)
{
    m_sprites = sprites;
    m_currentSprite = currentSprite;
    m_looping = looping;
    m_timePerFrame = timePerFrameMillis / 1000;
    m_timeElapsed = 0;
}
Animation::Animation(Animation* animation)
{
    Animation(animation->m_sprites, animation->m_currentSprite, animation->m_timePerFrame, animation->m_looping);
}
Animation::~Animation()
{}
int Animation::getTextureID()
{
    return m_currentSprite->getTextureID();
}
const Vertex* Animation::getTextureVertexData()
{
    return m_currentSprite->getTextureVertexData();
}
void Animation::update(float dt)
{
    if (m_sprites->m_size <= 0)
        return;
    
    m_timeElapsed += dt;
    
    if (m_timeElapsed >= m_timePerFrame * m_sprites->m_size)
        m_timeElapsed = 0;
    
    m_currentSprite = m_sprites->m_spritesArray[(int)((m_timeElapsed / (m_timePerFrame * m_sprites->m_size)) * m_sprites->m_size)];
}