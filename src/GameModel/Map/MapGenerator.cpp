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
#include <algorithm>
#include <stdio.h>

MapGenerator::~MapGenerator()
{

}

MapGenerator::MapGenerator()
{
	all.insert(GeneratedBlock(2, INCLINE));
	all.insert(GeneratedBlock(2, HORIZONTAL));
	all.insert(GeneratedBlock(2, DECLINE));
	all.insert(GeneratedBlock(1, INCLINE));
	all.insert(GeneratedBlock(1, HORIZONTAL));
	all.insert(GeneratedBlock(0, INCLINE));
	all.insert(GeneratedBlock(0, HORIZONTAL));
	all.insert(GeneratedBlock(0, DECLINE));
	all.insert(GeneratedBlock(-1, HORIZONTAL));
	all.insert(GeneratedBlock(-1, DECLINE));
	all.insert(GeneratedBlock(-2, HORIZONTAL));

	zeroIncline.insert(GeneratedBlock(0, INCLINE));

	zeroDecline.insert(GeneratedBlock(0, DECLINE));

	plusTwo.insert(GeneratedBlock(2, INCLINE));
	plusTwo.insert(GeneratedBlock(2, HORIZONTAL));
	plusTwo.insert(GeneratedBlock(2, DECLINE));

	plusOne.insert(GeneratedBlock(1, INCLINE));
	plusOne.insert(GeneratedBlock(1, HORIZONTAL));

	allZeroes.insert(GeneratedBlock(0, INCLINE));
	allZeroes.insert(GeneratedBlock(0, HORIZONTAL));
	allZeroes.insert(GeneratedBlock(0, DECLINE));

	allDeltaY.insert(GeneratedBlock(2, INCLINE));
	allDeltaY.insert(GeneratedBlock(2, HORIZONTAL));
	allDeltaY.insert(GeneratedBlock(2, DECLINE));
	allDeltaY.insert(GeneratedBlock(1, INCLINE));
	allDeltaY.insert(GeneratedBlock(1, HORIZONTAL));
	allDeltaY.insert(GeneratedBlock(-1, HORIZONTAL));
	allDeltaY.insert(GeneratedBlock(-1, DECLINE));
	allDeltaY.insert(GeneratedBlock(-2, HORIZONTAL));
}

set<GeneratedBlock> MapGenerator::getPossibleSet(GeneratedBlock* previousBlock)
{
	set<GeneratedBlock> possibleSet = all;

	if (!previousBlock)  {
		return possibleSet;
	}

	if (previousBlock->type == DECLINE) {
		// remove zeroIncline
		set<GeneratedBlock> tmp;
		set_difference(possibleSet.begin(), possibleSet.end(), zeroIncline.begin(), zeroIncline.end(), inserter(tmp, tmp.end()));
		possibleSet = tmp;
	} else if (previousBlock->type == INCLINE) {
		// remove zeroDecline
		set<GeneratedBlock> tmp;
		set_difference(possibleSet.begin(), possibleSet.end(), zeroDecline.begin(), zeroDecline.end(), inserter(tmp, tmp.end()));
		possibleSet = tmp;
	}

	if (previousBlock->dy != 0) {
		// remove allDeltaY
		set<GeneratedBlock> tmp;
		set_difference(possibleSet.begin(), possibleSet.end(), allDeltaY.begin(), allDeltaY.end(), inserter(tmp, tmp.end()));
		possibleSet = tmp;
	} else {
		if (previousBlock->type != HORIZONTAL) {
			// remove plusTwo
			set<GeneratedBlock> tmp;
			set_difference(possibleSet.begin(), possibleSet.end(), plusTwo.begin(), plusTwo.end(), inserter(tmp, tmp.end()));
			possibleSet = tmp;
		}
		if (previousBlock->type == DECLINE) {
			// remove plusOne
			set<GeneratedBlock> tmp;
			set_difference(possibleSet.begin(), possibleSet.end(), plusOne.begin(), plusOne.end(), inserter(tmp, tmp.end()));
			possibleSet = tmp;
		}
	}
	if (previousBlock->dy < 0) {
		// remove zeroIncline
		set<GeneratedBlock> tmp;
		set_difference(possibleSet.begin(), possibleSet.end(), zeroIncline.begin(), zeroIncline.end(), inserter(tmp, tmp.end()));
		possibleSet = tmp;
	}
	return possibleSet;
}


set<GeneratedBlock> MapGenerator::getAllowedSet(set<GeneratedBlock> possibleSet, Vector2d* startVector)
{
	set<GeneratedBlock> tmp = possibleSet;
	set<GeneratedBlock> allowedSet;
	int nbr = tmp.size();
	for (int i = 0; i < nbr; i++) {
		set<GeneratedBlock>::iterator it = tmp.begin();
		int dy = (&*it)->dy;
		int t = (&*it)->type;
		t = dy + (-1) * (t - 1); // t is now an int representing deltaY added by slope type.
		if (((startVector->m_y + t) <= HEIGHT_MAX && (startVector->m_y + t) >= HEIGHT_MIN)
				&& (startVector->m_y <= HEIGHT_MAX && startVector->m_y >= HEIGHT_MIN)) {
			// Only keep GeneratedBlocks that stay within the allowed height margin
			allowedSet.insert(*it);
		}
		tmp.erase(it);
	}
	return allowedSet;
}


Platform* MapGenerator::generatePlatform(Vector2d* startVector)
{
	return 0;
}

Platform* MapGenerator::generateFlatPlatform(Vector2d* startVector, int length)
{
	return 0;
}

bool MapGenerator::testFunc()
{
	printf("Size all = %i\n", (int)all.size());

	set<GeneratedBlock> testSet = 	getPossibleSet(0);
	printf("Size (input: 0) = %i\n", (int)testSet.size());

	GeneratedBlock* lastBlock = new GeneratedBlock(0, HORIZONTAL);

	testSet = getPossibleSet(lastBlock);
	printf("Size (input: -2,H) = %i\n", (int)testSet.size());

	testSet = getAllowedSet(testSet, new Vector2d(0, 4));

	printf("Size (input: -2,H) (0, 4) = %i\n", (int)testSet.size());

	int nbr = testSet.size();
	for (int i = 0; i < nbr; i++) {
		set<GeneratedBlock>::iterator it = testSet.begin();
		int y = (&*it)->dy;
		int t = (&*it)->type;
		printf("Element #%i: dy: %i, type %i\n", i, y, t);
		testSet.erase(it);
	}
	return true;
}
