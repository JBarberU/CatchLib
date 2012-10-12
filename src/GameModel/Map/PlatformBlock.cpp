//
//  File:		PlatformBlock.cpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		05/10-2012

#include "PlatformBlock.hpp"


PlatformBlock::PlatformBlock(Blocktype type, Vector2d* vector)
{
	this->type = type;
	this->startVector = vector;
	this->body = generatePBody();
	//make something listen to this->body for collisions.

}

PlatformBlock::~PlatformBlock()
{

}

void PlatformBlock::setStartPoint(Vector2d* vector)
{
	startVector = vector;
}

Vector2d* PlatformBlock::getStartVector()
{
	return startVector;
}

Vector2d* PlatformBlock::getEndVector()
{
	Vector2d* eVect = new Vector2d(startVector->m_x, startVector->m_y);
	if(type == INCLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree incline
		eVect=+(new Vector2d(2, 1));
	} else if (type == DECLINE) {
		//Set the end points at a set distance in x and y to create a 30 degree decline
		eVect=+(new Vector2d(2, -1));
	} else if (type == HORIZONTAL) {
		//Set the end points at a set distance in x and y to create a horizontal line
		eVect=+(new Vector2d(2, 0));
	}
	return eVect;
}

Blocktype PlatformBlock::getType()
{
	return type;
}

PBody* PlatformBlock::generatePBody()
{
	Vector2d** pVectors = new Vector2d*[4];
	pVectors[0] = startVector;
	pVectors[1] = getEndVector();
	pVectors[2] = new Vector2d(startVector->m_x, 0);
	pVectors[3] = new Vector2d(getEndVector()->m_x, 0);

	Vector2dArray* pVectorArray = new Vector2dArray(pVectors, 4);
	PBody* body = new PBody(pVectorArray, true, PB_PLATFORM);

	return body;
}

