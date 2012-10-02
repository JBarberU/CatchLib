//
//  Actor.hpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/2/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef __CatchiOS__Actor__
#define __CatchiOS__Actor__

#include "IRenderable.hpp"
#include "Animation.hpp"

class Actor : public IRenderable {
    // Pointer to some model object to represent
private:
    Animation** m_animations;
    Animation* m_currentAnimation;
public:
    Actor(Animation** animations, Animation* currentAnimation);
    ~Actor();
    
    virtual const Vertex* getVertexData();
    virtual const Vertex* getTextureVertexData();
    virtual int getTextureID();
    virtual void update(float dt);    // Setter for the object to follow
    // Reset actor
};

#endif /* defined(__CatchiOS__Actor__) */
