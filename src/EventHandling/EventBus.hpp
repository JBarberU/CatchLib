//
//  EventBus.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
#include "EEvent.hpp"
#include "IEventListener.hpp"

/*
 * Structure for organizing our array of eventListeners.
 * m_eventListeners --  our array of eventListeners.
 * m_size -- 			the size of our array.
 * m_incrementBy -- 	how much the size of the array should be incremented
 * 						by whenever m_index == m_size.
 * m_index -- 			the index of the last element of the array, it is set to -1
 * 			  			as default to prevent events to be performed when the array
 * 			  			is empty.
 */
struct EventListenerArray
{
	IEventListener** m_eventListeners;
	int m_size;
	int m_incrementBy;
	int m_index;
	EventListenerArray()
	{
		m_incrementBy = 5;
		m_index = -1;
		m_size = 0;
		m_eventListeners = 0;
	}
};

class EventBus
{
public:
	static EventBus* getSharedInstance();
	void publishEvent(EEvent event, void* source);
	void addEventListener(IEventListener* listener);
	void removeEventListener(IEventListener* listener);
private:
	EventListenerArray* m_listeners;
	~EventBus();
	EventBus();
};
