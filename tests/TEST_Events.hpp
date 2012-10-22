//
//  TEST_Events.hpp
//  Catch22_Tests
//
//  Created by Jesper Persson on 2012-10-05.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	License: The following code is licensed under the Catch22-License
//
//  Simple class for testing the eventbus. Inherits the IEventListener class
//  and implements onEvent function. Keeps track of the last EEvent recieved.


#include "../src/EventHandling/EEvent.hpp"
#include "../src/EventHandling/IEventListener.hpp"


class TEST_Events: public IEventListener
{
public:    
    TEST_Events(){}
    ~TEST_Events(){}
    virtual void onEvent (EEvent event, void* source);    
    
    EEvent eventType;
};




