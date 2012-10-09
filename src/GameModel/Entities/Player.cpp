//
//  Player.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/7/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "Player.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../Physics/Vector2d.hpp"
#include "../../Helper/Logger.hpp"

Vector2d* JUMP = new Vector2d(0, 450);

Player::Player()
{
    m_body = new PBody(true, false,  new Vector2d(100, 100), new Vector2d(32, 32), new Vector2d(0, 0));
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, m_body);
}
Player::~Player()
{
    
}
void Player::jump()
{
    m_body->addVector(JUMP);
}