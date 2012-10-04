#include "EEvent.hpp"
#include "EventBus.hpp"
#include "../Helper/Logger.hpp"


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
    Log(LOG_INFO, "EventBus", "Shared instance accesed");
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
    Log(LOG_INFO, "EventBus", "Added event listener");
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
