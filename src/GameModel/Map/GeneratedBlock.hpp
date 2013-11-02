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

#include "PlatformBlock.hpp"

/**
 * Helper class for MapGenerator. A GeneratedBlock represents the different
 * possible blocks the MapGenerator can use to create a Map. The Map is then
 * created with PlatformBlocks in Platforms.
 *
 * @see MapGenerator.hpp, PlatformBlock.hpp, Platform.hpp
 *
 */
class GeneratedBlock {

public:

	/*
	 * The height difference from the previous platform to this platform.
	 * When this variable is not 0 we get a vertical wall.
	 */
	int dy;

	/*
	 * BlockType of the block describes which of the three blocktypes
	 * this block has.
	 * INCLINE (goes up 1 level in a slope)
	 * HORIZONTAL (doesn't change height and is flat)
	 * DECLINE (goes down 1 level in a slope)
	 */
	Blocktype type;

	/*
	 * The random chance of this block to be used for a map in map generation.
	 */
	int chance;

	~GeneratedBlock();

	/**
	 * Creates a GeneratedBlock
	 * @param dy
	 * 		How many units of difference in height this block should have
	 * 		compared to the previous one.
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
