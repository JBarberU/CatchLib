
//
//  EventBus.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//

class EventBus
{
public:
	static EventBus getSharedInstance();
	void publishEvent();
	void addEventHandler();
	void removeEventHandler();
private:
	~EventBus();
	EventBus();
};
