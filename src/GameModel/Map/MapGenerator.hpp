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
//  A class for randomly generating platforms used by the GameMap.
//

#include "Platform.hpp"
#include "GeneratedBlock.hpp"
#include <set>
#include <vector>


#ifndef MAPGENERATOR_H_
#define MAPGENERATOR_H_

class MapGenerator {

private:

	/*
	 * Buffer with recently used blocks to prevent excessive placement of the
	 * same blocks.
	 */
	vector<GeneratedBlock> recentlyUsedBuffer;
	vector<int> bufferElementCounter;

	/*
	 * Basic sets used to calculate new sets by difference.
	 */
	set<GeneratedBlock> all;
	set<GeneratedBlock> zeroIncline;
	set<GeneratedBlock> zeroDecline;
	set<GeneratedBlock> plusTwo;
    set<GeneratedBlock> plusOne;
	set<GeneratedBlock> allDeltaY;
	set<GeneratedBlock> allZeroes;

	/**
	 * Returns a set of GeneratedBlocks which contain the possible
	 * blocks to place after the given block.
	 *
	 * The purpose of this method is to prevent undesirable map structures.
	 * Note though that no checks are made to obey the height limitations.
	 * see getAllowedSet()
	 *
	 * @param previousBlock
	 *		The block preceding this one in a Platform. 0 if there was no
	 *		preceding block.
	 * @return
	 * 		A set containing only the GeneratedBlocks that can be placed after
	 * 		the preceding one.
	 */
	set<GeneratedBlock> getPossibleSet(GeneratedBlock* previousBlock);

	/**
	 * Sifts through the provided set of GeneratedBlocks, finding and
	 * removing those that may not be placed upon the starting point
	 * defined by startVector without breaking the height limitations placed
	 * by HEIGH_MAX and HEIGHT_MIN.
	 *
	 * @param possibleSet
	 *		the possibleSet is a set of GeneretedBlocks either from the
	 *		predefined sets or preferably generated through getPossibleSet().
	 * @param startVector
	 *		The position where the Block will be placed.
	 * @return
	 *		A set containing the remaining GeneratedBlocks after illegal ones have
	 *		been removed.
	 */
	set<GeneratedBlock> getAllowedSet(set<GeneratedBlock> possibleSet, Vector2d* startVector);

	/**
	 * Modifies chances of all GeneratedBlocks in a set using recentlyUsedBuffer
	 * and vector position of the new GeneratedBlock.
	 *
	 * A GeneratedBlock going down has reduced chance if you are under the mid level
	 * and a GeneratedBlock going up has reduced chance if you are over the mid level.
	 *
	 * @param allowedSet
	 * 		The set of GeneratedBlocks that will have their chances modified.
	 * @param startVector
	 * 		The Vector2d representing the start position of the allowed GeneratedBlocks
	 */
	void modifyChances(set<GeneratedBlock>& allowedSet, Vector2d* startVector);

	/**
	 * Randomly selects a GeneratedBlock from a set of allowed GeneratedBlocks.
	 * The chance of a certain Block is based on the chance value of that Block.
	 *
	 * @param allowedSet
	 * 		The set to select a GeneratedBlock from.
	 * @return
	 * 		The selected GeneratedBlock.
	 */
	GeneratedBlock* selectBlock(set<GeneratedBlock> allowedSet);

	/**
	 * Adds a GeneratedBlock at the end of recentlyUsedBuffer
	 * vector, and removes the first one. This way the buffer vector
	 * will always maintain the size defined in BUFFER_SIZE.
	 *
	 * @param usedBlock
	 * 		The GeneratedBlock to add to the end of the buffer.
	 */
	void addToBuffer(GeneratedBlock usedBlock);

public:

	const static int HEIGHT_MIN = 1;
	const static int HEIGHT_MAX = 7;
	const static int PLATFORM_LENGTH_MIN = 7;
	const static int PLATFORM_LENGTH_MAX = 12;
	const static int BUFFER_SIZE = 20;

	~MapGenerator();
	MapGenerator();

	/**
	 * This function generates a new platform of random length and content
	 * which originates from the provided startPoint.
	 * The height of a platform may never surpass HEIGHT_MAX, and
	 * never go below HEIGHT_MIN.
	 *
	 * @param startPoint
	 * 		The point this platform will originate from.
	 * 		HEIGHT_MIN <= startPoint.y <= HEIGHT_MAX.
	 * @return
	 * 		A random generated platform of length PLATFORM_LENGTH_MIN
	 * 		to PLATFORM_LENGTH_MAX PlatformBlocks.
	 */
	Platform* generatePlatform(Vector2d* startPoint);

	/**
	 * This function generates a new platform with a specified length
	 * and content that has no height differences and only horizontal blocks.
	 *
	 * @param startPoint
	 * 		The point this platform will originate from.
	 * 		HEIGHT_MIN <= startPoint.y <= HEIGHT_MAX.
	 * @param length
	 * 		Length of the platform.
	 * @return
	 * 		A flat platform at the same height as the startPoint
	 * 		and of given length.
	 */
	Platform* generateFlatPlatform(Vector2d* startPoint, int length);
};

#endif
