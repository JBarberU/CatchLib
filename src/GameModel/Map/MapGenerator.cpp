//
//  File:	MapGenerator.cpp
//  Class	MapGenerator
//  Author	Jonatan Rapp & Alexander Hederstaf
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
#include <math.h>
#include <stdio.h>

// All possible GeneratedBlocks
const GeneratedBlock Ip2 = GeneratedBlock(2, INCLINE, 12);
const GeneratedBlock Hp2 = GeneratedBlock(2, HORIZONTAL, 12);
const GeneratedBlock Dp2 = GeneratedBlock(2, DECLINE, 8);

const GeneratedBlock Ip1 = GeneratedBlock(1, INCLINE, 16);
const GeneratedBlock Hp1 = GeneratedBlock(1, HORIZONTAL, 16);

const GeneratedBlock I0 = GeneratedBlock(0, INCLINE, 52);
const GeneratedBlock H0 = GeneratedBlock(0, HORIZONTAL, 300);
const GeneratedBlock D0 = GeneratedBlock(0, DECLINE, 52);

const GeneratedBlock Hn1 = GeneratedBlock(-1, HORIZONTAL, 20);
const GeneratedBlock Dn1 = GeneratedBlock(-1, DECLINE, 20);

const GeneratedBlock Hn2 = GeneratedBlock(-2, HORIZONTAL, 12);
// End of GeneratedBlocks

MapGenerator::~MapGenerator()
{

}

MapGenerator::MapGenerator()
{
	recentlyUsedBuffer.resize(BUFFER_SIZE, H0);
	bufferElementCounter.resize(11, 0);
	bufferElementCounter[4] = 20; //20x Horizontal dy = 0 blocks

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

void MapGenerator::addToBuffer(GeneratedBlock usedBlock)
{
	vector<GeneratedBlock>::iterator it = recentlyUsedBuffer.begin();
	recentlyUsedBuffer.erase(recentlyUsedBuffer.begin());
	GeneratedBlock removed = *it;
	int position = distance(all.begin(), all.find(removed));
	bufferElementCounter[position]--;

	recentlyUsedBuffer.push_back(usedBlock);
	position = distance(all.begin(), all.find(usedBlock));
	bufferElementCounter[position]++;
}

void MapGenerator::modifyChances(set<GeneratedBlock>& allowedSet, Vector2d* startVector)
{
	set<GeneratedBlock>::iterator it;
	for (it = allowedSet.begin(); it != allowedSet.end(); ++it) {
		GeneratedBlock block = *it;
		block.baseChance -=  2 * bufferElementCounter[distance(all.begin(), all.find(block))];
		if ((block.dy + ((-1) * (block.type - 1)) < 0 && startVector->m_y < 4)
				|| (block.dy + ((-1) * (block.type - 1)) > 0 && startVector->m_y > 4)) {
			int z = abs((int) (startVector->m_y - 4));
			if (z == 1) {
				block.baseChance *= 3;
			}
			if (z == 2) {
				block.baseChance *= 2;
			}
			block.baseChance /= 4;
		}
		allowedSet.erase(*it);
		allowedSet.insert(block);
	}
}



Platform* MapGenerator::generatePlatform(Vector2d* startVector)
{
	// 1. get possible set
	// 2. get allowed set
	// 3. modify chance (using buffer & deltaY)
	// 4. select GeneratedBlock
	// 5. add platformblock to platform
	// 6. add used GeneratedBlock to buffer
	return 0;
}

Platform* MapGenerator::generateFlatPlatform(Vector2d* startVector, int length)
{
	return 0;
}

bool MapGenerator::testFunc()
{
	printf("Size all = %i\n", (int)all.size());

	set<GeneratedBlock> testSet = getPossibleSet(0);
	printf("Size (input: 0) = %i\n", (int)testSet.size());

	GeneratedBlock lastBlock = H0;

	testSet = getPossibleSet(&lastBlock);
	printf("Size (input: 0,H) = %i\n", (int)testSet.size());

	testSet = getAllowedSet(testSet, new Vector2d(0, 5));

	printf("Size (input: 0,H) V(0, 3) = %i\n", (int)testSet.size());

	int nbr = testSet.size();
	set<GeneratedBlock> printSet = testSet;
	printf("allowedSet --------\n");
	for (int i = 0; i < nbr; i++) {
		set<GeneratedBlock>::iterator it = printSet.begin();
		int y = (&*it)->dy;
		int t = (&*it)->type;
		int c = (&*it)->baseChance;
		printf("Element #%i: dy: %i, type %i, chance %i\n", i, y, t, c);
		printSet.erase(it);
	}

	modifyChances(testSet, new Vector2d(0, 5));

	printf("After modifyChances()--------\n");
	printSet = testSet;
	for (int i = 0; i < nbr; i++) {
		set<GeneratedBlock>::iterator it = printSet.begin();
		int y = (&*it)->dy;
		int t = (&*it)->type;
		int c = (&*it)->baseChance;
		printf("Element #%i: dy: %i, type %i, chance %i\n", i, y, t, c);
		printSet.erase(it);
	}
	return true;
}
