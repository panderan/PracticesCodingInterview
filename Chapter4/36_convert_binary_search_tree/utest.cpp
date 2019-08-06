#include "utest.h"
#include "convert_binary_search_tree.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void verify(const char *message, BinaryTreeNode *origin)
{
    const BinaryTreeNode* arr[1024] = {0}, *bt_list = NULL, *loop = NULL;
    int len = 0, i = 0;

    len = InorderTraversal(origin, arr, 1024);
    PrintTraversal(arr, len);
 	bt_list = convert(origin);

    for (i=len, loop=bt_list; i<len; i++, loop=loop->m_pRight) {
    	CPPUNIT_ASSERT_MESSAGE(message, arr[i] == loop);
    }
}

void unit_test::setUp()
{
    return;
}

void unit_test::tearDown()
{
    return;
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void unit_test::first_test()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

	verify("Test1", pNode10);

    DestroyList(pNode4);
    return;
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void unit_test::second_test()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

	verify("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void unit_test::third_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

	verify("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void unit_test::fourth_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	verify("Test4", pNode1);

    DestroyList(pNode1);
}

