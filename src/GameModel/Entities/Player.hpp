//
//  File:	Player.hpp
//  Class	Player
//  Author	John Barbero Unenge
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 7, 2012
//
//	License: The following code is licensed under the Catch22-License


#ifndef __Player__
#define __Player__

#include "../Physics/PBody.hpp"

/**
 *
 * The Player is the Player object in the game. The Player is
 * a PBody for the physics engine.
 *
 */
class Player : public PBody
{
private:

public:
    Player();
    ~Player();
    
    /**
     * Set the box2d body of the player
     */
    virtual void setBody(b2Body* body);
    
    /**
     * Make the player jump
     */
    void jump();

    /**
     * Update the player
     */
    void update();
};

#endif /* defined(__Player__) */
