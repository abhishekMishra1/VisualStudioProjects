#include "Game.h"
#include <iostream>
#include "ChessBoard.h"
#include "PseudoUI.h"

namespace ChessGame
{
	void Game::LaunchGame()
	{
		std::cout << "Launching game...\n";
		//1. Create and initialize Board
		ChessBoard board;

		//Create and initialize players
		m_pPlayerl = new Player("P1", CharacterType::WHITE);
		m_pPlayer2 = new Player("P2", CharacterType::BLACK);
		PseudoUI::DisplayBoard(board);
		std::cout << "Game launched!\n";
	}

	Game::~Game()
	{
		if (m_pPlayerl)
			delete m_pPlayerl;

		if (m_pPlayer2)
			delete m_pPlayer2;

		if (m_pBoard)
			delete m_pBoard;
	}
}