#include "../../utest.h"
#include "inverse_pairs.h"
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
    int data1[] = {1,2,3,4,7,6,5}, retval = 0;
    retval = inverse_pairs(data1, sizeof(data1)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 3);

    int data2[] = {6, 5, 4, 3, 2, 1};
    retval = inverse_pairs(data2, sizeof(data2)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 15);

    int data3[] = {1, 2, 3, 4, 5, 6};
    retval = inverse_pairs(data3, sizeof(data3)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 0);

    int data4[] = {1};
    retval = inverse_pairs(data4, sizeof(data4)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 0);

    int data5[] = {1,2};
    retval = inverse_pairs(data5, sizeof(data5)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 0);

    int data6[] = {2,1};
    retval = inverse_pairs(data6, sizeof(data6)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 1);

    int data7[] = {1,2,1,2,1};
    retval = inverse_pairs(data7, sizeof(data7)/sizeof(int));
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 3);

    retval = inverse_pairs(NULL, 0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 0);

    return;
}


