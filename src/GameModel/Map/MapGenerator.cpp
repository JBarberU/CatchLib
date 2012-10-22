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
//	License: The following code is licensed under the Catch22-License
//

#include "MapGenerator.hpp"
#include <algorithm>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include "../../Helper/Logger.hpp"

// All possible GeneratedBlocks
const GeneratedBlock Ip2 = GeneratedBlock(2, INCLINE, 4);
const GeneratedBlock Hp2 = GeneratedBlock(2, HORIZONTAL, 4);

const GeneratedBlock Ip1 = GeneratedBlock(1, INCLINE, 4);
const GeneratedBlock Hp1 = GeneratedBlock(1, HORIZONTAL, 4);

const GeneratedBlock I0 = GeneratedBlock(0, INCLINE, 64);
const GeneratedBlock H0 = GeneratedBlock(0, HORIZONTAL, 244);
const GeneratedBlock D0 = GeneratedBlock(0, DECLINE, 64);

const GeneratedBlock Hn1 = GeneratedBlock(-1, HORIZONTAL, 4);
const GeneratedBlock Dn1 = GeneratedBlock(-1, DECLINE, 4);

const GeneratedBlock Hn2 = GeneratedBlock(-2, HORIZONTAL, 4);
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

	plusOne.insert(Ip1);
	plusOne.insert(Hp1);

	allZeroes.insert(I0);
	allZeroes.insert(H0);
	allZeroes.insert(D0);

	allDeltaY.insert(Ip2);
	allDeltaY.insert(Hp2);
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
	set<GeneratedBlock> allowedSet;
	set<GeneratedBlock>::iterator it;
	for (it = possibleSet.begin(); it != possibleSet.end(); it++) {
		int dy = (*it).dy;
		int t = (*it).type;
		t = dy + (-1) * (t - 1); // t is now an int representing deltaY added by slope type.
		if (((startVector->m_y + t) <= HEIGHT_MAX && (startVector->m_y + t) >= HEIGHT_MIN)
				&& (startVector->m_y <= HEIGHT_MAX && startVector->m_y >= HEIGHT_MIN)) {
			// Only keep GeneratedBlocks that stay within the allowed height margin
			allowedSet.insert(*it);
		}
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
		block.chance -=  2 * bufferElementCounter[distance(all.begin(), all.find(block))];
		if ((block.dy + ((-1) * (block.type - 1)) < 0 && startVector->m_y < 4)
				|| (block.dy + ((-1) * (block.type - 1)) > 0 && startVector->m_y > 4)) {
			int z = abs((int) (startVector->m_y - 4));
			if (z == 1) {
				block.chance *= 3;
			}
			if (z == 2) {
				block.chance *= 2;
			}
			block.chance /= 4;
		}
		allowedSet.erase(*it);
		allowedSet.insert(block);
	}
}

GeneratedBlock* MapGenerator::selectBlock(set<GeneratedBlock> allowedSet)
{
	set<GeneratedBlock>::iterator it;
	int totalChance = 0;
	for (it = allowedSet.begin(); it != allowedSet.end(); ++it) {
		totalChance += (*it).chance;
	}

	if (totalChance == 0) {
		// set is empty or sum of chance in all blocks are zero
		return 0;
	}

	int roll = (rand() % totalChance) + 1;
	for (it = allowedSet.begin(); it != allowedSet.end(); ++it) {
		if (roll <= (*it).chance) {
			break;
		} else {
			roll-=(*it).chance;
		}
	}
	return *it;
}



Platform* MapGenerator::generatePlatform(Vector2d* startVector)
{
	// 1. get possible set
	// 2. get allowed set
	// 3. modify chance (using buffer & deltaY)
	// 4. select GeneratedBlock
	// 5. add platformblock to platform
	// 6. add used GeneratedBlock to buffer

	Platform* platform = new Platform();

	set<GeneratedBlock> possibleSet = allZeroes;
	set<GeneratedBlock> allowedSet = getAllowedSet(possibleSet, startVector);
	modifyChances(allowedSet, startVector);
	GeneratedBlock* selectedBlock = selectBlock(allowedSet);

	PlatformBlock* block = new PlatformBlock(selectedBlock->type, startVector);
	platform->addPlatformBlock(block);

	Vector2d* newStartVector = block->getEndVector();

	addToBuffer(*selectedBlock);

	int length = (PLATFORM_LENGTH_MIN - 1) + (rand() % (2 + PLATFORM_LENGTH_MAX - PLATFORM_LENGTH_MIN));

	for (int i = 0; i < length; i++) {

		possibleSet = getPossibleSet(selectedBlock);
		allowedSet = getAllowedSet(possibleSet, newStartVector);
		modifyChances(allowedSet, newStartVector);
		selectedBlock = selectBlock(allowedSet);

		*newStartVector+=Vector2d(0.f, selectedBlock->dy);

		block = new PlatformBlock(selectedBlock->type, newStartVector);
		platform->addPlatformBlock(block);

		newStartVector = block->getEndVector();

		addToBuffer(*selectedBlock);
	}

	return platform;
}

Platform* MapGenerator::generateFlatPlatform(Vector2d* startVector, int length)
{
	Platform* platform = new Platform();
	for (int i = 0; i < length; i++) {
		PlatformBlock* block = new PlatformBlock(HORIZONTAL, startVector);
		platform->addPlatformBlock(block);
		startVector = block->getEndVector();
	}
	return platform;
}
