#pragma once
#include "PseudoUI.h"
#include <iostream>

namespace ChessGame
{
	std::string PseudoUI::m_szRowWhite = "|#| |#| |#| |#| \n";
	std::string PseudoUI::m_szRowBlack = "  |#| |#| |#| |#|\n";
	using namespace std;
	void PseudoUI::DisplayBoard(const ChessBoard& board)
	{
		cout << "\n\n";
		cout << "|E|H|C|K|Q|C|H|E|\n";
		cout << "|s|s|s|s|s|s|s|s|\n";
		for (int i = 0; i < 2; ++i)
		{
			cout << m_szRowWhite;
			cout << m_szRowBlack;
		}
		cout << "|s|s|s|s|s|s|s|s|\n";
		cout << "|E|H|C|Q|K|C|H|E|\n";
		cout << "\n\n";

		
	}
	
	void PseudoUI::RefreshBoard(const ChessBoard& board)
	{}
	
	void PseudoUI::UpdatePosition(const ICharacters& sym, const Position& source, const Position& destination)
	{

	}

	char PseudoUI::GetSymbolCharacter(const Characters& sym)
	{
		char cSym;
		switch (sym)
		{
		case Characters::KING:
			cSym = 'K';
			break;

		case Characters::QUEEN:
			cSym = 'Q';
			break;

		case Characters::CAMEL:
			cSym = 'C';
			break;

		case Characters::ELEPHANT:
			cSym = 'E';
			break;

		case Characters::HORSE:
			cSym = 'H';
			break;

		case Characters::SOLDIER:
			cSym = 'S';
			break;

		default:
			break;
		}

		return cSym;
	}


}