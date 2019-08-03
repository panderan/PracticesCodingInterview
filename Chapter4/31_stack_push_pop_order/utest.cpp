#include "../../utest.h"
#include "stack_push_pop_order.h"
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
    int push1[] = {1, 2, 3, 4, 5};
    int pop1[] = {4, 5, 3, 2, 1};
    CPPUNIT_ASSERT_MESSAGE("Test1", is_pop_push_order(push1, pop1, 5)==true);

    int push2[] = {1, 2, 3, 4, 5};
    int pop2[] = {3, 5, 4, 2, 1};
    CPPUNIT_ASSERT_MESSAGE("Test2", is_pop_push_order(push2, pop2, 5)==true);

    int push3[] = {1, 2, 3, 4, 5};
    int pop3[] = {4, 3, 5, 1, 2};
    CPPUNIT_ASSERT_MESSAGE("Test3", is_pop_push_order(push3, pop3, 5)==false);

    int push4[] = {1, 2, 3, 4, 5};
    int pop4[] = {3, 5, 4, 1, 2};
    CPPUNIT_ASSERT_MESSAGE("Test4", is_pop_push_order(push4, pop4, 5)==false);

    int push5[] = {1};
    int pop5[] = {2};
    CPPUNIT_ASSERT_MESSAGE("Test5", is_pop_push_order(push5, pop5, 1)==false);

    int push6[] = {1};
    int pop6[] = {1};
    CPPUNIT_ASSERT_MESSAGE("Test6", is_pop_push_order(push6, pop6, 1)==true);

    CPPUNIT_ASSERT_MESSAGE("Test7", is_pop_push_order(NULL, NULL, 0)==false);
    return;
}

