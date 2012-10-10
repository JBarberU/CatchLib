//
//  File:	MapGenerator.cpp
//  Class	MapGenerator
//  Author	Jonatan Rapp
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 9, 2012
//
//  Description:
//
//

#include "MapGenerator.hpp"

MapGenerator::~MapGenerator()
{

}

MapGenerator::MapGenerator()
{
	all.insert(new GeneratedBlock(2, INCLINE));
	all.insert(new GeneratedBlock(2, HORIZONTAL));
	all.insert(new GeneratedBlock(2, DECLINE));
	all.insert(new GeneratedBlock(1, INCLINE));
	all.insert(new GeneratedBlock(1, HORIZONTAL));
	all.insert(new GeneratedBlock(0, INCLINE));
	all.insert(new GeneratedBlock(0, HORIZONTAL));
	all.insert(new GeneratedBlock(0, DECLINE));
	all.insert(new GeneratedBlock(-1, HORIZONTAL));
	all.insert(new GeneratedBlock(-1, DECLINE));
	all.insert(new GeneratedBlock(-2, HORIZONTAL));

	zeroIncline.insert(new GeneratedBlock(0, INCLINE));

	zeroDecline.insert(new GeneratedBlock(0, DECLINE));

	plusTwo.insert(new GeneratedBlock(2, INCLINE));
	plusTwo.insert(new GeneratedBlock(2, HORIZONTAL));
	plusTwo.insert(new GeneratedBlock(2, DECLINE));

	plusOne.insert(new GeneratedBlock(1, INCLINE));
	plusOne.insert(new GeneratedBlock(1, HORIZONTAL));

	allZeroes.insert(new GeneratedBlock(0, INCLINE));
	allZeroes.insert(new GeneratedBlock(0, HORIZONTAL));
	allZeroes.insert(new GeneratedBlock(0, DECLINE));

	allDeltaY.insert(new GeneratedBlock(2, INCLINE));
	allDeltaY.insert(new GeneratedBlock(2, HORIZONTAL));
	allDeltaY.insert(new GeneratedBlock(2, DECLINE));
	allDeltaY.insert(new GeneratedBlock(1, INCLINE));
	allDeltaY.insert(new GeneratedBlock(1, HORIZONTAL));
	allDeltaY.insert(new GeneratedBlock(-1, HORIZONTAL));
	allDeltaY.insert(new GeneratedBlock(-1, DECLINE));
	allDeltaY.insert(new GeneratedBlock(-2, HORIZONTAL));
}

set<GeneratedBlock*> getPossibleSet(GeneratedBlock* previousBlock)
{
	if (previousBlock->type == DECLINE) {
		// remove zeroIncline
	} else if (previousBlock->type == INCLINE) {
		// remove zeroDecline
	}

	if (previousBlock->dy != 0) {
		// remove allDeltaY
	} else {
		if (previousBlock->type != HORIZONTAL) {
			// remove plusTwo
		}
		if (previousBlock->type == DECLINE) {
			// remove plusOne
		}
	}
	if (previousBlock->dy < 0) {
		// remove zeroIncline
	}

}


set<GeneratedBlock*> MapGenerator::getAllowedSet(set<GeneratedBlock*> possibleSet)
{
	return all;
}


Platform* MapGenerator::generatePlatform(Vector2d* startVector)
{
	return 0;
}

Platform* MapGenerator::generateFlatPlatform(Vector2d* startVector, int length)
{
	return 0;
}
