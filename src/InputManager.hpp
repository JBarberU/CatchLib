//
//  File:       InputManager.hpp
//  Class:      InputManager
//  Enum:       InputType
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Date: 17/9-2012
//  
//  Description:
//  This class is used to handle and process user input.
//  It recieves input events and passes them on to the C++ 
//  core.
//  
//  Methods:
//  passInputEvent
//      Passes an input event with a certain inputType and if 
//      suitable a coordinate where the event took place
//      (mostly useful for InputType: TOUCH).

//  InputType
//  An enum used to destinguish what kind of input event was
//  triggered.

#include "IInputListener.hpp"
#include "EInputType.hpp"

struct InputListenerArray {
    IInputListener** m_listeners;
    int m_size = 0;
};

//  InputManager
//  Used to manage input. It's a singleton class.
class InputManager{
private:
    InputListenerArray m_inputArray;
    InputManager();
    ~InputManager();
    static InputManager* s_sharedManager;
    
public:
    //  Tell InputManager to pass an input event.
    //  The first parameter has to be an InputType declared above, 
    //  and if it makes sense it should also provide an x and y 
    //  coordinates.
    //  The coordinate system used is with origin in the lower left 
    //  corner and coordinates (1,1) in the upper right cornder.
    void passInputEvent(InputType input, float locX, float locY);
    
    //  Add an inputListener which will recieve input events.
    void addInputListener(IInputListener* listener);
    
    static InputManager* getSharedManager();
};

