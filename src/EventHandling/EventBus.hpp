//
//  File:       EventBus.hpp
//  Class:      EventBus
//  Author:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//  Description:
//  This class is a singleton used as a communication system
//  between different parts of the application.
//
//

#include "EEvent.hpp"
#include "IEventListener.hpp"
#include <vector>

using namespace std;


class EventBus
{
public:
	static EventBus* getSharedInstance();

	// Publishes an event on the bus, that is, push an event-object onto every registered
	// listener.
	void publishEvent(EEvent event, void* source);

	// Register an IEventListener to the bus. The listener will be called
	// every time an event is published on the event bus.
	void addEventListener(IEventListener* listener);

	// Remove a listener from the bus. Events will no longer be pushed
	// onto the listener.
	void removeEventListener(IEventListener* listener);
private:
	vector<IEventListener*> listeners;
	~EventBus();
	EventBus();
};
