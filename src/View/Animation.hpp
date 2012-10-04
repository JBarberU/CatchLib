//
//  Animation.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__Animation__
#define __CatchiOS__Animation__

#include "Vertex.hpp"
#include "Sprite.hpp"

class Animation {
private:
    float m_timeElapsed;
    float m_timePerFrame;
    bool m_looping;
    Sprite** m_sprites;
    Sprite* m_currentSprite;
    // Callback function pointer should be saved here
    
public:
    Animation();
    ~Animation();
    
    int getTextureID();
    const Vertex* getTextureVertexData();
    void update(float dt);
};

#endif /* defined(__CatchiOS__Animation__) */
