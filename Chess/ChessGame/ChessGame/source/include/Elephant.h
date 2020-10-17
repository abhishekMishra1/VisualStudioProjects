#include "ICharacters.h"

namespace ChessGame
{
	class Elephant :public ICharacters
	{
	public:
		Elephant();
		void Move();
	};
}