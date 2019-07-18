#include "utest.h"
#include "next_node_in_binary_trees.h"
#include <cstring>
#include <unistd.h>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void unit_test::setUp()
{
    return;
}

void unit_test::tearDown()
{
    return;
}

void unit_test::first_test()
{
    BinaryTreeNode* retval = NULL;
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

    retval = get_next(pNode8);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval->m_nValue == pNode9->m_nValue);
    retval = get_next(pNode6);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval->m_nValue == pNode7->m_nValue);
    retval = get_next(pNode10);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval->m_nValue == pNode11->m_nValue);
    retval = get_next(pNode5);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval->m_nValue == pNode6->m_nValue);
    retval = get_next(pNode7);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval->m_nValue == pNode8->m_nValue);
    retval = get_next(pNode9);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval->m_nValue == pNode10->m_nValue);
    retval = get_next(pNode11);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == NULL);
    return;
}

void unit_test::second_test()
{
    BinaryTreeNode* retval = NULL;
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    retval = get_next(pNode5);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == NULL);
    retval = get_next(pNode4);
    CPPUNIT_ASSERT_MESSAGE("Test9", retval->m_nValue == pNode5->m_nValue);
    retval = get_next(pNode3);
    CPPUNIT_ASSERT_MESSAGE("Test10", retval->m_nValue == pNode4->m_nValue);
    retval = get_next(pNode2);
    CPPUNIT_ASSERT_MESSAGE("Test11", retval->m_nValue == pNode3->m_nValue);
}

void unit_test::thrid_test()
{
    BinaryTreeNode* retval = NULL;
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    retval = get_next(pNode5);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == NULL);
    retval = get_next(pNode4);
    CPPUNIT_ASSERT_MESSAGE("Test9", retval->m_nValue == pNode5->m_nValue);
    retval = get_next(pNode3);
    CPPUNIT_ASSERT_MESSAGE("Test10", retval->m_nValue == pNode4->m_nValue);
    retval = get_next(pNode2);
    CPPUNIT_ASSERT_MESSAGE("Test11", retval->m_nValue == pNode3->m_nValue);
}

void unit_test::fourth_test()
{
    BinaryTreeNode* retval = NULL;
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    retval = get_next(pNode5);
    CPPUNIT_ASSERT_MESSAGE("Test11", retval == NULL);
}
