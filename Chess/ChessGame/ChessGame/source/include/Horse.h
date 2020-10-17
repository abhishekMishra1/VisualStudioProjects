#include "ICharacters.h"

namespace ChessGame
{
	class Horse :public ICharacters
	{
	public:
		Horse();
		void Move();
	};
}