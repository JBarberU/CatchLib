//
//  File:       GameMap.hpp
//  Class:      GameMap
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//  Description:
//	This class is for representing a GameMap.
//
//
#include "Platform.hpp"

class GameMap
{
public:
	~GameMap();
	GameMap();
	void generateStartMap();
	void addPlatform(Platform* platform);
	void reformGameMap();
	Platform* generatePlatform(Vector2d* startpoint);

private:
	vector<Platform*> platforms;
};
