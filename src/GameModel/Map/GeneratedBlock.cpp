//
//  File:	GeneratedBlock.cpp
//  Class	GeneratedBlock
//  Author	Jonatan Rapp & Alexander Hederstaf
//			All code is my own except where credited to others.
//
//  Copyright © 2012 Catch22. All Rights Reserved.
//
//  Date: Oct 10, 2012
//
//  Description:
//
//
#include "GeneratedBlock.hpp"

GeneratedBlock::GeneratedBlock(int dy, Blocktype type)
{
	this->dy = dy;
	this->type = type;
}

GeneratedBlock::~GeneratedBlock()
{

}

bool operator==(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock)
{
	return lhsBlock.dy == rhsBlock.dy && lhsBlock.type == rhsBlock.type;
}

bool operator<(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock)
{
	/*
	 * return value based on type and dY to order
	 * the GeneratedBlocks.
	 */
	int thisValue = lhsBlock.dy*3 + lhsBlock.type == INCLINE ? 0 : lhsBlock.type == HORIZONTAL ? 1 : 2;
	int otherValue = rhsBlock.dy*3 + rhsBlock.type == INCLINE ? 0 : rhsBlock.type == HORIZONTAL ? 1 : 2;
	return thisValue < otherValue;
}
