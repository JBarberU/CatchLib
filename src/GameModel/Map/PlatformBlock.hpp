//
//  File:       PlatformBlock.hpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright © 2012 by Catch22. All Rights Reserved.
//  Date: 		Sep 29, 2012
//
//  Description:
//	A class for representing a block in a Platform.
//
//

#include "../Physics/PBody.hpp"
#include "../Physics/EPBodyType.hpp"
#include "../Physics/Vector2d.hpp"

#ifndef PLATFORMBLOCK_H
#define PLATFORMBLOCK_H

enum Blocktype
{
	INCLINE,
	HORIZONTAL,
	DECLINE
};

class PlatformBlock
{
public:
	~PlatformBlock();

	/**
	 * PlatformBlock constructor
	 * @param type
	 * 		The Blocktype enum of the block, basically the slope of the block.
	 * @param vector
	 * 		A pointer to the start position of the block.
	 */
	PlatformBlock(Blocktype type, Vector2d* vector);

	/**
	 * Changes the start position of the block, which for our implementation also changes the end position
	 * @param vector
	 * 		The new start position of the block.
	 */
	void setStartPoint(Vector2d* vector);

	/**
	 * Returns the Blocktype of the block
	 */
	Blocktype getType();

	/**
	 * Returns the start position of the block in the form of a Vector2d
	 */
	Vector2d* getStartVector();

	/**
	 * Returns the end position of the block, based on the start position and the type, in the form of a Vector2d
	 */
	Vector2d* getEndVector();

	/**
	 * Generates and then returns the physical body (that which you can collide with) of the block.
	 */
	PBody* generatePBody();

private:
	PBody* body;
	Blocktype type;
	Vector2d* startVector;
};

#endif
