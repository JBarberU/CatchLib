//
//  PlatformPoint.hpp
//  CatchLib
//
//  Created by Jesper Persson on 9/29/12.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
//	A class for representing a Point in a Platform.
//	Each PlatformPoint will help shape the outline of a Platform in the GameMap.
//

#include "PBody.hpp"

class PlatformPoint: public PBody
{
public:
	~PlatformPoint();
	PlatformPoint();
};
