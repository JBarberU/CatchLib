//
//  File:       PlatformBlock.hpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//  Description:
//	A class for representing a block in a Platform.
//
//

#include "../Physics/PBody.hpp"
#include "../Physics/Vector2d.hpp"

#ifndef PLATFORMBLOCK_H
#define PLATFORMBLOCK_H

enum Blocktype
{
	INCLINE,
	HORIZONTAL,
	DECLINE
};

class PlatformBlock {
public:
	~PlatformBlock();

	/*
	 * PlatformBlock constructor
	 * Blocktype type -- the Blocktype of the block, basically the slope of the block.
	 * Vector2d* vector -- a pointer to the start position of the block.
	 */
	PlatformBlock(Blocktype type, Vector2d* vector);

	//Changes the start position of the block, which for our implementation also changes the end position
	void setStartPoint(Vector2d* vector);

	//Returns the Blocktype of the block
	Blocktype getType();

	//Returns the start position of the block in the form of a Vector2d
	Vector2d* getStartVector();

	//Returns the end position of the block, based on the start position and the type, in the form of a Vector2d
	Vector2d* getEndVector();

private:
	Blocktype type;
	Vector2d* startVector;
};

#endif
