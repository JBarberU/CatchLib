//
//  File:       EEvent.hpp
//  Class:      EEvent
//  Author:     Jesper Persson and Sebastian Odbjer
//              All code is our own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		02/10-2012
//
//	License: The following code is licensed under the Catch22-License
//
//  Description:
//	Enumiration of different types of events.
//
//
#pragma once


enum EEvent
{
	DID_JUMP,
	DID_COLLIDE,
	DID_THROW,
	GAME_STARTED,
	GAME_PAUSED,
	GAME_OVER,
    PBODY_CREATED_PHYSICS,
    PBODY_CREATED_ACTORS,
    COLLIDED_WITH_PLAYER,
    WAS_DESTROYED,
    PBODY_DESTROYED_PHYSICS
};

