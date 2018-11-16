#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
{

}

BinarySearchTree::~BinarySearchTree()
{
	
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree&)
{

}

void BinarySearchTree::Insert(int value)
{
	//1. Initialize the head first
	if (!m_bHeadInitialized && Trees::UNINITIALIZED_INT == m_pHead->data)
	{
		m_pHead->data = value;
		m_bHeadInitialized = true;
	}
	else
	{
		if (m_pHead->data > value)
		{
			if (!m_pHead->pLeft)
				m_pHead->pLeft = new Node;
			Insert(m_pHead->pLeft, value);
		}
		else
		{
			if (!m_pHead->pRight)
				m_pHead->pRight = new Node;
			Insert(m_pHead->pRight, value);
		}
	}

}
void BinarySearchTree::Insert(Node* pHead, int value)
{
	if (Trees::UNINITIALIZED_INT == pHead->data)
	{
		pHead->data = value;
	}
	else
	{
		if (pHead->data > value)
		{
			if (!pHead->pLeft)
				pHead->pLeft = new Node;
			Insert(pHead->pLeft, value);
		}
		else
		{
			if (!pHead->pRight)
				pHead->pRight = new Node;
			Insert(pHead->pRight, value);
		}

	}
}

void BinarySearchTree::TraverseTree(Trees::TraversalType type)
{
	TraverseTree(m_pHead, type);
}

void BinarySearchTree::TraverseTree(const Node* pHead, Trees::TraversalType type)
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

void BinarySearchTree::Insert(vector<int>& vInputVals)
{

}

int BinarySearchTree::GetLongestValidPath()
{

	return 0;
}

void BinarySearchTree::GraphicalRepresentationOfTree()
{

}

int BinarySearchTree::GetDepth()
{
	if (!m_pHead)
		return 0;
	else if (!m_pHead->pLeft && !m_pHead->pRight)
		return 1;

	int depth = 0;
	depth = GetDepth(const_cast<Node*>(m_pHead));

	return depth;
}

int BinarySearchTree::GetDepth(Node* node)
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



