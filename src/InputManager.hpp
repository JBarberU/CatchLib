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
//  NOTE:
//  This is a singleton class and should be accessed by first
//  using the getSharedManager function and the calling functions.
//
//  Member functions:
//  passInputEvent
//      Passes an input event with a certain inputType and if 
//      suitable a coordinate where the event took place
//      (mostly useful for InputType: TOUCH).
//
//  addInputListener
//      Adds the provided IInputListener. All listeners will be
//      notified when anyone uses the passInputEvent function.
//
//  removeInputListener
//      Removes the first occurance of the given IInputListener.
//      Note that this function does not guarantee that the given
//      object is not still in among the listeners. Returns false
//      if the given listener was not found.
//
//  Static functions:
//  getSharedManager
//      Get a pointer to the shared instance of InputManager.

#include "IInputListener.hpp"
#include "EInputType.hpp"

//  Struct used as an array would in java (objects + size)
struct InputListenerArray {
    IInputListener** m_listeners;
    int m_size;
    InputListenerArray() {
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
    //  The first parameter has to be an InputType declared above, 
    //  and if it makes sense it should also provide an x and y 
    //  coordinates.
    //  The coordinate system used is with origin in the lower left 
    //  corner and coordinates (1,1) in the upper right cornder.
    void passInputEvent(InputType input, float locX, float locY);
    
    //  Add an inputListener which will recieve input events.
    void addInputListener(IInputListener* listener);
    
    //  Removes an inputListener. Returns true if the listener
    //  was found, otherwise false.
    bool removeInputListener(IInputListener* listener);
    
    //  Get the shared instance of InputManager.
    static InputManager* getSharedManager();
};
