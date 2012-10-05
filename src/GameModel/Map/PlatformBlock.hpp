//
//  PlatformBlock.hpp
//  CatchLib
//
//  Created by Jesper Persson on 9/29/12.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
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
