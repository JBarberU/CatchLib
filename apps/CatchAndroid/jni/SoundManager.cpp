//
//  File:       SoundManager.cpp
//  Class:      SoundManager
//  Author:     Jesper Persson
//              All code is my own except where credited to others.
//	Co Author:	John Barbero Unenge
//
//  Date: 23/9-2012
//
//	Description:
//	Implementation of the SoundManager for Android.
//
//	Includes:
//	string.h, CatchLib/src/SoundManager.hpp, CatchLib/src/Logger.hpp

#include "CatchLib/src/Helper/SoundManager.hpp"
#include "CatchLib/src/Helper/Logger.hpp"
#include <string.h>


SoundManager::SoundManager()
{
	Log(LOG_INFO, "SoundManager", "Created SoundManager");
}
SoundManager::~SoundManager()
{

}

//Dummy implementation of the playSFX-method. Will simply Log the filename that should have been played
void SoundManager::playSFX(const char* file)
{
	char buf [100];
	strcpy(buf, "Tried to play file: ");
	strcat(buf,file);
	Log(LOG_INFO, "SoundManager", buf);
}

//Dummy implementation of the playBGMusic-method. Will simply Log the filename that should have been played
void SoundManager::playBGMusic(const char* file)
{
	char buf[100];
	strcpy(buf, "Tried to play file: ");
	strcat(buf,file);
	Log(LOG_INFO, "SoundManager", buf);
}
