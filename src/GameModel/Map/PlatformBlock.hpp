//
//  File:       PlatformBlock.hpp
//  Class:      PlatformBlock
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//	License: The following code is licensed under the Catch22-License
//
//
//  Description:
//	A class for representing a block in a Platform.
//
//

#include "../Physics/PBody.hpp"

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
	PlatformBlock(Blocktype type);
	void setStartPoint(Vector2d* vector);
	Blocktype getType();
	Vector2d* getStartVector();
	Vector2d* getEndVector();

private:
	Blocktype type;
	Vector2d* startVector;
};
