#pragma once
#include <string>

namespace ChessGame
{
	class Player
	{
	private:
		std::string m_Name;
		CharacterType m_Coluor;
	public:
		Player() = default;
		Player(std::string name, CharacterType col)
			:m_Name(name)
			, m_Coluor(col)
		{}
	};
}