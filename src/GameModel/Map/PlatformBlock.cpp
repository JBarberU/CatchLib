//
//  File:		PlatformBlock.cpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		05/10-2012

#include "PlatformBlock.hpp"
#include "../../EventHandling/EventBus.hpp"

PlatformBlock::PlatformBlock(Blocktype type, Vector2d* vector)
{
	this->type = type;
	this->body = generatePBody(vector);
	EventBus::getSharedInstance()->publishEvent(PBODY_CREATED, (PBody *)body);
	//make something listen to this->body for collisions.

}

PlatformBlock::~PlatformBlock()
{

}

Vector2d* PlatformBlock::getStartVector()
{
	return this->body->getVectorArray()->m_vectors[1];
}

Vector2d* PlatformBlock::getEndVector()
{
	return this->body->getVectorArray()->m_vectors[2];
}

Blocktype PlatformBlock::getType()
{
	return type;
}

PBody* PlatformBlock::generatePBody(Vector2d* vector)
{
	Vector2d* endVector = new Vector2d(vector);
	if(type == INCLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree incline
		*endVector+=(new Vector2d(2, 1));
	} else if (type == DECLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree decline
		*endVector+=(new Vector2d(2, -1));
	} else if (type == HORIZONTAL) {
		//Set the end points at a set distance in x and y to create a horizontal line
		*endVector+=(new Vector2d(2, 0));
	}

	Vector2d** pVectors = new Vector2d*[4];
	pVectors[0] = new Vector2d(vector->m_x, 0);
	pVectors[1] = vector;
	pVectors[2] = endVector;
	pVectors[3] = new Vector2d(endVector->m_x, 0);

	Vector2dArray* pVectorArray = new Vector2dArray(pVectors, 4);
	PBody* body = new PBody(pVectorArray, true, PB_PLATFORM);

	return body;
}

