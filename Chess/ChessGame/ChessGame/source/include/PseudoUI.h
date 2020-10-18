#pragma once
#include "ChessBoard.h"
#include "ICharacters.h"
#include <string>
namespace ChessGame
{

	class PseudoUI
	{
		static std::string m_szRowWhite;
		static std::string m_szRowBlack;
	public:
		static void DisplayBoard(const ChessBoard& board);
		static void RefreshBoard(const ChessBoard& board);
		static void UpdatePosition(const ICharacters& sym, const Position& source, const Position& destination);

	private:
		static char GetSymbolCharacter(const Characters& sym);
	};
}