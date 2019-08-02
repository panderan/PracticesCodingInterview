#include "utest.h"
#include "mirror_of_binary_tree.h"
#include <cstring>
#include <iostream>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void verify(const char *message, BinaryTreeNode* pRoot, const BinaryTreeNode* truth[], int truth_len, void (mirror)(BinaryTreeNode*))
{
    const BinaryTreeNode *node_array[1024] = {NULL}; 
    int len = 0;

    (*mirror)(pRoot);
    len = PreorderTraversal(pRoot, node_array, 1024);

    CPPUNIT_ASSERT_MESSAGE(message, len == truth_len);
	std::cout<<message<<endl;
    PrintTraversal(truth, len);
    PrintTraversal(node_array, len);
    for (int i = 0; i < len; i++) {
        CPPUNIT_ASSERT_MESSAGE(message, *(node_array+i) == *(truth+i));
    }
    return;
}

void unit_test::setUp()
{
    return;
}

void unit_test::tearDown()
{
    return;
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void unit_test::first_test()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    
    const BinaryTreeNode *truth[] = {pNode8, pNode10, pNode11, NULL, NULL, pNode9, NULL, NULL, pNode6, pNode7, NULL, NULL, pNode5, NULL, NULL};   
    verify("Test1", pNode8, truth, 15, mirror_recursively);

    DestroyTree(pNode8);
    return;
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void unit_test::second_test()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    const BinaryTreeNode *truth[] = {pNode8, NULL, pNode7, NULL, pNode6, NULL, pNode5, NULL, pNode4, NULL, NULL};   
    verify("Test2", pNode8, truth, 11, mirror_recursively);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void unit_test::third_test()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    const BinaryTreeNode *truth[] = {pNode8, pNode7, pNode6, pNode5, pNode4, NULL, NULL, NULL, NULL, NULL, NULL};   
    verify("Test3", pNode8, truth, 11, mirror_recursively);

    DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void unit_test::fourth_test()
{
	mirror_recursively(NULL);
}

void unit_test::fifth_test()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    const BinaryTreeNode *truth[] = {pNode8, NULL, NULL};   
    verify("Test5", pNode8, truth, 3, mirror_recursively);
}
