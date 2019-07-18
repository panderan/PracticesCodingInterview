#include "../../utest.h"
#include "fibonacci.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test0", fibonacci(0) == 0);
    CPPUNIT_ASSERT_MESSAGE("Test1", fibonacci(1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test2", fibonacci(2) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", fibonacci(3) == 2);
    CPPUNIT_ASSERT_MESSAGE("Test4", fibonacci(4) == 3);
    CPPUNIT_ASSERT_MESSAGE("Test5", fibonacci(5) == 5);
    CPPUNIT_ASSERT_MESSAGE("Test6", fibonacci(6) == 8);
    CPPUNIT_ASSERT_MESSAGE("Test7", fibonacci(7) == 13);
    CPPUNIT_ASSERT_MESSAGE("Test8", fibonacci(8) == 21);
    CPPUNIT_ASSERT_MESSAGE("Test9", fibonacci(9) == 34);
    CPPUNIT_ASSERT_MESSAGE("Test10", fibonacci(10) == 55);
}


