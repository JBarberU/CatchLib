//
//  File:	TEST_Math.cpp
//  Author: John Barbero Unenge 
//	Date:  	10/11/12.
//
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//
//	All code is my own except where credited to others.
//

#include "catch.hpp"

#include "../src/Math/Math.hpp"

#include "../src/Helper/Logger.hpp"

TEST_CASE("Math: Unit vector", "Tests that unit vectors are generated correctly.")
{
    Vector2d* v1 = new Vector2d(3, 4);
    
    Vector2d* r1 = Math::generateUnitVectorOf(v1);
    
    CHECK(r1->m_x == 0.6);
    CHECK(r1->m_y == 0.8);
    
    delete r1;
    delete v1;
    
    Vector2d* v2 = new Vector2d(-4,3);
    
    Vector2d* r2 = Math::generateUnitVectorOf(v2);
    
    CHECK(r2->m_x == -0.8);
    CHECK(r2->m_y == 0.6);
    
    delete r2;
    delete v2;
    
    for (int i = -4; i < 5; i++) {
    
        for (int k = -4; k < 5; k++) {
        
            Vector2d* v3 = new Vector2d(i, k);
    
            Vector2d* r3 = Math::generateUnitVectorOf(v3);
    
            float squareSum = r3->m_x * r3->m_x + r3->m_y * r3->m_y;
            
            bool closeEnough = (squareSum < 1.001 && squareSum > 0.999);
            
            if (i == 0 && k == 0)
                CHECK((r3->m_x == 0 && r3->m_y == 0));
            else
                CHECK((squareSum == 1 || closeEnough));
        
            delete r3;
            delete v3;
        }
    }
}
