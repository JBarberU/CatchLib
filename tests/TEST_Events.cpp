//
//  TEST_Events.cpp
//  Catch22_Tests
//
//  Created by Jesper Persson on 2012-10-05.
//  Copyright (c) 2012 Catch22. All rights reserved.
//

#include "catch.hpp"
#include "TEST_Events.hpp"
#include "../src/EventHandling/EventBus.hpp"

TEST_CASE("EventBus", "Tests the EventBus-system. Adds listener, publishes events, makes sure event was recieved correctly")
{
    //Initiate a TEST_Event, add it as a EventListener and publish an event
    TEST_Events* eventTest = new TEST_Events();
    EventBus::getSharedInstance()->addEventListener(eventTest);
    EventBus::getSharedInstance()->publishEvent(DID_COLLIDE, eventTest);
    //Chech to see if the correct event was sent.
    REQUIRE(eventTest->eventType == DID_COLLIDE);
    
    EventBus::getSharedInstance()->publishEvent(GAME_OVER, eventTest);
    //Try another event-type
    REQUIRE(eventTest->eventType == GAME_OVER);
    
    //Make sure the TEST_Event is no longer listening to events, then publish new event.
    EventBus::getSharedInstance()->removeEventListener(eventTest);
    EventBus::getSharedInstance()->publishEvent(GAME_STARTED, eventTest);
    //Make sure no event was recieved (that is, that is, the TEST_Event is no longer registring published events.
    REQUIRE(eventTest->eventType == GAME_OVER);
}

void TEST_Events::onEvent (EEvent event, void* source)
{
    eventType = event;
}
