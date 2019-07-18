#include "utest.h"
#include "robot_move.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test1", moving_count(5, 10, 10) == 21);
    CPPUNIT_ASSERT_MESSAGE("Test2", moving_count(15, 20, 20) == 359);
    CPPUNIT_ASSERT_MESSAGE("Test3", moving_count(10, 1, 100) == 29);
    CPPUNIT_ASSERT_MESSAGE("Test4", moving_count(10, 1, 10) == 10);
    CPPUNIT_ASSERT_MESSAGE("Test5", moving_count(15, 100, 1) == 79);
    CPPUNIT_ASSERT_MESSAGE("Test6", moving_count(15, 10, 1) == 10);
    CPPUNIT_ASSERT_MESSAGE("Test7", moving_count(15, 1, 1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test8", moving_count(0, 1, 1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test9", moving_count(-10, 10, 10) == 0);
    return;
}

void unit_test::second_test()
{
    CPPUNIT_ASSERT_MESSAGE("Test10", moving_count2(5, 10, 10) == 21);
    CPPUNIT_ASSERT_MESSAGE("Test11", moving_count2(15, 20, 20) == 359);
    CPPUNIT_ASSERT_MESSAGE("Test12", moving_count2(10, 1, 100) == 29);
    CPPUNIT_ASSERT_MESSAGE("Test13", moving_count2(10, 1, 10) == 10);
    CPPUNIT_ASSERT_MESSAGE("Test14", moving_count2(15, 100, 1) == 79);
    CPPUNIT_ASSERT_MESSAGE("Test15", moving_count2(15, 10, 1) == 10);
    CPPUNIT_ASSERT_MESSAGE("Test16", moving_count2(15, 1, 1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test17", moving_count2(0, 1, 1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test18", moving_count2(-10, 10, 10) == 0);
    return;
}

