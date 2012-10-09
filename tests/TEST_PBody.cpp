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
    PBody* b1 = new PBody(true, false, new Vector2d(-100, -119), new Vector2d(50, 59), new Vector2d(-0, 951));
    
    CHECK(b1->getPosition()->m_x == -100);
    CHECK(b1->getPosition()->m_y == -119);
    CHECK(b1->getSize()->m_x == 50);
    CHECK(b1->getSize()->m_y == 59);
    CHECK(b1->isAffectedByGravity() == true);
    CHECK(b1->isStationary() == false);
    
    delete b1;
    
    b1 = new PBody(false, true, new Vector2d(-100, -119), new Vector2d(50, 59), new Vector2d(-0, 951));
    CHECK(b1->isAffectedByGravity() == false);
    CHECK(b1->isStationary() == true);
    
    delete b1;
}
TEST_CASE("PBody: Force application and reversion", "Makes sure force addition, application, subtraction and reversion works as intended.")
{
    Vector2d v = Vector2d(-20, -10);
    
    PBody* b1 = new PBody(true, false, new Vector2d(-100, -119), new Vector2d(50, 59), new Vector2d(-0, 951));
    
    float dt = 10;
    
    b1->addVector(&v);
    b1->applyForce(dt);
    
    CHECK(b1->getPosition()->m_x == -300);
    CHECK(b1->getPosition()->m_y == 9291);
    
    b1->revertForce(dt);
    b1->removeVector(&v);
    
    CHECK(b1->getPosition()->m_x == -100);
    CHECK(b1->getPosition()->m_y == -119);
    
    delete b1;
    
    b1 = new PBody(true, false, new Vector2d(-100, -119), new Vector2d(50, 59), new Vector2d(-25, 25));
    
    CHECK(b1->getPosition()->m_x == -100);
    CHECK(b1->getPosition()->m_y == -119);

    b1->applyForce(dt);
    
    CHECK(b1->getPosition()->m_x == -350);
    CHECK(b1->getPosition()->m_y == 131);
    
    b1->resetMovementVector();
    
    // Since the movement vector has been reset it should not matter how many times we do this.
    for (int i = 0; i < 1000; i++)
        b1->applyForce(dt);
    
    CHECK(b1->getPosition()->m_x == -350);
    CHECK(b1->getPosition()->m_y == 131);
    
    delete b1;
}

TEST_CASE("PBody: Collision detection", "Checks so that collision detection works as it should.")
{
    PBody* b1 = new PBody(true, false, new Vector2d(0, 0), new Vector2d(32, 32), new Vector2d(0, 0));
    PBody* b2 = new PBody(true, false, new Vector2d(32, 32), new Vector2d(32, 32), new Vector2d(0, 0));
    
    CHECK_FALSE(b1->isColliding(b2));
    
    Vector2d v1 = Vector2d(5, 5);
    b1->addVector(&v1);
    b1->applyForce(1);
    
    CHECK(b1->getPosition()->m_x == 5);
    CHECK(b1->getPosition()->m_y == 5);
    
    CHECK(b1->isColliding(b2));
    
    Vector2d v2 = Vector2d(5, 5);
    Vector2d v3 = Vector2d(36, 36);
    Vector2d v4 = Vector2d(4,4);
    Vector2d v5 = Vector2d(37,37);
    
    CHECK(b1->intersectionWithPoint(&v2));
    CHECK(b1->intersectionWithPoint(&v3));
    CHECK_FALSE(b1->intersectionWithPoint(&v4));
    CHECK_FALSE(b1->intersectionWithPoint(&v5));
    
    Vector2d v6 = Vector2d(32,32);
    Vector2d v7 = Vector2d(63,63);
    Vector2d v8 = Vector2d(31,31);
    Vector2d v9 = Vector2d(64,64);
    
    CHECK(b2->intersectionWithPoint(&v6));
    CHECK(b2->intersectionWithPoint(&v7));
    CHECK_FALSE(b2->intersectionWithPoint(&v8));
    CHECK_FALSE(b2->intersectionWithPoint(&v9));
    
    delete b1;
    delete b2;
}
