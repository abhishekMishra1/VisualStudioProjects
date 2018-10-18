
#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <vector>
#include "NodesType.h"
#include "GameConstants.h"

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinarySearchTree(const BinarySearchTree&);
	virtual void Insert(int value);
	virtual void Insert(std::vector<int>&);
	virtual void TraverseTree(Trees::TraversalType);
	virtual void GraphicalRepresentationOfTree();
	int GetLongestValidPath();
	int GetDepth();
	int GetDepth(Node* node);
protected:
	virtual void Insert(Node* pHead, int value);
	void TraverseTree(const Node* pHead, Trees::TraversalType type);
	
private:
	const Node* m_pHead = new Node;
	bool m_bHeadInitialized = false;
};

template<class T>
class GenericBST
{
public:
	GenericBST();
	~GenericBST();
	GenericBST(const GenericBST&);
	virtual void Insert(T value);
	virtual void Insert(std::vector<T>&);
	virtual void TraverseTree(Trees::TraversalType);
	virtual void GraphicalRepresentationOfTree();
	int GetLongestValidPath();
	int GetDepth();
	int GetDepth(GenericNode<T>* node);
protected:
	virtual void Insert(GenericNode<T>* pHead, T value);
	void TraverseTree(const GenericNode<T>* pHead, Trees::TraversalType type);

private:
	const GenericNode<T>* m_pHead = new GenericNode<T>;
	bool m_bHeadInitialized = false;
};

#endif