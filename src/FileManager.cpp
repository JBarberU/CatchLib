//
//  FileManager.cpp
//  CatchiOS
//
//  Created by John Barbero Unenge on 9/20/12.
//  Copyright (c) 2012 John Barbero Unenge. All rights reserved.
//

#include "FileManager.hpp"
#include "Logger.hpp"

FileManager::FileManager(const char* basePath)
{
    this->m_basePath = basePath;
}
FileManager::~FileManager()
{
}

CLTexture* FileManager::loadTextureFromFile(const char* file)
{
    Log(LOG_ERROR, "FileManager", "loadTextureFromFile is returning null since it hasn't been implemented yet.");
    return 0;
}