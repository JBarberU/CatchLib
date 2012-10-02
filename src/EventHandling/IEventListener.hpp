
//
//  IEventListener.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	Abstract class to be extented by classes fit to listen for events.
//  Classes extending this class are event listeners, that is, they are capable of listening to events.
//
// Methods:
// 	onEvent:
//	 event callback.
//

class IEventListener
{
public:
	virtual void onEvent (EEvent event, void* source)=0;
};
