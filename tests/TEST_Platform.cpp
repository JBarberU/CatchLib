//
//  File:		PlatformBlock.cpp
//  Class:      PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		22/10-2012
//
//	License: The following code is licensed under the Catch22-License
//

#include "../src/GameModel/Map/Platform.hpp"
#include "catch.hpp"

TEST_CASE("Platform", "Tests the Platform: creates a new platform and then checks it's values")
{
	PlatformBlock* platformblock1 = new PlatformBlock(INCLINE, new Vector2d(0.0, 0.0));
	PlatformBlock* platformblock2 = new PlatformBlock(HORIZONTAL, new Vector2d(2.0, 1.0));
	PlatformBlock* platformblock3 = new PlatformBlock(DECLINE, new Vector2d(4.0, 1.0));

	Platform platform = Platform();
	platform.addPlatformBlock(platformblock1);
	platform.addPlatformBlock(platformblock2);
	platform.addPlatformBlock(platformblock3);

	CHECK(platform.startPoint()->m_x == 0.0);
	CHECK(platform.startPoint()->m_y == 0.0);
	CHECK(platform.endPoint()->m_x == 6.0);
	CHECK(platform.endPoint()->m_y == 0.0);


}
