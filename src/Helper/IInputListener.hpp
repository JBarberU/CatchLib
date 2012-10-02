//
//  IInputListener.h
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/24/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#ifndef CatchiOS_IInputListener_hpp
#define CatchiOS_IInputListener_hpp

#include "EInputType.hpp"

class IInputListener {
public:
    virtual void didRecieveInputEvent(InputType input, int locX, int locY) = 0;
};

#endif
