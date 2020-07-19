#pragma once

namespace NODES
{
	template<typename T>
	struct BstNode
	{
		BstNode* m_pLeft = nullptr;
		BstNode* m_pRight = nullptr;
		T m_Data;
	};

	template <typename T>
	struct SSListNode
	{
		T* m_pData = nullptr;
		SSListNode* m_pNext = nullptr;
	};
}