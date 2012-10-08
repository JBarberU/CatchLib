//
//  File:       InputManager.hpp
//  Class:      InputManager
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 17/9-2012
//  
//  Description:
//  This class is used to handle and process user input.
//  It recieves input events and passes them on to the C++ 
//  core.
//
//  NOTE:
//  This is a singleton class and should be accessed by first
//  using the getSharedManager function and the calling functions.
//
#include "IInputListener.hpp"
#include "EInputType.hpp"

//  Struct used as an array would in java (objects + size)
struct InputListenerArray {
    IInputListener** m_listeners;
    int m_size;
    InputListenerArray()
    {
        m_listeners = 0;
        m_size = 0;
    }
};

//  InputManager
//  Used to manage input. It's a singleton class.
class InputManager{
private:
    InputListenerArray m_inputArray;
    InputManager();
    ~InputManager();
    
public:
    //  Tell InputManager to pass an input event.
    //  The first parameter has to be an InputType declared in
    //  EInputType, and if it makes sense it should also provide
    //  an x and y coordinates.
    //  The coordinate system used is with origin in the lower left 
    //  corner and coordinates (1,1) in the upper right cornder.
    //  This is when the device is in portrait mode.
    void passInputEvent(InputType input, int locX, int locY);
    
    //  Add an inputListener which will recieve input events.
    void addInputListener(IInputListener* listener);
    
    //  Removes an inputListener. Returns true if the listener
    //  was found, otherwise false.
    bool removeInputListener(IInputListener* listener);
    
    //  Get the shared instance of InputManager.
    static InputManager* getSharedManager();
};
