
#include "EventBus.hpp"

EventBus::~EventBus()
{
    m_listeners = new EventListenerArray();
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
	for(int i=0; i <= m_listeners->m_index; i++) {
		m_listeners->m_eventListeners[i]->onEvent(event, source);
	}

}
void EventBus::addEventListener(IEventListener* listener)
{
	if (m_listeners->m_eventListeners == 0){
		m_listeners->m_eventListeners = new IEventListener*[m_listeners->m_incrementBy];
        m_listeners->m_size += m_listeners->m_incrementBy;
	}
    if (m_listeners->m_index >= m_listeners->m_size-1 ) {
        IEventListener** newArray = new IEventListener*[m_listeners->m_size + m_listeners->m_incrementBy];
        
        for (int i = 0; i < m_listeners->m_size; i++) {
            newArray[i] = m_listeners->m_eventListeners[i];
        }
        m_listeners->m_eventListeners = newArray;
        m_listeners->m_size += m_listeners->m_incrementBy;
    }
    m_listeners->m_eventListeners[++m_listeners->m_index] = listener;
}
void EventBus:: removeEventListener(IEventListener* listener)
{
    if (m_listeners == 0 || m_listeners->m_index == 0 ){
        return;
    }
    for (int i = 0; i <= m_listeners->m_index; i++) {
        if (listener == m_listeners->m_eventListeners[i]){
            m_listeners->m_eventListeners[i] = m_listeners->m_eventListeners[m_listeners->m_index];
            m_listeners->m_eventListeners[m_listeners->m_index--] = 0;
            break;
        }
    }
}
