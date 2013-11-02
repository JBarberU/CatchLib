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

#include <vector>
#include <string>

/**
 *
 *
 */
class Actor : public IRenderable {
private:
    std::vector<Animation>  m_animations;
    int                     m_currentAnimationIndex;
    PBody*                  m_pBody;
    Vector2d                m_halfSize;
    OffsetMatrix            m_offset;

    /**
     * private utility function that creates the Actor, used by constructor.
     */
    void CreateActor(const std::vector<Animation> &animations, int currentAnimationIndex, const Vector2d &halfSize, const OffsetMatrix &offsetMatrix);

    /**
     * Private utility to check the validity of an animation, which prints an error
     * if there was a problem.
     */
    bool isAnimationOK(const std::string &str = "");
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
     * @param offsetMatrix
     * 		Matrix used to to draw the Animation on another location the the physical body.
     */
    Actor(const std::vector<Animation> &animations = std::vector<Animation>(), int currentAnimationIndex = -1, const Vector2d &halfSize = Vector2d(), const OffsetMatrix &offsetMatrix = OffsetMatrix());

    /**
     * Copy constructor for Actor.
     *
     * @param actor
     * 		The Actor to copy.
     */
    Actor(const Actor &actor);

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
