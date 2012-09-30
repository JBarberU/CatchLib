//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "CatchLib/src/FileManager.hpp"
#include "CatchLib/src/Lodepng.hpp"
#include "Logger.hpp"

FileManager::FileManager(const char* basePath)
{

}
FileManager::~FileManager()
{

}

CLTexture* loadTextureFromFile(const char* file)
{
	//Decode the requested file
	std::vector<unsigned char> image;
	unsigned width;
	unsigned height;
	unsigned error = Lodepng::decode(image, width, height, file);

	if (error != 0)
	{
		Log(LOG_ERROR, "FileManager", "Error when trying to load file");
		return 1;
	}

}
