#pragma once
namespace ChessGame
{
	enum class BoardBlocks
	{
		WHITE,
		BLACK,
		NONE
	};

	enum class CharacterType
	{
		WHITE,
		BLACK,
		INVALID
	};
	enum class BlockState
	{
		EMPTY,
		OCCUPIED,
		INVALID
	};

	enum class Characters
	{
		KING,
		QUEEN,
		CAMEL,
		ELEPHANT,
		HORSE,
		SOLDIER,
		INVALID
	};

	extern const unsigned int ROWSIZE;
	extern const unsigned int COLUMNSIZE;
}