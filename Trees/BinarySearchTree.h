
#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <vector>
#include "NodesType.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree&);
	virtual void Insert(int value);
	virtual void Insert(std::vector<int>&);
	virtual void TraverseTree();
protected:
	virtual void Insert(Node* pHead, int value);
	void TraverseTree(Node* pHead);
private:
	Node* m_pHead = new Node;
	bool m_bHeadInitialized = false;
};

#endif