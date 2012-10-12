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
#include "MapGenerator.hpp"

class GameMap
{
public:
	~GameMap();
	GameMap();

	/*
	 * TODO:
	 */
	void addPlatform(Platform* platform);

	/*
	 * TODO:
	 */
	void reformGameMap();

private:

	/*
	 * TODO:
	 */
	Vector2d* nextPlatformStart(Vector2d* lastEnd);

	/*
	 * TODO:
	 */
	void generateStartMap();

	vector<Platform*> platforms;
	MapGenerator* generator;
};
