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
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//  This class is used to graphically represent some part of
//  the game model. It has a set of animations which it can
//  switch between.
//
#ifndef __Actor__
#define __Actor__

#include "IRenderable.hpp"
#include "Animation.hpp"
#include "../GameModel/Physics/PBody.hpp"
#include "OffsetMatrix.hpp"

/**
 * A structure used keep track of animations and
 * the current number of animations.
 */
struct AnimationArray {
    Animation** m_animationArray;
    int         m_size;
    
    /**
     * Constructor for AnimationArray
     *
     * @param animations
     * 		An arrays of Animations that will be used for this AnimationArray.
     * @param size
     * 		The size of the array.
     */
    AnimationArray(Animation** animations, int size) {
        m_animationArray = animations;
        m_size = size;
    }

    /**
     * Copy Constructor for AnimationArray
     * @param anim
     * 		The AnimationArray to copy.
     */
    AnimationArray(AnimationArray* anim) {
        this->m_size = anim->m_size;
        this->m_animationArray = new Animation*[this->m_size];
        
        for (int i = 0; i < this->m_size; i++) {
            this->m_animationArray[i] = new Animation(anim->m_animationArray[i]);
        }
    }

    /**
     * Deconstructor for AnimationArray
     *
     */
    ~AnimationArray() {
        for (int i = 0; i < m_size; i++) {
            delete m_animationArray[i];
        }
        delete m_animationArray;
        m_animationArray = 0;
    }
};

/**
 *
 *
 */
class Actor : public IRenderable {
private:
    AnimationArray* m_animations;
    Animation*  	m_currentAnimation;
    PBody*          m_pBody;
    Vector2d*       m_halfSize;
    OffsetMatrix*   m_offset;

    /**
     * private utility function that creates the Actor, used by constructor.
     */
    void CreateActor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize, OffsetMatrix* offsetMatrix);

public:

    /**
     * Constructor for an Actor based on an array of animations with offset.
     *
     * @param animations
     *		The Animations this Actor loops through.
     * @param currentAnimation
     *		The starting Animation.
     * @param halfSize
     *		Half the size of the Actor, the distance to the corners in absolute values
     *		from the center point.
     */
    Actor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize);

    /**
     * Constructor for an Actor based on an array of animations with offset.
     *
     * @param animations
     *		The Animations this Actor loops through.
     * @param currentAnimation
     *		The starting Animation.
     * @param halfSize
     *		Half the size of the Actor, the distance to the corners in absolute values
     *		from the center point.
     * @param offsetMatrix
     * 		Matrix used to to draw the Animation on another location the the physical body.
     */
    Actor(AnimationArray* animations, Animation* currentAnimation, Vector2d* halfSize, OffsetMatrix* offsetMatrix);

    /**
     * Copy constructor for Actor.
     *
     * @param actor
     * 		The Actor to copy.
     */
    Actor(Actor* actor);

    /**
     * Deconstructor for Actor.
     *
     */
    ~Actor();
    
    /**
     * Sets a physical body to this Actor, it will be used to draw the actor at the correct location.
     *
     * @param  pBody
     * 		A physical body that this Actor will represent graphically.
     */
    void setPBody(PBody* pBody);
    
    // Inherited from IRenderable
    virtual const Vertex* getVertexData();
    virtual const Vertex* getTextureVertexData();
    virtual int getTextureID();
    virtual void update(float dt);
    virtual float getAngle();
};

#endif /* defined(__Actor__) */
