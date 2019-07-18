#include "utest.h"
#include "number_of_one.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test1", number_of_one(0) == 0);
    CPPUNIT_ASSERT_MESSAGE("Test2", number_of_one(1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", number_of_one(10) == 2);
    CPPUNIT_ASSERT_MESSAGE("Test4", number_of_one(0x7fffffff) == 31);
    CPPUNIT_ASSERT_MESSAGE("Test5", number_of_one(0xffffffff) == 32);
    CPPUNIT_ASSERT_MESSAGE("Test6", number_of_one(0x80000000) == 1);
    return;
}

void unit_test::second_test()
{
    CPPUNIT_ASSERT_MESSAGE("Test1", number_of_one2(0) == 0);
    CPPUNIT_ASSERT_MESSAGE("Test2", number_of_one2(1) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", number_of_one2(10) == 2);
    CPPUNIT_ASSERT_MESSAGE("Test4", number_of_one2(0x7fffffff) == 31);
    CPPUNIT_ASSERT_MESSAGE("Test5", number_of_one2(0xffffffff) == 32);
    CPPUNIT_ASSERT_MESSAGE("Test6", number_of_one2(0x80000000) == 1);
    return;
}
