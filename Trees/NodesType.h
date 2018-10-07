#ifndef _NODE_TYPES_
#define _NODE_TYPES_
//Binary Tree
struct Node
{
	mutable int data = -999;
	mutable Node* pLeft = nullptr;
	mutable Node* pRight = nullptr;

	//Node();
	// ~Node();

};

//Node::Node()
//{
//}

//Node::~Node()
//{
//	if (pLeft)
//		delete pLeft;
//	if (pRight)
//		delete pRight;
//	pLeft = pRight = nullptr;
//}

#endif
