#include "ChessBoard.h"
#include "Elephant.h"
#include "Camel.h"
#include "Horse.h"
#include "King.h"
#include "Queen.h"
#include "Soldier.h"

namespace ChessGame
{
	Block::Block(BoardBlocks color, BlockState state, ICharacters* sym)
		:m_Color(color), m_State(state), m_Character(sym)
	{}

	bool Position::operator<(const Position& pos) const
	{
		if (column < pos.column)
			return true;
		else if (column == pos.column)
		{
			if (row < pos.row)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool Position::operator>(const Position& pos) const
	{
		if (column > pos.column)
			return true;
		else if (column == pos.column)
		{
			if (row > pos.row)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool Position::operator==(const Position& pos) const
	{
		if (column == pos.column && row == pos.row)
			return true;
		else
			return false;
	}
	Position::Position(int c, int r)
		:column(c)
		, row(r)
	{}

	ChessBoard::ChessBoard()
	{
		//Initialize the board having 8x8 matrix
		for(int column = 0; column < 8; ++column)
			for (int row = 0; row < 8; ++row)
			{
				if (row < 2 || row >5)
				{
					Position p(column, row);
					Block b(GetColor(p), BlockState::OCCUPIED, GetSymbol(p));
					m_Board[p] = b;
				}
			}
	}

	ChessBoard::~ChessBoard()
	{}

	bool ChessBoard::IsEmpty(const Position pos) const
	{
		return m_Board.at(pos).m_State == BlockState::EMPTY;
	}
	
	void ChessBoard::Set(ICharacters* sym, Position pos)
	{
		Block b(GetColor(pos), BlockState::OCCUPIED, sym);
		m_Board[pos] = b;
	}
	
	void ChessBoard::Reset(const Position& pos)
	{}
	
	void ChessBoard::ResetBoard()
	{}
	
	ICharacters& ChessBoard::Get(const Position& pos)
	{
		return *m_Board.at(pos).m_Character;
	}


	/*0,0 [column, row]
	* _________________
	* |X| |X| |X| |X| |
	* | |X| |X| |X| |X|
	* |X| |X| |X| |X| |
	* | |X| |X| |X| |X|
	* |X| |X| |X| |X| |
	* | |X| |X| |X| |X|
	* |X| |X| |X| |X| |
	* | |X| |X| |X| |X|
	*               7,7
	*/
	BoardBlocks GetColor(Position pos)
	{
		return (pos.column + pos.row) % 2 ? BoardBlocks::WHITE : BoardBlocks::BLACK;
	}

	ICharacters* GetSymbol(Position pos)
	{
		ICharacters* sym = nullptr;

		//first or last row
		if (0 == pos.row || 7 == pos.row)
		{
			switch (pos.column)
			{
			case 0:
			case 7:
				sym = new Elephant();
				break;

			case 1:
			case 6:
				sym = new Horse();
				break;

			case 2:
			case 5:
				sym = new Camel();
				break;

			case 3:
				sym = new Queen();
				break;

			case 4:
				sym = new King();
				break;

			default:
				break;
			}
		}
		else if (1 == pos.row || 6 == pos.row)
		{
			sym = new Soldier();
		}

		if (pos.row < 2)
			sym->SetType(CharacterType::WHITE);
		else if (pos.row > 5)
			sym->SetType(CharacterType::BLACK);

		return sym;
	}
}
