//
//  Platform.hpp
//  CatchLib
//
//  Created by Jesper Persson on 9/29/12.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
//	This class is for representing a Platform in a GameMap.
//	Each Platform is made up by several PlatformBlocks.
//
//

#include "PlatformBlock.hpp"
#include <vector>

class Platform
{
public:
	~Platform();
	Platform();
	vector<PlatformBlocks*> const &getPlatformBlocks() const;

private:
	vector<PlatformBlock*> platformblocks;
};
