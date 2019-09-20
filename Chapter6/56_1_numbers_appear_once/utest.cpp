#include "../../utest.h"
#include "numbers_appear_once.h"
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
    int data1[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    int retvals1[2];
    find_nums_appear_once(data1, sizeof(data1)/sizeof(int), retvals1, 2);
    CPPUNIT_ASSERT_MESSAGE("Test1", (retvals1[0]==4&&retvals1[1]==6)||((retvals1[0]==6&&retvals1[1]==4)));

    int data2[] = { 4, 6 };
    int retvals2[2];
    find_nums_appear_once(data2, sizeof(data2)/sizeof(int), retvals2, 2);
    CPPUNIT_ASSERT_MESSAGE("Test2", (retvals2[0]==4&&retvals2[1]==6)||((retvals2[0]==6&&retvals2[1]==4)));

    int data3[] = { 4, 6, 1, 1, 1, 1 };
    int retvals3[2];
    find_nums_appear_once(data3, sizeof(data3)/sizeof(int), retvals3, 2);
    CPPUNIT_ASSERT_MESSAGE("Test3", (retvals3[0]==4&&retvals3[1]==6)||((retvals3[0]==6&&retvals3[1]==4)));

    return;
}


