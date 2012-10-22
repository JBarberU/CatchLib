//
//  File:	Player.cpp
//  Class	Player
//  Author	John Barbero Unenge
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 7, 2012
//
//	License: The following code is licensed under the Catch22-License
//

#include "Player.hpp"
#include "../../EventHandling/EventBus.hpp"
#include "../../Math/Vector2d.hpp"
#include "../../Helper/Logger.hpp"

#include "../../../Box2D/Dynamics/b2Body.h"
#include "../../../Box2D/Dynamics/b2Fixture.h"

Vector2d*   JUMP = new Vector2d(0.f,400.f);
b2Vec2      MOVEMENT_SPEED = b2Vec2(3.f,0.f);

Player::Player() :
PBody(b2Vec2(2.f, 2.f), b2Vec2(0.f, 12.f), false, false, PB_PLAYER)
{

    Log(LOG_INFO, "Player", "Created Player");
    EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, this);
}
Player::~Player()
{
}
void Player::jump()
{
    this->getBody()->ApplyForce(b2Vec2(JUMP->m_x, JUMP->m_y), this->getBody()->GetPosition());
}
void Player::setBody(b2Body* body)
{
    PBody::setBody(body);
    this->getBody()->GetFixtureList()->SetRestitution(.3);
    this->getBody()->GetFixtureList()->SetFriction(.0);
}
void Player::update()
{
    b2Vec2 vel = this->getBody()->GetLinearVelocity();

    b2Vec2 impulse = MOVEMENT_SPEED - vel;

    this->getBody()->ApplyForce(impulse, this->getBody()->GetPosition());

    Log(LOG_INFO, "Player", generateCString("Player: %d,%d", this->getPosition().x, this->getPosition().y));

}
