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

class MapGenerator {

private:

	set<GeneratedBlock*> all;

	set<GeneratedBlock*> zeroIncline;

	set<GeneratedBlock*> zeroDecline;

	set<GeneratedBlock*> plusTwo;

    set<GeneratedBlock*> plusOne;

	set<GeneratedBlock*> allDeltaY;

	set<GeneratedBlock*> allZeroes;

	/*
	 * Returns a set of GeneratedBlocks which contain the allowed
	 * blocks to place after the given block.
	 */
	set<GeneratedBlock*> getPossibleSet(GeneratedBlock* previousBlock);

	/*
	 *
	 */
	set<GeneratedBlock*> getAllowedSet(set<GeneratedBlock*> possibleSet);

public:

	const static int HEIGHT_MIN = 1;
	const static int HEIGHT_MAX = 7;
	const static int PLATFORM_LENGTH_MIN = 5;
	const static int PLATFORM_LENGTH_MAX = 15;

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

