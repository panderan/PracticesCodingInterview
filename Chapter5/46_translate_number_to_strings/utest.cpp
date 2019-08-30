#include "../../utest.h"
#include "translate_number_to_strings.h"
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
    int retval;

    retval = get_translate_count(0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 1);

    retval = get_translate_count(10);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 2);

    retval = get_translate_count(125);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 3);

    retval = get_translate_count(126);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 2);

    retval = get_translate_count(426);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 1);

    retval = get_translate_count(100);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 2);

    retval = get_translate_count(101);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 2);

    retval = get_translate_count(12258);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 5);

    return;
}

