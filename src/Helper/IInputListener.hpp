//
//  File:   IInputListener.hpp
//  Class:  IInputListener
//  Author: John Barbero Unenge
//      All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 24/9-2012
//
//  Description:
//      An interface for all classes interrested in knowing
//      when input has taken place.
//

#ifndef CatchiOS_IInputListener_hpp
#define CatchiOS_IInputListener_hpp

#include "EInputType.hpp"

class IInputListener {
public:
    //  Called when input been recieved
    virtual void didRecieveInputEvent(InputType input, int locX, int locY) = 0;
};

#endif
