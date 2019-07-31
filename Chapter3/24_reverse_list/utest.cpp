#include "utest.h"
#include "reverse_list.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

bool verify(ListNode *p_head)
{
	int num[1024], i=0, cnt=0;
	ListNode *loop = p_head;
    ListNode *re_head = NULL;

	if (loop == NULL) {
        return false;
    }

    for (cnt=0; loop!=NULL; num[cnt++]=loop->m_nValue, loop=loop->m_pNext);
    re_head = reverse_list(p_head);

    for (i=cnt-1, loop=re_head; i>=0; i--, loop=loop->m_pNext) {
        if (num[i] != loop->m_nValue) {
            return false;
        }
    }
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
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    CPPUNIT_ASSERT_MESSAGE("Test1", verify(pNode1)==true);
    DestroyList(pNode5);
    return;
}

void unit_test::second_test()
{
    ListNode* pNode1 = CreateListNode(1);

    CPPUNIT_ASSERT_MESSAGE("Test2", verify(pNode1)==true);

    DestroyList(pNode1);
}

void unit_test::third_test()
{
    CPPUNIT_ASSERT_MESSAGE("Test3", verify(NULL)==false);
}

