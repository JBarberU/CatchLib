//
//  File:       Platform.hpp
//  Class:      Platform
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright © 2012 by Catch22. All Rights Reserved.
//  Date: 		Sep 29, 2012
//
//	License: The following code is licensed under the Catch22-License


#include "PlatformBlock.hpp"
#include <vector>

using namespace std;

/**
 *
 * A Platform is built using one to many PlatformBlocks.
 * Platforms are used to create the game's map.
 *
 * @see PlatformBlock.hpp, GameMap.hpp
 *
 */
class Platform
{
public:
	~Platform();
	Platform();

	/**
	 * Returns a vector of the PlatformBlocks of this platform.
	 */
	vector<PlatformBlock*> getPlatformBlocks();

	/**
	 * Adds a PlatformBlock at the end of the vector of PlatformBlocks.
	 * @param block
	 * 		The PlatformBlock that is to be added.
	 */
	void addPlatformBlock(PlatformBlock* block);

	/**
	 * Removes all the PlatformBlocks in the vector.
	 */
	void clearPlatformBlocks();

	/**
	 * Returns the end point of the Platform in the form of a Vector2d.
	 */
	Vector2d* endPoint();

	/**
	 * Returns the start point of the Platform in the form of a Vector2d.
	 */
	Vector2d* startPoint();

private:
	vector<PlatformBlock*> platformblocks;

};
