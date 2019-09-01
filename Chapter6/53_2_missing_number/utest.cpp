#include "../../utest.h"
#include "missing_number.h"
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

    int numbers1[] = { 1, 2, 3, 4, 5 };
    retval = get_missing_number(numbers1, sizeof(numbers1)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 0);

    int numbers2[] = { 0, 1, 2, 3, 4 };
    retval = get_missing_number(numbers2, sizeof(numbers2)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 5);

    int numbers3[] = { 0, 1, 2, 4, 5 };
    retval = get_missing_number(numbers3, sizeof(numbers3)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 3);

    int numbers4[] = { 1 };
    retval = get_missing_number(numbers4, sizeof(numbers4)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 0);

    int numbers5[] = { 0 };
    retval = get_missing_number(numbers5, sizeof(numbers5)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 1);

    return;
}


