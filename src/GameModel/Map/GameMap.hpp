//
//  GameMap.hpp
//  CatchLib
//
//  Created by Jesper Persson on 9/29/12.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
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
