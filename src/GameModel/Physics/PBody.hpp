//
//  File:       PBody.hpp
//  Class:      PBody
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//  Description:
//	A class for representing a Physical Body.
//	All Physical Bodies will be solid (collidable) and affected by
//  in game physics. They will each have a position in the GameMap
//  and a directional vector.
//
//
#include "Vector2d.hpp"

class PBody
{
public:
	~PBody();
	PBody();
private:
	Vector2d position;
	Vector2d direction;
};
