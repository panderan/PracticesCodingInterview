#include "utest.h"
#include "print_trees_in_lines.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void verify(const char * message, BinaryTreeNode* p_root, BinaryTreeNode* truth[], int length)
{
	BinaryTreeNode *out[1024] = {NULL};
	print_trees_in_lines(p_root, out, 1024);

	for (int i = 0; i < length; i++) {
		CPPUNIT_ASSERT_MESSAGE(message, truth[i] == out[i]);
		if (out[i]) {
			printf("%d ", out[i]->m_nValue);
		}
		else {
			printf("\n");
		}
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

	BinaryTreeNode *truth[] = {pNode8, NULL, pNode6, pNode10, NULL, pNode5, pNode7, pNode9, pNode11, NULL};
	verify("Test1", pNode8, truth, 10);
    DestroyTree(pNode8);
    return;
}

//            5
//          4
//        3
//      2
void unit_test::second_test()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

	BinaryTreeNode *truth[] = {pNode5, NULL, pNode4, NULL, pNode3, NULL, pNode2, NULL};
	verify("Test2", pNode5, truth, 8);

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void unit_test::third_test()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

	BinaryTreeNode *truth[] = {pNode5, NULL, pNode4, NULL, pNode3, NULL, pNode2, NULL};
	verify("Test3", pNode5, truth, 8);

    DestroyTree(pNode5);
}


void unit_test::fourth_test()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	BinaryTreeNode *truth[] = {pNode5};
	verify("Test4", pNode5, truth, 1);

    DestroyTree(pNode5);
}

void unit_test::fifth_test()
{
	verify("Test5", NULL, NULL, 0);
}

//        100
//        /
//       50   
//         \
//         150
void unit_test::sixth_test()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

	BinaryTreeNode *truth[] = {pNode100, NULL, pNode50, NULL, pNode150, NULL};
	verify("Test6", pNode100, truth, 6);
}

