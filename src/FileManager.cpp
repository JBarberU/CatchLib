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
	m_basePath = basePath;
}
FileManager::~FileManager()
{

}

CLTexture* loadTextureFromFile(const char* filename)
{

	CLTexture texture;
	const char filepath = m_basePath + filename;

	//Decode the requested file
	//Decodes it in a way that it is acceptable to assume it has RGBA format.
	unsigned error = decoder.decode(texture.data, texture.width, texture.height, filepath);

	if (error != 0)
	{
		Log(LOG_ERROR, "FileManager", "Error when trying to load file from path: " + filepath);
		return 1;
	}

	//Set the format and the type
	texture.type = GL_UNSIGNED_BYTE;
	texture.internalformat = GL_RGBA;

	return texture;

}
