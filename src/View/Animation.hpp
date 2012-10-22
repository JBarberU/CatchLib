//
//  File:   Animation.hpp
//  Class:  Animation
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10/2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  A class used to represent an animation. It has its sprites
//  which are included in said animation and some properties such
//  as time per frame and whether to loop or not.
//
#ifndef __Animation__
#define __Animation__

#include "Vertex.hpp"
#include "Sprite.hpp"

struct SpriteArray{
    Sprite**    m_spritesArray;
    int         m_size;
    SpriteArray(Sprite** sprites, int size) {
        m_spritesArray = sprites;
        m_size = size;
    }
};

class Animation {
private:
    float           m_timeElapsed;
    float           m_timePerFrame;
    bool            m_looping;
    
    SpriteArray*    m_sprites;
    Sprite*         m_currentSprite;
    
    void CreateAnimation(SpriteArray* sprites, Sprite* currentSprite, float timePerFrameMillis, bool looping);
    
public:
    //  Creates an animation with the given sprites, current sprite, number of milliseconds per frame
    //  and whether to loop or not.
    Animation(SpriteArray* sprites, Sprite* currentSprite, float timePerFrameMillis, bool looping);
    Animation(Animation* animation);
    ~Animation();
    
    //  Same as the ones in IRenderable
    int getTextureID();
    const Vertex* getTextureVertexData();
    void update(float dt);
};

#endif /* defined(__Animation__) */
