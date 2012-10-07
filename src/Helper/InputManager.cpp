//
//  File:       InputManager.cpp
//  Class:      InputManager
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 17/9-2012
//

#include "InputManager.hpp"
#include "Logger.hpp"

InputManager::InputManager()
{

}
InputManager::~InputManager()
{
    
}

void InputManager::passInputEvent(InputType input, int locX, int locY)
{
    Log(LOG_EVENT, "InputManager", "Passing inputEvent");
    
    for (int i = 0; i < m_inputArray.m_size; i++) {
        m_inputArray.m_listeners[i]->didRecieveInputEvent(input, locX, locY);
    }
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
bool InputManager::removeInputListener(IInputListener* listener)
{
    if (m_inputArray.m_size <= 0)
        return false;
    
    int r_index = -1;
    for (int i = 0; i < m_inputArray.m_size; i++) {
        if (m_inputArray.m_listeners[i] == listener) {
            r_index = i;
            break;
        }
    }
    
    if (r_index == -1)
        return false;
    
    IInputListener** newArray = new IInputListener*[m_inputArray.m_size - 1];
    for (int i = 0; i < m_inputArray.m_size - 1; i++) {
        if (i < r_index)
            newArray[i] = m_inputArray.m_listeners[i];
        else if (i > r_index)
            newArray[i] = m_inputArray.m_listeners[i+1];
    }
    m_inputArray.m_listeners = newArray;
    m_inputArray.m_size--;
    
    return true;
}
//////////////////////////////////////
//  Static part of implementation   //
//////////////////////////////////////

static InputManager* s_sharedManager;

InputManager* InputManager::getSharedManager()
{
    if (s_sharedManager == 0) {
        s_sharedManager = new InputManager();
    }
    return s_sharedManager;
}
