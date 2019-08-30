#include "../../utest.h"
#include "ugly_number.h"
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
    int retval = 0;;

    retval = get_ugly_number(1);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 1);

    retval = get_ugly_number(2);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 2);

    retval = get_ugly_number(3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 3);

    retval = get_ugly_number(4);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 4);

    retval = get_ugly_number(5);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 5);

    retval = get_ugly_number(6);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 6);

    retval = get_ugly_number(7);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 8);

    retval = get_ugly_number(8);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 9);

    retval = get_ugly_number(9);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test9", retval == 10);

    retval = get_ugly_number(10);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test10", retval == 12);

    retval = get_ugly_number(11);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test11", retval == 15);

    retval = get_ugly_number(1500);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test12", retval == 859963392);

    return;
}


