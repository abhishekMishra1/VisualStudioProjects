#include "ICharacters.h"

namespace ChessGame
{
	class King :public ICharacters
	{
	public:
		King();
		void Move();
	};
}