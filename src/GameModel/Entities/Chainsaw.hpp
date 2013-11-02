//
//  File:       Chainsaw.hpp
//  Class:      Chainsaw
//  Author:     Jesper Persson
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		22/10-2012
//
//	License: The following code is licensed under the Catch22-License


#include "../Physics/PBody.hpp"

/**
 *
 * The Chainsaw is the Players weapon. Can be thrown to destroy
 * obstacles.
 * The Chainsaw is a physical body capable of moving
 * in any direction and colliding with other object.
 *
 * @see Obstacle
 *
 */
class Chainsaw : public PBody
{    
protected:

	~Chainsaw();

public:

	Chainsaw(b2Vec2 size, b2Vec2 position, b2Vec2 target, bool stationary, bool rotatable, PBodyType tag);

    /**
     * Check if the Chainsaw has reached the target.
     * @return
     * 		true - the Chainsaw has reached the target.
     * 		false - the Chainsaw has not reached the target.
     */
    bool targetReached();

    /**
     * Updates the position of the Chainsaw.
     *
     * @param dt
     * 		Time elapsed since last call to update.
     *
     * @see PBody
     *
     */
    void update(float dt);

    /**
     * Set the target of the Chainsaw.
     *
     * @param b2Vec2
     * 		Position of the target.
     */
    void setTarget(b2Vec2);

    /**
     * Set the physical body of the Chainsaw.
     *
     * @param body
     * 		The physics body that should be set as the Chainsaws body.
     */
    virtual void setBody(b2Body* body);

    /**
     * Handle a collision with another Pbody.
     *
     * @param
     * 		The body that the Chainsaw collided with.
     *
     */
    void onCollide(PBody* other);
    
private:
    bool m_targetReached;
    b2Vec2 m_target;
    static double CHAINSAW_MOVEMENT_SPEED;
};
