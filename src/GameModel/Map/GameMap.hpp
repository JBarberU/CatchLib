//
//  File:       GameMap.hpp
//  Class:      GameMap
//  Author:     Sebastian Odbjer, Alexander Hederstaf
//              All code is my own except where credited to others.
//
//	Copyright © 2012 by Catch22. All Rights Reserved.
//  Date: 		Sep 29,-2012
//
//	License: The following code is licensed under the Catch22-License
//
//
//  Description:
//	A GameMap is a collection of Platforms at a distance from each other used
//	as the world in the Game.
//
//
#include "MapGenerator.hpp"

class GameMap
{
public:
	~GameMap();

	/**
	 * Construtor for GameMap.
	 * Creates and initiates a MapGenerator for this GameMap, it then calls generateStartMap().
	 */
	GameMap();

	/**
	 * Adds a Platform at the end of the vector of platforms.
	 * @param platform
	 * 		The Platform that is to be added.
	 */
	void addPlatform(Platform* platform);

	/**
	 * Reforms the GameMap by erasing the first element in the vector of platforms
	 * and adding a newly generated one at the end.
	 */
	void reformGameMap();

	/**
	 * Update the GameMap checking for platforms out of bounds and replacing those.
	 */
	void update(float playerX);

private:

	/**
	 * Generates an appropriate start point for the next platform based on a given Vector2d.
	 * @param lastEnd
	 * 		The position where the last platform ended.
	 * @return
	 * 		A position at a distance from the last platform where you can place a new platform.
	 */
	Vector2d* nextPlatformStart(Vector2d* lastEnd);

	/**
	 * Generates a flat surface of platform blocks that represents a starting area platform,
	 * followed by six randomly generated platforms.
	 */
	void generateStartMap();

	vector<Platform*> platforms;
	MapGenerator* generator;
};
