//
//  File:       GameMap.hpp
//  Class:      GameMap
//  Author:     Jesper Persson
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
	void addPlatform(Platform* platform);
	void reformFirstPlatform();

private:
	vector<Platform*> platforms;
};
