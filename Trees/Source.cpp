#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree b;
	b.Insert(4);
	b.Insert(5);
	b.Insert(4);
	b.Insert(5);
	b.Insert(6);
	b.Insert(4);
	b.Insert(1);
	b.Insert(3);
	b.Insert(1);
	b.Insert(3);

	b.TraverseTree();

	return 0;
}