#include "utest.h"
#include "merge_sorted_lists.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

bool verify(ListNode *l1, ListNode *l2, int num[])
{
	ListNode *ml = merge(l1, l2);
	if (ml == NULL) {
		return true;
	}

	ListNode *loop = ml;
	for (int i = 0; loop != NULL; loop=loop->m_pNext, i++) {
		if (loop->m_nValue != *(num+i)) {
			return false;
		}	
	}

    DestroyList(ml);
	return true;
}

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
	int num[] = {1,2,3,4,5,6};
    ListNode* pNode1 = CreateListNode(num[0]);
    ListNode* pNode3 = CreateListNode(num[2]);
    ListNode* pNode5 = CreateListNode(num[4]);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(num[1]);
    ListNode* pNode4 = CreateListNode(num[3]);
    ListNode* pNode6 = CreateListNode(num[5]);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

	CPPUNIT_ASSERT_MESSAGE("Test1", verify(pNode1, pNode2, num) == true);
    return;
}

void unit_test::second_test()
{
	int num[] = {1,1,3,3,5,5};
    ListNode* pNode1 = CreateListNode(num[0]);
    ListNode* pNode3 = CreateListNode(num[2]);
    ListNode* pNode5 = CreateListNode(num[4]);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(num[1]);
    ListNode* pNode4 = CreateListNode(num[3]);
    ListNode* pNode6 = CreateListNode(num[5]);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

	CPPUNIT_ASSERT_MESSAGE("Test2", verify(pNode1, pNode2, num) == true);
}

void unit_test::third_test()
{
	int num[] = {1,2};
    ListNode* pNode1 = CreateListNode(num[0]);
    ListNode* pNode2 = CreateListNode(num[1]);

	CPPUNIT_ASSERT_MESSAGE("Test3", verify(pNode1, pNode2, num) == true);
}

void unit_test::fourth_test()
{
	int num[] = {1,3,5};
    ListNode* pNode1 = CreateListNode(num[0]);
    ListNode* pNode3 = CreateListNode(num[1]);
    ListNode* pNode5 = CreateListNode(num[2]);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

	CPPUNIT_ASSERT_MESSAGE("Test4", verify(pNode1, NULL, num) == true);
}

void unit_test::fifth_test()
{
	int num[] = {0};
	CPPUNIT_ASSERT_MESSAGE("Test4", verify(NULL, NULL, num) == true);
}
