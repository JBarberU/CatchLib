
//
//  IEventHandler.hpp
//  CatchLib
//
//  Created by Jesper Persson and Sebastian Odbjer on 2/10-12.
//  Copyright (c) 2012 Catch22. All rights reserved.
//
//	Abstract class to be extented by classes affected by events.
//
//

class IEventHandler
{
public:
	virtual void onEvent ()=0;
};
