#ifndef _BINARY_TREE_NODE_H
#define _BINARY_TREE_NODE_H

/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#pragma once

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
    BinaryTreeNode*        m_pParent;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
int PreorderTraversal(const BinaryTreeNode *pRoot, const BinaryTreeNode* nl[], int length);
int InorderTraversal(const BinaryTreeNode *pRoot, const BinaryTreeNode* nl[], int length);
void PostorderTraversal(const BinaryTreeNode *pRoot, int num[], int length);
void PrintTraversal(const BinaryTreeNode *nl[], int length);
#endif
