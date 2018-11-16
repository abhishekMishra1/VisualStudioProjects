
#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_
#include <vector>
#include<string>
#include "NodesType.h"
#include "GameConstants.h"

using namespace std;
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
	virtual void InsertString(string& str);
	virtual void Insert(std::vector<T>&);
	virtual void TraverseTree(Trees::TraversalType);
	virtual void GraphicalRepresentationOfTree();
	int GetLongestValidPath();
	int GetDepth();
	int GetDepth(GenericNode<T>* node);
protected:
	virtual void Insert(GenericNode<T>* pHead, T value);
	void TraverseTree(const GenericNode<T>* pHead, Trees::TraversalType type);
	Trees::DataTypes GetDataTypes(char ch);

private:
	const GenericNode<T>* m_pHead = new GenericNode<T>;
	bool m_bHeadInitialized = false;
};

////////////////////////////////////////////////////GENERIC NODE IMPLEMENTATION	//////////////////////////////////////////////////////////////////////
template<class T>
GenericBST<T>::GenericBST()
{

}

template<class T>
GenericBST<T>::~GenericBST()
{

}


template<class T>
GenericBST<T>::GenericBST(const GenericBST<T>&)
{

}

template<class T>
void GenericBST<T>::Insert(T value)
{
	//1. Initialize the head first
	if (!m_bHeadInitialized/* && Trees::UNINITIALIZED_INT == m_pHead->data*/)//Need to fix this check
	{
		m_pHead->data = value;
		m_bHeadInitialized = true;
	}
	else
	{
		if (m_pHead->data > value)
		{
			if (!m_pHead->pLeft)
				m_pHead->pLeft = new GenericNode<T>;
			Insert(m_pHead->pLeft, value);
		}
		else
		{
			if (!m_pHead->pRight)
				m_pHead->pRight = new GenericNode<T>;
			Insert(m_pHead->pRight, value);
		}
	}

}


template<class T>
void GenericBST<T>::Insert(GenericNode<T>* pHead, T value)
{
	//if (pHead->data) // Need to fix this check.
	{
		pHead->data = value;
	}
	//else
	{
		if (pHead->data > value)
		{
			if (!pHead->pLeft)
				pHead->pLeft = new GenericNode<T>;
			Insert(pHead->pLeft, value);
		}
		else
		{
			if (!pHead->pRight)
				pHead->pRight = new GenericNode<T>;
			Insert(pHead->pRight, value);
		}

	}
}

template<class T>
void GenericBST<T>::TraverseTree(Trees::TraversalType type)
{
	TraverseTree(m_pHead, type);
}

template<class T>
void GenericBST<T>::TraverseTree(const GenericNode<T>* pHead, Trees::TraversalType type)
{
	if (!pHead)
		return;
	switch (type)
	{
	case Trees::PREORDER:
		cout << pHead->data << " ";
		TraverseTree(pHead->pLeft, type);
		TraverseTree(pHead->pRight, type);
		break;
	case Trees::INORDER:
		TraverseTree(pHead->pLeft, type);
		cout << pHead->data << " ";
		TraverseTree(pHead->pRight, type);
		break;
	case Trees::POSTORDER:
		TraverseTree(pHead->pLeft, type);
		TraverseTree(pHead->pRight, type);
		cout << pHead->data << " ";
		break;
	default:
		break;
	}
}

template<class T>
void GenericBST<T>::Insert(vector<T>& vInputVals)
{

}


template<class T>
int GenericBST<T>::GetLongestValidPath()
{

	return 0;
}


template<class T>
void GenericBST<T>::GraphicalRepresentationOfTree()
{

}

template<class T>
int GenericBST<T>::GetDepth()
{
	if (!m_pHead)
		return 0;
	else if (!m_pHead->pLeft && !m_pHead->pRight)
		return 1;

	int depth = 0;
	depth = GetDepth(const_cast<GenericNode<T>*>(m_pHead));

	return depth;
}

template<class T>
int GenericBST<T>::GetDepth(GenericNode<T>* node)
{
	int depthL = 1;
	int depthR = 1;
	if (node->pLeft)
		depthL = 1 + GetDepth(node->pLeft);

	if (node->pRight)
		depthR = 1 + GetDepth(node->pRight);

	if (depthL > depthR)
		return depthL;
	else
		return depthR;
}

template<class T>
void GenericBST<T>::InsertString(string& str)
{
	char delimiter = ' ';
	for (auto itr : str)
	{
		Trees::DataTypes dt = GetDataTypes(itr);
		switch (dt)
		{
		case Trees::SPACE:
			continue;
			break;
		case Trees::STRING:
			break;
		case Trees::CHARACTER:
			break;
		case Trees::INTEGER:
			break;
		case Trees::FLOAT:
			break;
		case Trees::OPERATORS:
			break;
		case Trees::BRACKETS:
			break;
		case Trees::INVALID:
			break;
		default:
			break;
		}
		Insert(itr);
	}
}

template<class T>
Trees::DataTypes GenericBST<T>::GetDataTypes(char ch)
{
	Trees::DataTypes checkTypes;
	if (ch == ' ')
	{
		checkTypes = Trees::SPACE;
	}
	else if (ch - '0' >= 0 || ch -'0' <= 9)
	{
		checkTypes = Trees::INTEGER;
	}
	else if (ch >= 'a' || ch <= 'z' ||
		ch >= 'A' || ch <= 'Z')
	{
		checkTypes = Trees::CHARACTER;
	}
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		checkTypes = Trees::OPERATORS;
	}
	else if (ch == '(' || ch == ')')
	{
		checkTypes = Trees::BRACKETS;
	}
	else
	{
		checkTypes = Trees::INVALID;
	}

	return checkTypes;
}
#endif