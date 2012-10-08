

#include "stdlib.h"
#include "GameMap.hpp"

GameMap::GameMap()
{

}

GameMap::~GameMap()
{

}

void GameMap::generateStartMap()
{
	addPlatform(generatePlatform(new Vector2d(0 ,0)));
	for(int i = 0; i < 6; i++){
		addPlatform(generatePlatform(platforms.back()->endPoint()));
	}
}

void GameMap::addPlatform(Platform* platform)
{
	platforms.push_back(platform);
}

void GameMap::reformGameMap()
{
	platforms.erase(platforms.begin());
	//Generate new platformBlocks in this platform
	addPlatform(generatePlatform(platforms.back()->endPoint()));
}

Platform* GameMap::generatePlatform(Vector2d* startPoint)
{
	Platform* platform = new Platform();
	int numberOfBlocks = rand() % 11 + 5;

	Vector2d* lastPoint = startPoint;

	for(int i = 0; i < numberOfBlocks; i++) {
		int type = 1;//rand() % 3;
		PlatformBlock* block;
		switch(type) {
		case 0:
			block = new PlatformBlock(INCLINE, lastPoint);
			break;
		case 1:
			block = new PlatformBlock(HORIZONTAL, lastPoint);
			break;
		case 2:
			block = new PlatformBlock(DECLINE, lastPoint);
			break;
		}
		lastPoint = block->getEndVector();
		platform->addPlatformBlock(block);
		// delete block; ??
	}
	return platform;
}
