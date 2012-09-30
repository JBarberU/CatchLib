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

	const char* filepath = filename;

	std::vector<unsigned char> rawImage;
	std::vector<unsigned char> image;

	unsigned width, height;

	lodepng::load_file(image, filename);
	unsigned error = lodepng::decode(rawImage, width, height, image);

	if (error != 0)
	{
		Log(LOG_ERROR, "FileManager", "Error when trying to load file from path: ");
	}

	//Set the format and the type

	int size = rawImage.size();
	char* data = new char[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = rawImage.at(i);
	}

	CLTexture *texturePtr;
	texturePtr = new CLTexture;

	texturePtr->data = data;
	texturePtr->height = height;
	texturePtr->width = width;
	texturePtr->type = GL_UNSIGNED_BYTE;
	texturePtr->internalFormat = GL_RGBA;

	return texturePtr;

}
