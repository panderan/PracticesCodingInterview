#include "utest.h"
#include "kth_node_in_bst.h"
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

//            8
//        6      10
//       5 7    9  11
void unit_test::first_test()
{
	int retval = 0;	
	const BinaryTreeNode *retnode = NULL;

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
	
	retnode = kth_node(pNode8, 0);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_1", retval == -1);

	retnode = kth_node(pNode8, 1);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_2", retval == 5);

	retnode = kth_node(pNode8, 2);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_3", retval == 6);

	retnode = kth_node(pNode8, 3);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_4", retval == 7);

	retnode = kth_node(pNode8, 4);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_5", retval == 8);

	retnode = kth_node(pNode8, 5);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_6", retval == 9);

	retnode = kth_node(pNode8, 6);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_7", retval == 10);

	retnode = kth_node(pNode8, 7);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_8", retval == 11);

	retnode = kth_node(pNode8, 8);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test1_9", retval == -1);

    DestroyTree(pNode8);
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
	int retval = 0;	
	const BinaryTreeNode *retnode = NULL;

    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);


	retnode = kth_node(pNode5, 0);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_1", retval == -1);

	retnode = kth_node(pNode5, 1);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_2", retval == 1);

	retnode = kth_node(pNode5, 2);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_3", retval == 2);

	retnode = kth_node(pNode5, 3);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_4", retval == 3);

	retnode = kth_node(pNode5, 4);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_5", retval == 4);

	retnode = kth_node(pNode5, 5);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_6", retval == 5);

	retnode = kth_node(pNode5, 6);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test2_7", retval == -1);

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
	int retval = 0;	
	const BinaryTreeNode *retnode = NULL;

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

	retnode = kth_node(pNode1, 0);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_1", retval == -1);

	retnode = kth_node(pNode1, 1);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_2", retval == 1);

	retnode = kth_node(pNode1, 2);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_3", retval == 2);

	retnode = kth_node(pNode1, 3);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_4", retval == 3);

	retnode = kth_node(pNode1, 4);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_5", retval == 4);

	retnode = kth_node(pNode1, 5);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_6", retval == 5);

	retnode = kth_node(pNode1, 6);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test3_7", retval == -1);

    DestroyTree(pNode1);

}


void unit_test::fourth_test()
{
	int retval = 0;	
	const BinaryTreeNode *retnode = NULL;

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	retnode = kth_node(pNode1, 0);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test4_1", retval == -1);

	retnode = kth_node(pNode1, 1);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test4_2", retval == 1);

	retnode = kth_node(pNode1, 2);
	retval = retnode == NULL ? -1 : retnode->m_nValue;
	CPPUNIT_ASSERT_MESSAGE("Test4_3", retval == -1);

    DestroyTree(pNode1);
}
