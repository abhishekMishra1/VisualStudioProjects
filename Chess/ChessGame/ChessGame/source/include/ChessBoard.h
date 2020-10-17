#pragma once
#include "CommonTypes.h"
#include "ICharacters.h"
#include <map>



namespace ChessGame
{

	struct Block
	{
		BoardBlocks m_Color = BoardBlocks::NONE;
		BlockState m_State = BlockState::INVALID;
		ICharacters* m_Character = nullptr;
		Block() = default;
		Block(BoardBlocks color, BlockState state, ICharacters* sym);
	};

	struct Position
	{
		int column = 0;
		int row = 0;

		Position() = default;
		Position(int col, int row);
		bool operator<(const Position& pos) const;
		bool operator>(const Position& pos) const;
		bool operator==(const Position& pos) const;
	};

	class ChessBoard
	{
	private:
		std::map<Position, Block> m_Board;

		ChessBoard(const ChessBoard&) = default;
		ChessBoard& operator=(const ChessBoard&) = default;
	public:
		/*Ctor & Dtor*/
		ChessBoard();
		~ChessBoard();
		
		bool IsEmpty(const Position pos) const;
		void Set(ICharacters* sym, Position pos);
		void Reset(const Position& pos);
		void ResetBoard();
		ICharacters& Get(const Position& pos);

	};

	BoardBlocks GetColor(Position pos);
	ICharacters* GetSymbol(Position pos);
}

