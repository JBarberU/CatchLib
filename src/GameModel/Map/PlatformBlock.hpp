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

enum Blocktype
{
	INCLINE,
	HORIZONTAL,
	DECLINE
};

class PlatformBlock {
public:
	~PlatformBlock();
	PlatformBlock(Blocktype type, Vector2d* vector);
	void setStartPoint(Vector2d* vector);
	Blocktype getType();
	Vector2d* getStartVector();
	Vector2d* getEndVector();

private:
	Blocktype type;
	Vector2d* startVector;
};
