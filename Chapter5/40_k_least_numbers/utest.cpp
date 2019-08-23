#include "../../utest.h"
#include "k_least_numbers.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

int compare_ints(const void *a, const void *b)
{
    int arg1 = *reinterpret_cast<const int *>(a);
    int arg2 = *reinterpret_cast<const int *>(b);

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void print_nums(int numbers[], int length)
{
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%d ", *(numbers+i));
    }
    printf("\n");
}

void verify(const char *message, int numbers[], int length, int expected[], int n, bool error_flag)
{
    int least_k[1024] = {0}, i = 0;

    get_least_numbers_quick(numbers, length, least_k, n); 
    qsort(least_k, n, sizeof(int), compare_ints);
    qsort(expected, n, sizeof(int), compare_ints);
     
    print_nums(least_k, n);
    for (i = 0; i < n; i++) {
        CPPUNIT_ASSERT_MESSAGE(message, least_k[i] == expected[i] && g_error == error_flag);
    }

}

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
    int data1[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected1[] = {1, 2, 3, 4};
    verify("Test1", data1, sizeof(data1)/sizeof(int), expected1, sizeof(expected1)/sizeof(int), false);

    int data2[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8};
	verify("Test2", data2, sizeof(data2)/sizeof(int), expected2, sizeof(expected2)/sizeof(int), false);	

    int data3[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected3 = nullptr;
	verify("Test3", data3, sizeof(data3)/sizeof(int), NULL, 0, true);	

    int data4[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected4[] = {1};
	verify("Test4", data4, sizeof(data4)/sizeof(int), expected4, sizeof(expected4)/sizeof(int), false);	

    int data5[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected5 = nullptr;
	verify("Test5", data5, sizeof(data5)/sizeof(int), NULL, 0, true);	

    int data6[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected6[] = {1, 2};
	verify("Test6", data6, sizeof(data6)/sizeof(int), expected6, sizeof(expected6)/sizeof(int), false);	

}


