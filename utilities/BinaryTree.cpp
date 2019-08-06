/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/ 
//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================
#include <stack>
#include <cstdio>
#include "BinaryTree.h"

using namespace std;

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if(pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

int PreorderTraversal(const BinaryTreeNode *pRoot, const BinaryTreeNode* nl[], int length)
{
    stack<const BinaryTreeNode *> s;
    int i = 0;

    if (pRoot == NULL || nl == NULL || length < 1) {
        return 0;
    }

    s.push(pRoot);
    while (s.empty() == false) {
        const BinaryTreeNode *tmp = s.top();
        *(nl+i++) = tmp;
        s.pop();

        if (i==length) {
            return i;
        }

		if (tmp != NULL) {
        	s.push(tmp->m_pRight);
        	s.push(tmp->m_pLeft);
		}
    }

    return i;
}

int InorderTraversal(const BinaryTreeNode *pRoot, const BinaryTreeNode* nl[], int length)
{
    stack<const BinaryTreeNode *>s;
	const BinaryTreeNode *loop = pRoot;
    int i = 0;

    if (pRoot == NULL || nl == NULL || length < 1) {
        return 0;
    }

	for (loop=pRoot,s.push(loop); loop->m_pLeft!=NULL; loop=loop->m_pLeft, s.push(loop)){}

    while (s.empty()==false) {
        const BinaryTreeNode * tmp = s.top();
        *(nl+i++) = tmp;
        s.pop();

        if (i==length) {
            return i;
        }

        if (tmp->m_pRight) {
			for (loop=tmp->m_pRight,s.push(loop); loop->m_pLeft!=NULL; loop=loop->m_pLeft, s.push(loop));
        }
    }
    return i;
}

void PostorderTraversal(const BinaryTreeNode *pRoot, BinaryTreeNode* nl[], int length)
{

}

void PrintTraversal(const BinaryTreeNode *nl[], int length)
{
    for (int i=0; i<length; i++) {
        if (*(nl+i) == NULL) {
            printf("Null");
        }
        else {
            printf("%d", (*(nl+i))->m_nValue);
        }
        if (i==length-1) {
            printf("\n");
        }
        else {
            printf(", ");
        }
    }
}
