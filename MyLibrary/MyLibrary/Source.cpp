#include "BST.h"
#include <random>

int main()
{
	BinarySearchTree::BST<int> myBst;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 100);

	for (int i = 10; i > 0; --i) 
	{
		int value = distribution(generator);
		myBst.insertElement(value);
	}

	myBst.traverseBST();
	std::cout<<"Depth of field is " << myBst.depth() << std::endl;

	return 0;
}