#include "utest.h"
#include "serialize_binary_tree.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void _verify(const char *message, BinaryTreeNode* node1, BinaryTreeNode *node2) 
{
    if (node1 == NULL && node2 == NULL) {
        return;
    }
    CPPUNIT_ASSERT_MESSAGE(message, node1 != NULL);
    CPPUNIT_ASSERT_MESSAGE(message, node2 != NULL);
    CPPUNIT_ASSERT_MESSAGE(message, node1->m_nValue == node2->m_nValue);

    _verify(message, node1->m_pLeft, node2->m_pLeft);
    _verify(message, node1->m_pRight, node2->m_pRight);
}

void verify(const char *message, BinaryTreeNode *orig_root)
{
	char *buff = serialize(orig_root);
    printf("%s\n", buff);
    BinaryTreeNode *root = deserialize(buff);
    _verify(message, orig_root, root);
    DestroyTree(root);
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
    
    verify("Test1", pNode8);

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

    verify("Test2", pNode5);

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

    verify("Test3", pNode5);

    DestroyTree(pNode5);
}


void unit_test::fourth_test()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    verify("Test4", pNode5);

    DestroyTree(pNode5);
}

void unit_test::fifth_test()
{
    verify("Test5", NULL);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void unit_test::sixth_test()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode71, nullptr);
    ConnectTreeNodes(pNode62, nullptr, pNode72);

    verify("Test6", pNode1);

    DestroyTree(pNode1);
}

