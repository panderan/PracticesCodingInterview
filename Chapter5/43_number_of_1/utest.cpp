#include "../../utest.h"
#include "number_of_1.h"
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
    int retval = 0;

    retval = number_of_1(1);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 1);

    retval = number_of_1(5);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 1);

    retval = number_of_1(10);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 2);

    retval = number_of_1(55);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 16);

    retval = number_of_1(99);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 20);

    retval = number_of_1(10000);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 4001);

    retval = number_of_1(21345);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 18821);

    retval = number_of_1(0);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 0);

    return;
}


