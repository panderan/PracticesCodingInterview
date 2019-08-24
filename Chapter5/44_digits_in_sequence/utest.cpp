#include "../../utest.h"
#include "digits_in_sequence.h"
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

    retval = digit_at_index(0);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 0);

    retval = digit_at_index(1);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 1);

    retval = digit_at_index(9);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 9);

    retval = digit_at_index(10);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 1);

    retval = digit_at_index(189);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 9);

    retval = digit_at_index(190);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 1);

    retval = digit_at_index(1000);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 3);

    retval = digit_at_index(1001);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 7);

    retval = digit_at_index(1002);
    printf("%d ", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 0);
    return;
}


