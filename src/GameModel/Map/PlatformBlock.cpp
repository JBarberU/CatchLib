//
//  PlatformBlock.cpp
//  CatchLib
//
//  Created by Sebastian Odbjer on 5/10/12.
//  Copyright (c) 2012 Catch22. All rights reserved.


#include "PlatformBlock.hpp"


PlatformBlock::PlatformBlock(Blocktype type)
{
	this->type = type;
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
		//Set the end points at a set distance in x and y to create a 30d incline
		eVect=+(new Vector2d(2, 1));
	} else if (type == DECLINE) {
		//Set the end points at a set distance in x and y to create a 30d decline
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

