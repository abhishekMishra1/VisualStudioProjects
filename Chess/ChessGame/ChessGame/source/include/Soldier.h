#pragma once
#include "ICharacters.h"

namespace ChessGame
{
	class Soldier:public ICharacters
	{
	public:
		Soldier();
		void Move();
	};
}