//
//  FileManager.hpp
//  CatchLib
//
//  Created by John Barbero Unenge on 9/17/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "FileManager.hpp"
#include "Includes/Lodepng.hpp"
#include "Logger.hpp"
#include <iostream>

FileManager::FileManager(const char* basePath)
{
	m_basePath = basePath;
}
FileManager::~FileManager()
{

}

/*
 * Decode the requested file
 * Decodes it in a way that it is acceptable to assume it has RGBA format.
 * by rapp & ZEB0
 */
CLTexture* loadTextureFromFile(const char* filename)
{

	CLTexture texture;
	const char filepath = filename;

	std::vector<unsigned char> rawImage;
	std::vector<unsigned char> image;

	unsigned width, height;

	lodepng::load_file(image, filename);
	unsigned error = lodepng::decode(rawImage, width, height, image);

	if (error != 0)
	{
		Log(LOG_ERROR, "FileManager", "Error when trying to load file from path: " + filepath);
		return 1;
	}

	//Set the format and the type
	texture.data = rawImage;
	texture.height = height;
	texture.width = width;
	texture.type = GL_UNSIGNED_BYTE;
	texture.internalFormat = GL_RGBA;

	return texture;

}
