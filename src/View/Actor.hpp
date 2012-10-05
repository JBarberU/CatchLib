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

struct AnimationArray {
    Animation** m_animationArray;
    int         m_size;
    
    AnimationArray(Animation** animations, int size) {
        m_animationArray = animations;
        m_size = size;
    }
};

class Actor : public IRenderable {
    // Pointer to some model object to represent
private:
    AnimationArray* m_animations;
    Animation*  	m_currentAnimation;
    
public:
    Actor(AnimationArray* animations, Animation* currentAnimation);
    Actor(Actor* actor);
    ~Actor();
    
    virtual const Vertex* getVertexData();
    virtual const Vertex* getTextureVertexData();
    virtual int getTextureID();
    virtual void update(float dt);    // Setter for the object to follow
    // Reset actor
};

#endif /* defined(__CatchiOS__Actor__) */
