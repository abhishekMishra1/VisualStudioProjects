#pragma once
#include <iostream>
#include "Nodes.h"

#define _DEBUG_ENABLED 0

namespace BinarySearchTree {

#if(_DEBUG_ENABLED)
    using namespace std;
#define LOGINFO(x) cout<< ##x <<std::endl;
#else
#define LOGINFO(x)
#endif

    template<typename T>
    class BST
    {
        NODES::BstNode<T>* m_pHead = nullptr;

    public:
        BST();
        ~BST();
        BST(const BST&);
        BST& operator=(const BST&);

        //iterators

        //public functions
        bool insertElement(const NODES::BstNode<T>* p);
        bool insertElement(T& val);
        bool deleteElement(NODES::BstNode<T>* p);
        bool deleteElement(T& val);
        void traverseBST();
        bool treeCreated();
        unsigned int depth();
        unsigned int siblings();
        NODES::BstNode<T>* GetRootNode(NODES::BstNode<T>* p);
        void GetRootNode(NODES::BstNode<T>* pNode, NODES::BstNode<T>* pLeftChild, NODES::BstNode<T>* pRightChild);


    protected:
        void traverseInOrder(NODES::BstNode<T>* root);
        void traversPreOrder(NODES::BstNode<T>* root);
        void traversePostOrder(NODES::BstNode<T>* root);
        bool insertElement(NODES::BstNode<T>* head, const T& val);

    private:
        unsigned int m_Depth = 0;
    };


    template<typename T>
    BST<T>::BST()
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    BST<T>::~BST()
    {
        LOGINFO(__FUNCTION__);
        //Need to delete all nodes

    }

    template<typename T>
    BST<T>::BST(const BST&)
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    BST<T>& BST<T>::operator=(const BST&)
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    bool BST<T>::insertElement(const NODES::BstNode<T>* p)
    {
        bool ret = false;
        LOGINFO(__FUNCTION__);
        if (treeCreated())
        {
            NODES::BstNode<T>* tempNode = m_pHead;
            if (tempNode->m_Data > p->m_Data)
            {
                ret = insertElement(tempNode->m_pLeft, p->m_Data);
            }
            else
            {
                ret = insertElement(tempNode->m_pRight, p->m_Data);
            }
        }
        else
        {
            m_pHead = new NODES::BstNode<T>;
            m_pHead->m_Data = data;
            ret = true;
        }

        return ret;
    }

    template<typename T>
    bool BST<T>::insertElement(T& data)
    {
        LOGINFO(__FUNCTION__);
        bool ret = false;
        if (treeCreated())
        {
            NODES::BstNode<T>* tempNode = m_pHead;
            if (tempNode->m_Data > data)
            {
                if(tempNode->m_pLeft)
                    ret = insertElement(tempNode->m_pLeft, data);
                else
                {
                    tempNode->m_pLeft = new NODES::BstNode<T>;
                    tempNode->m_pLeft->m_Data = data;
                    ret = true;
                }
            }
            else
            {
                if (tempNode->m_pRight)
                    ret = insertElement(tempNode->m_pRight, data);
                else
                {
                 
                    tempNode->m_pRight = new NODES::BstNode<T>;
                    tempNode->m_pRight->m_Data = data;
                    ret = true;
                }
            }
        }
        else
        {
            m_pHead = new NODES::BstNode<T>;
            m_pHead->m_Data = data;
            ret = true;
        }

        return ret;
    }

    template<typename T>
    bool BST<T>::deleteElement(NODES::BstNode<T>* p)
    {
        LOGINFO(__FUNCTION__);
        NODES::BstNode<T>* tempNode = m_pHead;
        if (m_pHead == p && m_pHead->m_Data == p->m_Data)
        {

        }
    }

    template<typename T>
    bool BST<T>::deleteElement(T& val)
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    void BST<T>::traverseBST()
    {
        LOGINFO(__FUNCTION__);
        if (treeCreated())
        {
            traverseInOrder(m_pHead);
        }
        std::cout << std::endl;
    }



    template<typename T>
    bool BST<T>::treeCreated()
    {
        return (m_pHead != nullptr);
    }

    template<typename T>
    void BST<T>::traverseInOrder(NODES::BstNode<T>* root)
    {
        LOGINFO(__FUNCTION__);
        if (root->m_pLeft)
            traverseInOrder(root->m_pLeft);
        std::cout << root->m_Data << " ";
        if (root->m_pRight)
            traverseInOrder(root->m_pRight);
    }

    template<typename T>
    void BST<T>::traversPreOrder(NODES::BstNode<T>* root)
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    void BST<T>::traversePostOrder(NODES::BstNode<T>* root)
    {
        LOGINFO(__FUNCTION__);
    }

    template<typename T>
    bool BST<T>::insertElement(NODES::BstNode<T>* root, const T& val)
    {
        bool ret = false;
        if (root->m_Data > val)
        {
            if (root->m_pLeft)
            {
                m_Depth++;
                insertElement(root->m_pLeft, val);
            }
            else
            {
                root->m_pLeft = new NODES::BstNode<T>;
                root->m_pLeft->m_Data = val;
                ret = true;
            }
        }
        else
        {
            if (root->m_pRight)
            {
                m_Depth++;
                insertElement(root->m_pRight, val);
            }
            else
            {
                root->m_pRight = new NODES::BstNode<T>;
                root->m_pRight->m_Data = val;
                ret = true;
            }
        }
        return ret;
    }

    template<typename T>
    unsigned int BST<T>::depth()
    {
        LOGINFO(__FUNCTION__);
        return m_Depth;
    }

    template<typename T>
    unsigned int BST<T>::siblings()
    {
    }

    template<typename T>
    NODES::BstNode<T>* BST<T>::GetRootNode(NODES::BstNode<T>* p)
    {
    }

    template<typename T>
    void BST<T>::GetRootNode(NODES::BstNode<T>* pNode, NODES::BstNode<T>* pLeftChild, NODES::BstNode<T>* pRightChild)
    {
    }

}