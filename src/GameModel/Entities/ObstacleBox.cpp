//
//  File:	ObstacleNormal.cpp
//  Class	ObstacleNormal
//  Author	Jonatan Rapp
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 8, 2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//	A class for representing a box obstacle.


#include "ObstacleBox.hpp"

ObstacleBox::~ObstacleBox()
{

}
ObstacleBox::ObstacleBox(Vector2d* position, float height)
{
	m_height = height;
	ObstacleBox::generatePbody(position);
	EventBus::getSharedInstance()->publishEvent(PBODY_CREATED_PHYSICS, (PBody *)m_body);

}
void ObstacleBox::destroy()
{
	EventBus::getSharedInstance()->publishEvent(PBODY_DESTROYED_PHYSICS, (PBody *)m_body);
}

void ObstacleBox::generatePbody(Vector2d position)
{
	b2Vec2 pos = b2Vec2(position.m_x, position.m_y);
	b2Vec2 size = b2Vec2(2.0f, m_height);
    m_body = new PBody(size, pos, true, false, PB_OBSTACLE_BOX);

}

