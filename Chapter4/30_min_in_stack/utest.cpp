#include "../../utest.h"
#include "min_in_stack.h"
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
    stack_with_min<int> s;

    s.push(3);
    CPPUNIT_ASSERT_MESSAGE("Test1", s.min() == 3);
    s.push(4);
    CPPUNIT_ASSERT_MESSAGE("Test2", s.min() == 3);
    s.push(2);
    CPPUNIT_ASSERT_MESSAGE("Test3", s.min() == 2);
    s.push(3);
    CPPUNIT_ASSERT_MESSAGE("Test4", s.min() == 2);
    s.pop();
    CPPUNIT_ASSERT_MESSAGE("Test5", s.min() == 2);
    s.pop();
    CPPUNIT_ASSERT_MESSAGE("Test6", s.min() == 3);
    s.pop();
    CPPUNIT_ASSERT_MESSAGE("Test7", s.min() == 3);
    s.push(0);
    CPPUNIT_ASSERT_MESSAGE("Test4", s.min() == 0);
    return;
}

