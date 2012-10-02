//
//  EventBus.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
#include "EEvent.hpp"
#include "IEventListener.hpp"

struct EventListenerArray
{
	IEventListener** m_eventListeners;
	int m_size;
	int m_incrementBy;
	int m_index;
	EventListenerArray()
	{
		m_incrementBy = 5;
		m_index = 0;
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
