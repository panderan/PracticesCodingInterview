#include "../../utest.h"
#include "number_of_k.h"
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

    int data1[] = {1,2,3,3,3,3,4,5};
    retval = get_number_of_k(data1, sizeof(data1)/sizeof(int), 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 4);

    int data2[] = {3, 3, 3, 3, 4, 5};
    retval = get_number_of_k(data2, sizeof(data2)/sizeof(int), 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 4);

    int data3[] = {1, 2, 3, 3, 3, 3};
    retval = get_number_of_k(data3, sizeof(data3)/sizeof(int), 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 4);

    int data4[] = {1, 3, 3, 3, 3, 4, 5};
    retval = get_number_of_k(data4, sizeof(data4)/sizeof(int), 2);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 0);

    int data5[] = {1, 3, 3, 3, 3, 4, 5};
    retval = get_number_of_k(data5, sizeof(data5)/sizeof(int), 0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 0);

    int data6[] = {1, 3, 3, 3, 3, 4, 5};
    retval = get_number_of_k(data6, sizeof(data6)/sizeof(int), 6);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 0);

    int data7[] = {3, 3, 3, 3};
    retval = get_number_of_k(data7, sizeof(data7)/sizeof(int), 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 4);

    int data8[] = {3, 3, 3, 3};
    retval = get_number_of_k(data8, sizeof(data8)/sizeof(int), 4);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 0);

    int data9[] = {3};
    retval = get_number_of_k(data9, sizeof(data9)/sizeof(int), 3);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test9", retval == 1);

    int data10[] = {3};
    retval = get_number_of_k(data10, sizeof(data10)/sizeof(int), 4);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test10", retval == 0);

    retval = get_number_of_k(NULL, 0, 0);
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test11", retval == -1);
    return;
}


