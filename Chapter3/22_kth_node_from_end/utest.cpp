#include "utest.h"
#include "kth_node_from_end.h"
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

    ListNode* pNode = find_kth_to_tail(pNode1, 2);
	CPPUNIT_ASSERT_MESSAGE("Test1", pNode!=NULL && pNode->m_nValue==4);
    DestroyList(pNode1);
    return;
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

    ListNode* pNode = find_kth_to_tail(pNode1, 1);
	CPPUNIT_ASSERT_MESSAGE("Test2", pNode!=NULL && pNode->m_nValue==5);

    DestroyList(pNode1);
}

void unit_test::third_test()
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

    ListNode* pNode = find_kth_to_tail(pNode1, 5);
	CPPUNIT_ASSERT_MESSAGE("Test3", pNode!=NULL && pNode->m_nValue==1);

    DestroyList(pNode1);
}

void unit_test::fourth_test()
{
    ListNode* pNode = find_kth_to_tail(nullptr, 100);
	CPPUNIT_ASSERT_MESSAGE("Test4", pNode==NULL);
}

void unit_test::fifth_test()
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

    ListNode* pNode = find_kth_to_tail(pNode1, 6);
	CPPUNIT_ASSERT_MESSAGE("Test5", pNode==NULL);

    DestroyList(pNode1);
}

void unit_test::sixth_test()
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

    ListNode* pNode = find_kth_to_tail(pNode1, 0);
	CPPUNIT_ASSERT_MESSAGE("Test6", pNode==NULL);

    DestroyList(pNode1);
}
