//
//  File:   Animation.cpp
//  Class:  Animation
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10/2012
//
#include "Animation.hpp"
#include "../Helper/Logger.hpp"

Animation::Animation(SpriteArray* sprites, Sprite* currentSprite, float timePerFrameMillis, bool looping)
{
    CreateAnimation(sprites, currentSprite, timePerFrameMillis, looping);
}
Animation::Animation(Animation* animation)
{
    CreateAnimation(animation->m_sprites, animation->m_currentSprite, animation->m_timePerFrame * 1000, animation->m_looping);
}
void Animation::CreateAnimation(SpriteArray* sprites, Sprite* currentSprite, float timePerFrameMillis, bool looping)
{
    m_sprites = sprites;
    m_currentSprite = currentSprite;
    m_looping = looping;
    m_timePerFrame = timePerFrameMillis / 1000;
    m_timeElapsed = 0;
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