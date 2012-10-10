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

