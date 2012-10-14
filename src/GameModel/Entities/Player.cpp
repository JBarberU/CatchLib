//
//  Player.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Player.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Math/Vector2d.hpp"
#include "../../Helper/Logger.hpp"

Vector2d* JUMP = new Vector2d(3.0, 15.0);

Player::Player() :
PBody(new Vector2d(0.0,6), new Vector2d(1.5, 1.5), true, false, true, PB_PLAYER)
{    
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, this);
}
Player::~Player()
{
    
}
void Player::jump()
{
    this->maskMovementVector(0, 1);
    this->addVector(JUMP);
}
Vector2d* Player::isCollidingWithBody(PBody* otherBody)
{
    Log(LOG_INFO, "Player", "Check collision");
    
    return PBody::isCollidingWithBody(otherBody);
}