#include "ICharacters.h"

namespace ChessGame
{
	class Queen :public ICharacters
	{
	public:
		Queen();
		void Move();
	};
}