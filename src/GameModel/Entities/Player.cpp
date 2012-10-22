//
//  Player.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	License: The following code is licensed under the Catch22-License
//

#include "Player.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Math/Vector2d.hpp"
#include "../../Helper/Logger.hpp"

Vector2d* JUMP = new Vector2d(3.0, 15.0);

Player::Player() :
PBody(b2Vec2(2.f, 2.f), b2Vec2(3.f, 12.f), false, false, PB_PLAYER)
{
    Log(LOG_INFO, "Player", "Created Player");
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, this);
}
Player::~Player()
{
}
void Player::jump()
{
    this->getBody()->ApplyForce(b2Vec2(-200.f,400.f), this->getBody()->GetPosition());
}