//
//  File:	GeneratedBlock.hpp
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
#include "PlatformBlock.hpp"

class GeneratedBlock {

public:
	int dy;
	Blocktype type;
	int chance;

	~GeneratedBlock();
	GeneratedBlock(int dy, Blocktype type, int baseChance);
	friend bool operator==(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock);
	friend bool operator<(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock);
};
