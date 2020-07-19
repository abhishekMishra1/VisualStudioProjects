#pragma once
//#include <mutex>
#include <iostream>

namespace MyDS
{
	template <typename T>
	struct Node
	{
		T* m_pData = nullptr;
		Node* m_pNext = nullptr;
	};

	template <class T>
	class sList
	{
		Node<T>* m_pHead = nullptr;
		Node<T>* m_pCurrentNode = nullptr;
		int m_Size = 0;
		//std::mutex m_ListMutex;

	public:
		bool insert_front(T val);
		bool insert_last(T val);
		bool insert_anywhere(T val, int loc);

		bool remove(T val);
		//bool remove(int loc);
		bool remove_front();
		bool remove_last();

		void traverse();
		void traverse_reverse();

		bool emptyList();

		int getSize();

	private:
		void traverse_reverse(Node<T>* pNode);
	};

	template<typename T>
	void sList<T>::traverse_reverse(Node<T>* pNode)
	{
		if (pNode->m_pNext != nullptr)
			traverse_reverse(pNode->m_pNext);
		std::cout << *pNode->m_pData << " ";
	}

	template<typename T>
	bool sList<T>::emptyList()
	{
		bool ret = false;
		if (getSize() > 0)
		{
			//std::lock_guard<std::mutex> lg(m_ListMutex);

			Node<T>* pTempNode = m_pHead, pTempNode1 = nullptr;
			while (pTempNode->m_pNext!= nullptr)
			{
				pTempNode1 = pTempNode->m_pNext;

				delete pTempNode->m_pData;
				delete pTempNode;
				pTempNode = pTempNode1;
			}

			delete pTempNode->m_pData;
			delete pTempNode;

			pTempNode->m_pData = pTempNode1->m_pData = m_pHead->m_pData = m_pCurrentNode->m_pData = nullptr;
			pTempNode = pTempNode1 = m_pHead = m_pCurrentNode = nullptr;
			m_Size = 0;
		}

		ret = true;
		return ret;
	}

	template<typename T>
	int sList<T>::getSize()
	{
		return m_Size;
	}

	template<typename T>
	bool sList<T>::insert_front(T val)
	{
		Node<T>* pNode = new Node<T>;
		pNode->m_pData = new T(val);

		if (getSize() > 0)
		{
			pNode->m_pNext = m_pHead;
		}

		m_pHead = pNode;
		m_Size++;

		return true;
	}


	template<typename T>
	bool sList<T>::insert_last(T val)
	{
		Node<T>* plastNode = m_pHead;
		while (plastNode->m_pNext!= nullptr)
			plastNode = plastNode->m_pNext;

		plastNode->m_pNext = new Node<T>;
		plastNode->m_pNext->m_pData = new T(val);

		return true;
	}


	template<typename T>
	bool sList<T>::insert_anywhere(T val, int loc)
	{
		return true;
	}

	
	//template<typename T>
	//bool sList<T>::remove(int loc)
	//{
	//	return true;
	//}


	template<typename T>
	bool sList<T>::remove_front()
	{
		//std::lock_guard<std::mutex> lg(m_ListMutex);
		Node<T>* pNode = m_pHead;
		m_pHead = m_pHead->m_pNext;

		delete pNode->m_pData;
		delete pNode;

		m_Size--;
		return true;
	}

	template<typename T>
	bool sList<T>::remove_last()
	{
		Node<T>* plastNode = m_pHead;
		//std::lock_guard<std::mutex> lg(m_ListMutex);
		if (getSize() > 1)
		{
			while (plastNode->m_pNext->m_pNext != nullptr)
				plastNode = plastNode->m_pNext;

			Node<T>* pNode = plastNode->m_pNext;
			plastNode->m_pNext = nullptr;

			delete pNode->m_pData;
			delete pNode;
			pNode->m_pData = pNode = nullptr;
			m_Size--;
		}
		else if(getSize() == 1) // Only 1 node 
		{
			delete m_pHead->m_pData;
			delete m_pHead;

			m_pHead->m_pData = m_pHead = nullptr;
			m_Size--;
		}
		else   // No node available
		{
			//Nothing to do	
		}

		return true;

	}

	template<typename T>
	bool sList<T>::remove(T val)
	{
		bool ret = false;
		Node<T>* pNode = m_pHead;
		Node<T>* pNodeNext = pNode->m_pNext;

		if (pNode->m_pData == val)
		{
			ret = remove_front();
		}
		else if (pNodeNext->m_pData == val)
		{
			pNode->m_pNext = pNodeNext->m_pNext;
			pNodeNext->m_pNext = nullptr;
			
			delete pNodeNext->m_pData;
			delete pNodeNext;
			pNodeNext->m_pData = pNodeNext = nullptr;
			ret = true;
			m_Size--;
		}
		else
		{
			while (pNodeNext->m_pData != val)
			{
				pNode = pNodeNext;
				pNodeNext = pNodeNext->m_pNext;
			}

			if (pNodeNext == nullptr)
				ret = false;
			else
			{
				pNode->m_pNext = pNodeNext->m_pNext;
				pNodeNext->m_pNext = nullptr;

				delete pNodeNext->m_pData;
				delete pNodeNext;
				pNodeNext->m_pData = pNodeNext = nullptr;
				m_Size--;
				ret = true;
			}
		}

		return ret;
	}

	template<typename T>
	void sList<T>::traverse()
	{
		m_pCurrentNode = m_pHead;
		while (m_pCurrentNode->m_pNext != nullptr)
		{
			std::cout << *m_pCurrentNode->m_pData<<" ";
			m_pCurrentNode = m_pCurrentNode->m_pNext;
		}

		std::cout << *m_pCurrentNode->m_pData;
		std::cout << std::endl;
	}
		
	template<typename T>
	void sList<T>::traverse_reverse()
	{
		m_pCurrentNode = m_pHead;
		traverse_reverse(m_pCurrentNode);
		std::cout << std::endl;
	}

}
