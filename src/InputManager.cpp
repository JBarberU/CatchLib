//
//  InputManager.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/20/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "InputManager.hpp"
#include "Logger.hpp"

InputManager::InputManager()
{

}
InputManager::~InputManager()
{
    
}

void InputManager::passInputEvent(InputType input, float locX, float locY)
{
    for (int i = 0; i < m_inputArray.m_size; i++) {
        m_inputArray.m_listeners[i]->didRecieveInputEvent(input, locX, locY);
    }
    
    Log(LOG_EVENT, "InputManager", "Passing inputEvent");
}
void InputManager::addInputListener(IInputListener* listener)
{
    IInputListener** newArray = new IInputListener*[m_inputArray.m_size + 1];
    
    for (int i = 0; i < m_inputArray.m_size; i++) {
        newArray[i] = m_inputArray.m_listeners[i];
    }
    newArray[m_inputArray.m_size] = listener;
    
    m_inputArray.m_listeners = newArray;
    m_inputArray.m_size++;
}

//////////////////////////////////////
//  Static part of implementation   //
//////////////////////////////////////

InputManager* InputManager::getSharedManager()
{
    if (s_sharedManager == 0) {
        s_sharedManager = new InputManager();
    }
    return s_sharedManager;
}