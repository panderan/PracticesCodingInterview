#include "../../utest.h"
#include "max_value_of_gifts.h"
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

    int values1[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    retval = get_max_value_quick((const int *)values1, 3, 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 29);

    int values2[][4] = {{1,10,3,8}, {12,2,9,6}, {5,7,4,11}, {3,7,16,5}};
    retval = get_max_value_quick((const int *)values2, 4, 4);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 53);

    int values3[][4] = {{1,10,3,8}};
    retval = get_max_value_quick((const int *)values3, 1, 4);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 22);

    int values4[4][1] = {{1}, {12}, {5}, {3}};
    retval = get_max_value_quick((const int *)values4, 4, 1);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 21);

    int values5[][1] = {{3}};
    retval = get_max_value_quick((const int *)values5, 1, 1);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 3);

    retval = get_max_value_quick((const int *)NULL, 0, 0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 0);



    return;
}


