//
//  File:		GameMap.cpp
//  Class:      GameMap
//  Author:     Sebastian Odbjer, Alexander Hederstaf
//              All code is my own except where credited to others.
//
//	Copyright © 2012 by Catch22. All Rights Reserved.
//  Date: 		Oct 7, 2012
//
//	License: The following code is licensed under the Catch22-License
//

#include "stdlib.h"
#include "GameMap.hpp"


GameMap::GameMap()
{
	generator = new MapGenerator();
	generateStartMap();
}

GameMap::~GameMap()
{

}

Vector2d* GameMap::nextPlatformStart(Vector2d* lastEnd)
{
	// Find the allowed change in height based on max and min
	// height for the generator. Compare previous platforms end
	// point plus and minus one with the max and min values.
	int minAllowed = (lastEnd->m_y - 1 >= generator->HEIGHT_MIN) ? -1 : 0;
	int maxAllowed = (lastEnd->m_y + 1 <= generator->HEIGHT_MAX) ?  1 : 0;

	// Randomize the difference in height.
	int range = maxAllowed - minAllowed;
	int random = rand() % (range + 1) + minAllowed;

	// Add the difference in height to the height of the last platforms
	// end point. Add a constant horizontal distance between platforms.
	return new Vector2d(lastEnd->m_x + generator->PLATFORM_GAP_LENGTH
			, lastEnd->m_y + random);
}

void GameMap::generateStartMap()
{
	Platform* p = generator->generateFlatPlatform(new Vector2d(0.f, 7.f), 8);
	addPlatform(p);

	// Generate two additional Platforms
	for (int i = 0; i < 2; i++) {
		p = generator->generatePlatform(nextPlatformStart(p->endPoint()));
		addPlatform(p);
	}
}

void GameMap::addPlatform(Platform* platform)
{
	platforms.push_back(platform);
}

void GameMap::reformGameMap()
{
	platforms.erase(platforms.begin());
	Platform* p = platforms.back();
	addPlatform(generator->generatePlatform(nextPlatformStart(p->endPoint())));
}

void GameMap::update(float playerX)
{
	Platform* firstPlatform = platforms.front();
	if (firstPlatform->endPoint()->m_x + 10 < playerX) {
		reformGameMap();
	}
}
