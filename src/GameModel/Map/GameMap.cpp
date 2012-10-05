//
//  GameMap.hpp
//  CatchLib
//
//  Created by Sebastian Odbjer on 9/29/12.
//  Copyright (c) 2012 Catch22. All rights reserved.

#include "GameMap.hpp"

GameMap::GameMap()
{

}

GameMap::~GameMap()
{

}

void GameMap::addPlatform(Platform* platform)
{
	platforms.push_back(platform);
}

void GameMap::reformFirstPlatform()
{
	platforms.erase(platforms.first());
	//Generate new platformBlocks in this platform
	// addPlatform(mapGenerator.generatePlatform());

}


