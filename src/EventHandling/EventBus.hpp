//
//  EventBus.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
#include "EEvent.hpp"
#include "IEventListener.hpp"
#include <vector>

using namespace std;


class EventBus
{
public:
	static EventBus* getSharedInstance();
	void publishEvent(EEvent event, void* source);
	void addEventListener(IEventListener* listener);
	void removeEventListener(IEventListener* listener);
private:
	vector<IEventListener*> listeners;
	~EventBus();
	EventBus();
};
