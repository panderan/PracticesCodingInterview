#include "../../utest.h"
#include "print_list_in_reversed_order.h"
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
	char buff[1024] = "\0";
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    strcpy(buff, "");
	print_list_in_reversed_order(pNode1, buff, 1024);
	CPPUNIT_ASSERT_MESSAGE("TEST1", strcmp(buff, "5,4,3,2,1") == 0);
    DestroyList(pNode1);

    pNode1 = CreateListNode(1);
    strcpy(buff, "");
	print_list_in_reversed_order(pNode1, buff, 1024);
	CPPUNIT_ASSERT_MESSAGE("TEST2", strcmp(buff, "1") == 0);
    DestroyList(pNode1);
    
    strcpy(buff, "");
	print_list_in_reversed_order(NULL, buff, 1024);
	CPPUNIT_ASSERT_MESSAGE("TEST2", strcmp(buff, "") == 0);
    return;
}


