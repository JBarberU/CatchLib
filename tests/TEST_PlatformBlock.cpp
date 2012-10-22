//
//  File:       TEST_PlatformBlock.cpp
//  Class:      TEST_PlatformBlock
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		09/10-2012
//

#include "../src/GameModel/Map/PlatformBlock.hpp"
#include "catch.hpp"

TEST_CASE("PlatformBlock", "Tests the PlatformBlock: creates some new platformblocks, checks that the values are correct")
{
	//Create the platformBlocks
	PlatformBlock platformblock1 = PlatformBlock(INCLINE, new Vector2d(0.0, 0.0));
	PlatformBlock platformblock2 = PlatformBlock(HORIZONTAL, new Vector2d(0.0, 0.0));
	PlatformBlock platformblock3 = PlatformBlock(DECLINE, new Vector2d(0.0, 0.0));

	//Check the values
	CHECK(platformblock1.getStartVector()->m_x == 0.0);
	CHECK(platformblock1.getStartVector()->m_y == 0.0);

	CHECK(platformblock1.getEndVector()->m_x == 2.0);
	CHECK(platformblock1.getEndVector()->m_y == 1.0);
	CHECK(platformblock2.getEndVector()->m_x == 2.0);
	CHECK(platformblock2.getEndVector()->m_y == 0.0);
	CHECK(platformblock3.getEndVector()->m_x == 2.0);
	CHECK(platformblock3.getEndVector()->m_y == -1.0);

	CHECK(platformblock1.getType() == INCLINE);
	CHECK(platformblock2.getType() == HORIZONTAL);
	CHECK(platformblock3.getType() == DECLINE);

}
