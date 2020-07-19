#include "BST.h"

int main()
{
	BinarySearchTree::BST<int> myBst;
	
	for (int i = 10; i > 0; --i)
	{
		myBst.insertElement(i);
	}

	myBst.traverseBST();

	return 0;
}