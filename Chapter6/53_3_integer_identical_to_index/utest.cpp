#include "../../utest.h"
#include "integer_identical_to_index.h"
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

    int numbers1[] = { -3, -1, 1, 3, 5 };
    retval = get_number_same_as_index(numbers1, sizeof(numbers1)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 3);

    int numbers2[] = { 0, 1, 3, 5, 6 };
    retval = get_number_same_as_index(numbers2, sizeof(numbers2)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 0 || retval == 1);

    int numbers3[] = { -1, 0, 1, 2, 4 };
    retval = get_number_same_as_index(numbers3, sizeof(numbers3)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 4);

    int numbers4[] = { -1, 0, 1, 2, 5 };
    retval = get_number_same_as_index(numbers4, sizeof(numbers4)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == -1);

    int numbers5[] = { 0 };
    retval = get_number_same_as_index(numbers5, sizeof(numbers5)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 0);

    int numbers6[] = { 10 };
    retval = get_number_same_as_index(numbers6, sizeof(numbers6)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == -1);

    retval = get_number_same_as_index(NULL, 0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == -1);

    return;
}


