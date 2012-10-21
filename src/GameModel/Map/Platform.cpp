//
//  File:		Platform.cpp
//  Class:      Platform
//  Author:     Sebastian Odbjer
//              All code is my own except where credited to others.
//
//	Copyright (c) 2012 by Catch22. All Rights Reserved.
//  Date: 		05/10-2012

#include "Platform.hpp"


Platform::Platform()
{

}

Platform::~Platform()
{

}

vector<PlatformBlock*> Platform::getPlatformBlocks()
{
	return platformblocks;
}

void Platform::addPlatformBlock(PlatformBlock* block)
{
	platformblocks.push_back(block);
}

void Platform::clearPlatformBlocks()
{
	platformblocks.clear();
}

Vector2d* Platform::startPoint()
{
	return platformblocks.front()->getStartVector();
}

Vector2d* Platform::endPoint()
{
	return platformblocks.back()->getEndVector();
}




