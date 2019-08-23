#include "../../utest.h"
#include "greatest_sum_of_subarray.h"
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
    int ret = 0;

    int data1[] = {1, -2, 3, 10, -4, 7, 2, -5};
    ret = find_greatest_sum_of_subarray(data1, sizeof(data1)/sizeof(int));
    printf("%d ", ret);
    CPPUNIT_ASSERT_MESSAGE("Test1", ret == 18 && g_error == false);

    int data2[] = {-2, -8, -1, -5, -9};
    ret = find_greatest_sum_of_subarray(data2, sizeof(data2)/sizeof(int));
    printf("%d ", ret);
    CPPUNIT_ASSERT_MESSAGE("Test2", ret == -1 && g_error == false);

    int data3[] = {2, 8, 1, 5, 9};
    ret = find_greatest_sum_of_subarray(data3, sizeof(data3)/sizeof(int));
    printf("%d ", ret);
    CPPUNIT_ASSERT_MESSAGE("Test3", ret == 25 && g_error == false);

    find_greatest_sum_of_subarray(NULL, 0);
    CPPUNIT_ASSERT_MESSAGE("Test4", g_error == true);




    return;
}


