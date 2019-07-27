#include "utest.h"
#include "delete_node.h"
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

void unit_test::first_test()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

	delete_node(&pNode1, pNode3);
    ListNode *p_loop = pNode1;
    int values[] = {1,2,4,5};
    for (int i=0; i<4; i++) {
        CPPUNIT_ASSERT_MESSAGE("Test1", p_loop != NULL);
        CPPUNIT_ASSERT_MESSAGE("Test1", p_loop->m_nValue == values[i]);
        p_loop = p_loop->m_pNext;
    }

    DestroyList(pNode1);
}

void unit_test::second_test()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
	delete_node(&pNode1, pNode5);

    ListNode *p_loop = pNode1;
    int values[] = {1,2,3,4};
    for (int i=0; i<4; i++) {
        CPPUNIT_ASSERT_MESSAGE("Test2", p_loop != NULL);
        CPPUNIT_ASSERT_MESSAGE("Test2", p_loop->m_nValue == values[i]);
        p_loop = p_loop->m_pNext;
    }

	DestroyList(pNode1);
    return;
}

void unit_test::thrid_test()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

	delete_node(&pNode1, pNode1);

    ListNode *p_loop = pNode1;
    int values[] = {2,3,4,5};
    for (int i=0; i<4; i++) {
        CPPUNIT_ASSERT_MESSAGE("Test3", p_loop != NULL);
        CPPUNIT_ASSERT_MESSAGE("Test3", p_loop->m_nValue == values[i]);
        p_loop = p_loop->m_pNext;
    }

	DestroyList(pNode1);
    return;
}

void unit_test::fourth_test()
{
    ListNode* pNode1 = CreateListNode(1);
	delete_node(&pNode1, pNode1);
	CPPUNIT_ASSERT_MESSAGE("Test4", pNode1 == NULL);
}

void unit_test::fiveth_test()
{
    delete_node(NULL, NULL);
}
