#include "C11Concepts.h"

C11Concepts::C11Concepts()
{
}

C11Concepts::C11Concepts(const std::initializer_list<int>& v)
{
	for (std::initializer_list<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		vInt.push_back(*it);
	}
}

C11Concepts::~C11Concepts()
{
}

delegatingCtor::delegatingCtor(int v) :delegatingCtor()
{
	a = v;
}

delegatingCtor::delegatingCtor()
{
	
}

