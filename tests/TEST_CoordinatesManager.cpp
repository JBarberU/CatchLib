//
//  File:	TEST_CoordinatesManager.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/22/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//


#include "catch.hpp"
#include "../src/Helper/CoordinatesManager.hpp"
#include "../src/Math/Vector2d.hpp"

TEST_CASE("CoordinatesManager screen coordinates", "Convert world to screen coordinates")
{
    Vector2d v = *CoordinatesManager::getSharedInstance()->getScreenCoordinates(Vector2d(10.f, 12.f));
    CHECK(v.m_x == 10.f);
    CHECK(v.m_y == 12.f);
}

TEST_CASE("CoordinatesManager world coordinates", "Convert screen to world coordinates")
{
    Vector2d v2 = *CoordinatesManager::getSharedInstance()->getWorldCoordinates(Vector2d(5.f, 7.f));
    CHECK(v2.m_x == 5.f);
    CHECK(v2.m_y == 7.f);
}
TEST_CASE("CoordinatesManager update", "Tests update method.")
{
    CoordinatesManager::getSharedInstance()->updateWorldCoordinate(Vector2d(10.f, 13.f));
    
    Vector2d s1 = Vector2d(2.f, 5.f);
    Vector2d s2 = Vector2d(4.f, 6.f);
    Vector2d w1 = Vector2d(10.f, 7.f);
    
    Vector2d v1 = *CoordinatesManager::getSharedInstance()->getScreenCoordinates(w1);
    CHECK(v1.m_x == 0.f);
    CHECK(v1.m_y == -6.f);
    
    Vector2d v12 = Vector2d(0.f, 0.f);
    CoordinatesManager::getSharedInstance()->getScreenCoordinates(w1, v12);
    CHECK(v12.m_x == 0.f);
    CHECK(v12.m_y == -6.f);
    
    Vector2d v2 = *CoordinatesManager::getSharedInstance()->getWorldCoordinates(s1);
    CHECK(v2.m_x == 12.f);
    CHECK(v2.m_y == 18.f);
    
    Vector2d v21 = Vector2d(0.f, 0.f);
    CoordinatesManager::getSharedInstance()->getWorldCoordinates(s1, v21);
    CHECK(v21.m_x == 12.f);
    CHECK(v21.m_y == 18.f);
    
    CoordinatesManager::getSharedInstance()->updateWorldCoordinate(Vector2d(1337.f, 42.f));
    
    Vector2d v3 = *CoordinatesManager::getSharedInstance()->getWorldCoordinates(s2);
    CHECK(v3.m_x == 1341.f);
    CHECK(v3.m_y == 48.f);
    
    Vector2d v31 = Vector2d(0.f, 0.f);
    CoordinatesManager::getSharedInstance()->getWorldCoordinates(s2, v31);
    CHECK(v31.m_x == 1341.f);
    CHECK(v31.m_y == 48.f);
    
}
