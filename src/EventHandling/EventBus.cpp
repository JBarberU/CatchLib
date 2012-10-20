//
//  File:       EventBus.hpp
//  Class:      EventBus
//  Author:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//	License: The following code is licensed under the Catch22-License
//
//

#include "EEvent.hpp"
#include "EventBus.hpp"


EventBus::~EventBus()
{
}
EventBus::EventBus()
{

}

static EventBus* s_sharedBus = 0;

EventBus* EventBus::getSharedInstance()
{
	if(s_sharedBus == 0)
	{
		s_sharedBus = new EventBus();
	}
	return s_sharedBus;
}

void EventBus::publishEvent(EEvent event, void* source)
{
	for(unsigned int i=0; i < listeners.size(); ++i) {
		listeners[i]->onEvent(event, source);
	}
   
}

void EventBus::addEventListener(IEventListener* listener)
{
	listeners.push_back(listener);
}

void EventBus:: removeEventListener(IEventListener* listener)
{
    for(vector<IEventListener*>::iterator it = listeners.begin(); it < listeners.end(); it++)
    {
        if(listener == *it){
            listeners.erase(it);
        }
    }
}
