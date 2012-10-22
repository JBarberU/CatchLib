//
//  File:       PlatformBlock.hpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright © 2012 by Catch22. All Rights Reserved.
//  Date: 		Sep 29, 2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//	A class for representing a block in a Platform.


#include "../Physics/PBody.hpp"
#include "../Physics/EPBodyType.hpp"
#include "../../Math/Vector2d.hpp"

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

	/**
	 * PlatformBlock constructor
	 * @param type
	 * 		The Blocktype enum of the block, basically the slope of the block.
	 * @param vector
	 * 		The start position of the block.
	 */
	PlatformBlock(Blocktype type, Vector2d* vector);

	/**
	 * Returns the Blocktype of the block.
	 */
	Blocktype getType();

	/**
	 * Returns the start position of the block.
	 */
	Vector2d* getStartVector();

	/**
	 * Returns the end position of the block.
	 */
	Vector2d* getEndVector();

	/**
	 * Generates and then returns the physical body of the block.
	 *
	 * @param vector
	 * 		The Vector2d representing the platforms startpoint.
	 */
	PBody* generatePBody(Vector2d* vector);

private:
	PBody*      m_body;
	Blocktype   m_type;
};

#endif
