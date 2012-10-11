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

Vector2d* JUMP = new Vector2d(1, 450);

Player::Player()
{
    m_body = new PBody(new Vector2d(100,100), new Vector2d(32, 32), true, false, true, PB_PLAYER);
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, m_body);
}
Player::~Player()
{
    
}
void Player::jump()
{
    m_body->addVector(JUMP);
}