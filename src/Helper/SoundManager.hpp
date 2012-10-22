//
//  File:       SoundManager.hpp
//  Class:      SoundManager
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date: 17/9-2012
//
//	License: The following code is licensed under the Catch22-License
//  
//  Description:
//  This class is used for audio playback.
//  
class SoundManager {
public:

	//	Constructor
	SoundManager();

	//	Destructor
	~SoundManager();
    
    //  Plays the given file as a sound effect. This means 
    //  that it will playback in parallell with music and 
    //  other sounds.
    void playSFX(const char* file);
    
    //  Plays the given file as background music. This file
    //  may very well be compressed. If music is already 
    //  playing then that music will be stopped and the 
    //  contents of the new file will start playing.
    void playBGMusic(const char* file);
};
