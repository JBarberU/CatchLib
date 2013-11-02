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
//	License: The following code is licensed under the Catch22-License
//

#include "GeneratedBlock.hpp"

GeneratedBlock::GeneratedBlock(int dy, Blocktype type, int baseChance)
{
	this->dy = dy;
	this->type = type;
	this->chance = baseChance;
}

GeneratedBlock::~GeneratedBlock()
{

}

int GeneratedBlock::hashCode() const
{
	return this->dy*3 + (this->type == INCLINE ? 0 : this->type == HORIZONTAL ? 1 : 2);
}

bool operator==(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock)
{
	return lhsBlock.dy == rhsBlock.dy && lhsBlock.type == rhsBlock.type;
}

bool operator<(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock)
{
	return lhsBlock.hashCode() < rhsBlock.hashCode();
}
