//
//  File:       IEventListener.hpp
//  Class:      IEventListener
//  Authors:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//  Description:
//	Abstract class to be extented by classes fit to listen for events.
//  Classes extending this class are event listeners, that is, they are capable of
//  listening to events.
//
//

#include "EEvent.hpp"
#pragma once
class IEventListener
{
public:
	// Event callback.
	virtual void onEvent (EEvent event, void* source)=0;
};
