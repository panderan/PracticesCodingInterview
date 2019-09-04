#include "utest.h"
#include "tree_depth.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void unit_test::setUp()
{
    return;
}

void unit_test::tearDown()
{
    return;
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void unit_test::first_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, nullptr, pNode6);
    ConnectTreeNodes(pNode5, pNode7, nullptr);

	int depth = tree_depth(pNode1);
	printf("%d\n", depth);
	CPPUNIT_ASSERT_MESSAGE("Test1", depth == 4); 

    DestroyTree(pNode1);
    return;
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void unit_test::second_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);

	int depth = tree_depth(pNode1);
	printf("%d\n", depth);
	CPPUNIT_ASSERT_MESSAGE("Test2", depth == 5); 

    DestroyTree(pNode1);

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

	int depth = tree_depth(pNode1);
	printf("%d\n", depth);
	CPPUNIT_ASSERT_MESSAGE("Test3", depth == 5); 

    DestroyTree(pNode1);
}

// 树中只有1个结点
void unit_test::fourth_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	int depth = tree_depth(pNode1);
	printf("%d\n", depth);
	CPPUNIT_ASSERT_MESSAGE("Test4", depth == 1); 

    DestroyTree(pNode1);
}

// 树中没有结点
void unit_test::fifth_test()
{
	int depth = tree_depth(NULL);
	printf("%d\n", depth);
	CPPUNIT_ASSERT_MESSAGE("Test5", depth == 0); 
}
