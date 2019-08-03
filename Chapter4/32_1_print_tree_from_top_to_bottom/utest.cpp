#include "utest.h"
#include "print_tree_from_top_to_bottom.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void verify(const char * message, BinaryTreeNode *p_root, int truth[], int length)
{
	int out[1024] = {0};

	print_from_top_to_bottom(p_root, out, 1024);

	for (int i = 0; i < length; i++) {
		CPPUNIT_ASSERT_MESSAGE(message, out[i] == truth[i]);
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

	int truth[7] = {10, 6, 14, 4, 8, 12, 16};
	verify("Test1", pNode10, truth, 7);

	DestroyTree(pNode10);
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

	int truth[5] = {5,4,3,2,1};
	verify("Test2", pNode5, truth, 5);

    DestroyTree(pNode5);
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

	int truth[5] = {1,2,3,4,5};
	verify("Test3", pNode1, truth, 5);

    DestroyTree(pNode1);
}

void unit_test::fourth_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	int truth[1] = {1};
	verify("Test4", pNode1, truth, 1);

    DestroyTree(pNode1);
}

void unit_test::fifth_test()
{
	verify("Test5", NULL, NULL, 0);
}





















