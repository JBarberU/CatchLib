//
//  TEST_PBody.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 10/8/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "catch.hpp"
#include "../src/GameModel/Physics/PBody.hpp"

TEST_CASE("PBody: Constructor", "Checks so all instance variables have the expected values.")
{
    Vector2d** v = new Vector2d*[4];
    
    v[0] = new Vector2d(-100, -119);
    v[1] = new Vector2d(-100, -60);
    v[2] = new Vector2d(-50, -60);
    v[3] = new Vector2d(-50, -119);
    
    PBody* b1 = new PBody(new Vector2dArray(v, 4), new Vector2d(0,0), true, false, true);
    
    CHECK_FALSE(b1->isStationary());
    CHECK(b1->isAffectedByGravity());
    CHECK(b1->getVectorArray()->m_size == 4);
    CHECK(b1->getVectorArray()->m_vectors[3]->m_y == -119);
        
    delete b1;
}
TEST_CASE("PBody: Force application and reversion", "Makes sure force addition, application, subtraction and reversion works as intended.")
{
    Vector2d v = Vector2d(-20, -10);
 
    Vector2d** v1 = new Vector2d*[4];
    
    v1[0] = new Vector2d(-100, -119);
    v1[1] = new Vector2d(-100, -60);
    v1[2] = new Vector2d(-50, -60);
    v1[3] = new Vector2d(-50, -119);
    
    PBody* b1 = new PBody(new Vector2dArray(v1, 4), new Vector2d(0,0), true, false, true);
    
    float dt = 10;
    
    b1->addVector(&v);
    b1->applyForce(dt);
    
    CHECK(b1->getVectorArray()->m_vectors[0]->m_x == -300);
    CHECK(b1->getVectorArray()->m_vectors[0]->m_y == -219);
    
    b1->revertForce(dt);
    b1->removeVector(&v);

    CHECK(b1->getVectorArray()->m_vectors[0]->m_x == -100);
    CHECK(b1->getVectorArray()->m_vectors[0]->m_y == -119);
        
    delete b1;
}

TEST_CASE("PBody: Collision detection rectangles", "Checks so that collision detection works as it should for rectangles.")
{
    Vector2d** v = new Vector2d*[4];
    
    v[0] = new Vector2d(0, 0);
    v[1] = new Vector2d(0, 31);
    v[2] = new Vector2d(31, 31);
    v[3] = new Vector2d(31, 0);
    
    Vector2d** v2 = new Vector2d*[4];
    
    v2[0] = new Vector2d(32, 32);
    v2[1] = new Vector2d(32, 63);
    v2[2] = new Vector2d(63, 63);
    v2[3] = new Vector2d(63, 32);
    
    PBody* b1 = new PBody(new Vector2dArray(v, 4), new Vector2d(0,0), true, false, true);
    
    PBody* b2 = new PBody(new Vector2dArray(v2, 4), new Vector2d(0,0), true, false, true);
    
    CHECK_FALSE(b1->isCollidingWithBody(b2));
    
    Vector2d v1 = Vector2d(5, 5);
    b1->addVector(&v1);
    b1->applyForce(1);
    
    CHECK(b1->getVectorArray()->m_vectors[0]->m_x == 5);
    CHECK(b1->getVectorArray()->m_vectors[0]->m_y == 5);
    
    CHECK(b1->isCollidingWithBody(b2));

    delete b1;
    delete b2;
}
TEST_CASE("PBody: Collision detection polygons", "Checks so that collision detection works as it should for other polygons.")
{
    Vector2d** v1 = new Vector2d*[3];
    
    v1[0] = new Vector2d(0,3);
    v1[1] = new Vector2d(3,0);
    v1[2] = new Vector2d(0,0);
    
    Vector2dArray* vArr1 = new Vector2dArray(v1, 3);
    PBody* b1 = new PBody(vArr1, true, false, true);
    
    Vector2d** v2 = new Vector2d*[3];
    
    v2[0] = new Vector2d(1,3);
    v2[1] = new Vector2d(3,3);
    v2[2] = new Vector2d(3,1);
    
    Vector2dArray* vArr2 = new Vector2dArray(v2, 3);
    PBody* b2 = new PBody(vArr2, true, false, true);
    
    CHECK_FALSE(b1->isCollidingWithBody(b2));
    
    
    Vector2d** v3 = new Vector2d*[3];
    
    v3[0] = new Vector2d(0,6);
    v3[1] = new Vector2d(6,0);
    v3[2] = new Vector2d(0,0);
    
    Vector2dArray* vArr3 = new Vector2dArray(v3, 3);
    PBody* b3 = new PBody(vArr3, true, false, true);
    
    Vector2d** v4 = new Vector2d*[4];
    
    v4[0] = new Vector2d(5,5);
    v4[1] = new Vector2d(6,5);
    v4[2] = new Vector2d(6,6);
    v4[3] = new Vector2d(5,6);
    
    Vector2dArray* vArr4 = new Vector2dArray(v4, 4);
    PBody* b4 = new PBody(vArr4, true, false, true);
    
    CHECK_FALSE(b3->isCollidingWithBody(b4));
    
    
    delete b1;
    delete b2;
    delete b3;
    delete b4;
}