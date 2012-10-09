//
//  TEST_Vector2D.cpp
//  test
//
//  Created by Jesper Persson on 2012-10-05.
//  Copyright (c) Catch22. All rights reserved.
//

#include "catch.hpp"
#include "Vector2d.hpp"

TEST_CASE("Test Vector2D", "Testing basic vetor operations")
{
    
    Vector2d vecA(1.0, 1.0);
    Vector2d vecB(2.0, 2.0);
    Vector2d vecC(1.0, 2.0);
    //Make sure the vectors initiated with correct values.
    REQUIRE(vecA.m_x < vecB.m_x);
    REQUIRE(vecA.m_y < vecB.m_y);
    
    //Test the += operator
    vecA +=(vecB);
    REQUIRE(vecA.m_x > vecB.m_x);
    REQUIRE(vecA.m_y > vecB.m_y);
    
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
