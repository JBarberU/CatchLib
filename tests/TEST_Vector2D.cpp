//
//  TEST_Vector2D.cpp
//  test
//
//  Created by Jesper Persson on 2012-10-05.
//  Copyright (c) Catch22. All rights reserved.
//

#include "catch.hpp"
#include "../src/Math/Vector2d.hpp"
#include "../src/Helper/Logger.hpp"

TEST_CASE("Vector2D: Constructor", "Testing non trivial constructors")
{
    Vector2d* v1 = new Vector2d(1.0, 1.0);
    double mag = 7.071067811865476;
    
    Vector2d* v2 = new Vector2d(v1, mag);
    
    CHECK((v2->m_x > 4.999 && v2->m_x < 5.001));
    CHECK((v2->m_y > 4.999 && v2->m_y < 5.001));
    
    Log(LOG_INFO, "Test_Vector2d", generateCString("X,Y: %d, %d", v2->m_x, v2->m_y));
}

TEST_CASE("Test Vector2D", "Testing basic vetor operations")
{
    
    Vector2d vecA(1.0, 1.0);
    Vector2d vecB(2.0, 2.0);
    Vector2d vecC(1.0, 2.0);
    //Make sure the vectors initiated with correct values.
    REQUIRE(vecA.m_x == 1.0);
    REQUIRE(vecA.m_y == 1.0);
    REQUIRE(vecB.m_x == 2.0);
    REQUIRE(vecB.m_y == 2.0);    
    //Test the += operator
    vecA +=(vecB);
    REQUIRE(vecA.m_x == 1.0 + 2.0);
    REQUIRE(vecA.m_y == 1.0 + 2.0);
    
    //Test the ==, = and the -= operators
    vecA -=(vecC);
    REQUIRE(vecA.m_x == 2.0);
    REQUIRE(vecA.m_y == 1.0);
    
    vecA=(vecC);
    REQUIRE(vecA == vecC);
    
    //Test the *= operator
    vecC*=(2.0);
    REQUIRE(vecC.m_x == 2.0);
    REQUIRE(vecC.m_y == 4.0);
    vecC*=(-4.0);
    REQUIRE(vecC.m_x == -8.0);
    REQUIRE(vecC.m_y == -16.0);
    
    //  Test the scalar multiplication operator (Vector2d * double)
    Vector2d v1 = Vector2d(10,9);
    Vector2d v2 = v1 * 2.0;
    REQUIRE(v2.m_x == 20);
    REQUIRE(v2.m_y == 18);
    
    v1 = new Vector2d(-10,9);
    v2 = v1 * -20.0;
    REQUIRE(v2.m_x == 200);
    REQUIRE(v2.m_y == -180);
    
}
