//
//  File:   Actor.hpp
//  Class:  Actor
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   2/10/12
//
//  Description:
//  This class is used to graphically represent some part of
//  the game model. It has a set of animations which it can
//  switch between.
//
#ifndef __CatchiOS__Actor__
#define __CatchiOS__Actor__

#include "IRenderable.hpp"
#include "Animation.hpp"
#include "../GameModel/Physics/PBody.hpp"

//  A structure used keep track of animations and
//  the current number of animations.
struct AnimationArray {
    Animation** m_animationArray;
    int         m_size;
    
    AnimationArray(Animation** animations, int size) {
        m_animationArray = animations;
        m_size = size;
    }
};

class Actor : public IRenderable {
private:
    AnimationArray* m_animations;
    Animation*  	m_currentAnimation;
    PBody*          m_pBody;
    
public:
    Actor(AnimationArray* animations, Animation* currentAnimation);
    Actor(Actor* actor);
    ~Actor();
    
    void setPBody(PBody* pBody);
    
    //  Inherited from IRenderable
    virtual const Vertex* getVertexData();
    virtual const Vertex* getTextureVertexData();
    virtual int getTextureID();
    virtual void update(float dt);

};

#endif /* defined(__CatchiOS__Actor__) */
