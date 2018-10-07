#include "BinarySearchTree.h"
#include <iostream>
#include "GameConstants.h"

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

void BinarySearchTree::TraverseTree()
{
	TraverseTree(m_pHead);
}

void BinarySearchTree::TraverseTree(const Node* pHead)
{
	if (!pHead)
		return;
	TraverseTree(pHead->pLeft);
	cout << pHead->data << " ";
	TraverseTree(pHead->pRight);
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