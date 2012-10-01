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
#include <vector>
#include <string>


FileManager::FileManager(const char* basePath)
{
    m_basePath = std::string(basePath);
}
FileManager::~FileManager()
{
}

/*
 * Decode the requested file
 * Decodes it in a way that it is acceptable to assume it has RGBA format.
 * by rapp & ZEB0
 */
CLTexture* FileManager::loadTextureFromFile(const char* filename)
{
    std::string filepath = std::string(m_basePath);
    filepath.append(filename).append(".png");
 
    Log(LOG_INFO, "FileManager", filepath.c_str());
    

	std::vector<unsigned char> rawImage;
    std::vector<unsigned char> image;
    
	unsigned width, height;
    
	lodepng::load_file(image, filepath);
    
    const std::vector<unsigned char> rawIn = std::vector<unsigned char>(image);
    
	unsigned error = lodepng::decode(rawImage, width, height, rawIn);

	if (error != 0)
	{
		Log(LOG_ERROR, "FileManager", "Error when trying to load file from path: ");
	}

	//Set the format and the type

	int size = rawImage.size();
	char* data = new char[size];
    
    std::cout << "Size = " << size << "\n";
    std::cout << "WxH = " << width * height << "\n";

	for (int i = 0; i < size; i +=4 )
	{
		data[i] = rawImage.at(i);
        std::cout << "Derp: " << (int)rawImage.at(i) << "," << (int)rawImage.at(i+1) << "," << (int)rawImage.at(i+2) << "," << (int)rawImage.at(i+3) << "\n";
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
