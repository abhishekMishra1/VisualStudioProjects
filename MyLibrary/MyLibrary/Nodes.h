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
}