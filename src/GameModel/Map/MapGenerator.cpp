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
	all.insert(Ip2);
	all.insert(Hp2);
	all.insert(Dp2);
	all.insert(Ip1);
	all.insert(Hp1);
	all.insert(I0);
	all.insert(H0);
	all.insert(D0);
	all.insert(Hn1);
	all.insert(Dn1);
	all.insert(Hn2);

	zeroIncline.insert(I0);

	zeroDecline.insert(D0);

	plusTwo.insert(Ip2);
	plusTwo.insert(Hp2);
	plusTwo.insert(Dp2);

	plusOne.insert(Ip1);
	plusOne.insert(Hp1);

	allZeroes.insert(I0);
	allZeroes.insert(H0);
	allZeroes.insert(D0);

	allDeltaY.insert(Ip2);
	allDeltaY.insert(Hp2);
	allDeltaY.insert(Dp2);
	allDeltaY.insert(Ip1);
	allDeltaY.insert(Hp1);
	allDeltaY.insert(Hn1);
	allDeltaY.insert(Dn1);
	allDeltaY.insert(Hn2);
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

	GeneratedBlock lastBlock = H0;

	testSet = getPossibleSet(&lastBlock);
	printf("Size (input: 0,H) = %i\n", (int)testSet.size());

	testSet = getAllowedSet(testSet, new Vector2d(0, 4));

	printf("Size (input: 0,H) V(0, 4) = %i\n", (int)testSet.size());

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
