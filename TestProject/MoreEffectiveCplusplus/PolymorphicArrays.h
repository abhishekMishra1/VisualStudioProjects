#include <iostream>
#include <ostream>


class BST
{
	public:
	
		int i;
		//std::ostream& operator << (BST& value)
		//{
		//	return value.i;
		//}
};

class BalancedBST :public BST
{

};


void printArray(std::ostream& OutStream, const BST array[], int numElements);
