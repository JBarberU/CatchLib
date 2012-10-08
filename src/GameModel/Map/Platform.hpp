//
//  File:       Platform.hpp
//  Class:      Platform
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		29/09-2012
//
//  Description:
//	This class is for representing a Platform in a GameMap.
//	Each Platform is made up by several PlatformBlocks.
//
//

#include "PlatformBlock.hpp"
#include <vector>

using namespace std;

class Platform
{
public:
	~Platform();
	Platform();
	vector<PlatformBlock*> getPlatformBlocks();
	void addPlatformBlock(PlatformBlock* block);
	void clearPlatformBlocks();
	Vector2d* endPoint();
	Vector2d* startPoint();

private:
	vector<PlatformBlock*> platformblocks;

};
