//
//  File:       SoundManager.hpp
//  Class:      SoundManager
//  Author:     John Barbero Unenge
//              All code is my own except where credited to others.
//
//  Date: 17/9-2012
//  
//  Description:
//  This class is used for audio playback.
//  
//  Methods:
//  playSFX
//    Starts playback of a sound effect. It takes a filename as 
//    its parameter which should contain a small audio sample.
//  playBGMusic
//    Starts playback of background music. It takes a filename 
//    as its parameter which should contain an audio file long 
//    enough to be background music. This file may very well 
//    be compressed audio.

//  SoundManager
//  The sound manager
class SoundManager {
public:
    //  playSFX
    //  Plays the given file as a sound effect. This means 
    //  that it will playback in parallell with music and 
    //  other sounds.
    void playSFX(const char* file);
    
    //  playBGMusic
    //  Plays the given file as background music. This file 
    //  may very well be compressed. If music is already 
    //  playing then that music will be stopped and the 
    //  contents of the new file will start playing.
    void playBGMusic(const char* file);
};
