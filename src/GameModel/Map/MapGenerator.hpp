//
//  File:	MapGenerator.hpp
//  Class	MapGenerator
//  Author	Jonatan Rapp & Alexander Hederstaf
//  Co-author Sebastian Odbjer
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 9, 2012
//
//  Description:
//  A class for randomly generating playable maps consisting of platforms.
//

#include "Platform.hpp"
#include "GeneratedBlock.hpp"
#include <set>
#include <vector>


#ifndef MAPGENERATOR_H_
#define MAPGENERATOR_H_

class MapGenerator {

private:

	vector<GeneratedBlock> recentlyUsedBuffer;
	vector<int> bufferElementCounter;

	set<GeneratedBlock> all;
	set<GeneratedBlock> zeroIncline;
	set<GeneratedBlock> zeroDecline;
	set<GeneratedBlock> plusTwo;
    set<GeneratedBlock> plusOne;
	set<GeneratedBlock> allDeltaY;
	set<GeneratedBlock> allZeroes;

	/*
	 * Returns a set of GeneratedBlocks which contain the possible
	 * blocks to place after the given block.
	 *
	 * The purpose of this method is to prevent undesirable
	 * map structures. Note though that no checks are made
	 * to obey the height limitations.
	 * see getAllowedSet()
	 */
	set<GeneratedBlock> getPossibleSet(GeneratedBlock* previousBlock);

	/*
	 * Sifts through the provided set of GeneratedBlocks, finding and
	 * removing those that may not be placed upon the starting point
	 * defined by startVector without breaking the height limitations placed
	 * by HEIGH_MAX and HEIGHT_MIN.
	 *
	 * Returns a set containing the remaining GeneratedBlocks.
	 *
	 * the possibleSet is a set of GeneretedBlocks either from the predefined sets
	 * or preferably generated through getPossibleSet().
	 */
	set<GeneratedBlock> getAllowedSet(set<GeneratedBlock> possibleSet, Vector2d* startVector);

	/*
	 * TODO:
	 */
	void modifyChances(set<GeneratedBlock>& allowedSet, Vector2d* startVector);

	/*
	 * Adds a GeneratedBlock at the end of recentlyUsedBuffer
	 * vector, and removes the first one. This way the buffer vector
	 * will always maintain the size defined in BUFFER_SIZE.
	 */
	void addToBuffer(GeneratedBlock usedBlock);

public:

	const static int HEIGHT_MIN = 1;
	const static int HEIGHT_MAX = 7;
	const static int PLATFORM_LENGTH_MIN = 5;
	const static int PLATFORM_LENGTH_MAX = 15;
	const static int BUFFER_SIZE = 20;

	/*
	 * Internal testing of private functions
	 */
	bool testFunc();

	~MapGenerator();
	MapGenerator();
	/*
	 * This function generates a new platform of random length and content
	 * which originates from the provided startpoint.
	 * - The length of a platform is PLATFORM_LENGTH_MIN - PLATFORM_LENGTH_MAX PlatformBlocks.
	 * - The height of a platform may never surpass HEIGHT_MAX, and
	 *   never go below HEIGHT_MIN.
	 * - This means that the startvector must have a y value between
	 * 	 HEIGHT_MIN and HEIGHT_MAX (or equal to either).
	 */
	Platform* generatePlatform(Vector2d* startPoint);

	/*
	 * This function generates a new platform with a specified length
	 * and content that has:
	 * - No height differences.
	 * - Only horizontal blocktypes.
	 */
	Platform* generateFlatPlatform(Vector2d* startPoint, int length);
};

#endif
