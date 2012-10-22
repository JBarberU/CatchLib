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
//	License: The following code is licensed under the Catch22-License
//
//  Description:

#include "PlatformBlock.hpp"

class GeneratedBlock {

public:

	/*
	 * The "Jump" made by this platform from the earlier platform.
	 * This creates a vertical wall.
	 */
	int dy;

	/*
	 * Enum BlockType of the block
	 * INCLINE, HORIZONTAL, DECLINE
	 */
	Blocktype type;

	/*
	 * Chance value for this block to be randomed in map generation.
	 */
	int chance;

	~GeneratedBlock();

	/**
	 * Creates a GeneratedBlock
	 * @param dy
	 * 		How many units of a "jump" this block should make.
	 * @param type
	 * 		Type of slope for this block.
	 * @param baseChance
	 * 		Base chance to random this block, can be modified later.
	 */
	GeneratedBlock(int dy, Blocktype type, int baseChance);

	/**
	 * Overloads == operator.
	 * Compares dy and type.
	 */
	friend bool operator==(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock);

	/**
	 * Overloads < operator for use in set.
	 * Compares dy and type.
	 */
	friend bool operator<(GeneratedBlock const& lhsBlock, GeneratedBlock const& rhsBlock);
};
