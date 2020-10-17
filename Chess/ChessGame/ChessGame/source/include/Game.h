#pragma once
#include "ChessBoard.h"
#include "Player.h"

namespace ChessGame
{

	class Game
	{
		ChessBoard* m_pBoard;
		Player* m_pPlayerl;
		Player* m_pPlayer2;
	public:
		Game() = default;
		virtual ~Game();
		void LaunchGame();
	};
}