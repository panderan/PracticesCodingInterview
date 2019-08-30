#include "../../utest.h"
#include "sort_array_for_min_number.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void verify(const char * message, int numbers[], int length, const char *answer)
{
    char output[10240];
    int retlen = 0, i = 0;

    retlen = print_min_number(numbers, length, output, 10240);
    printf("%s\n", output);

    CPPUNIT_ASSERT_MESSAGE(message, retlen == strlen(answer));
    CPPUNIT_ASSERT_MESSAGE(message, strcmp(output, answer) == 0);

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
    int numbers1[] = {3, 5, 1, 4, 2};
    verify("Test1", numbers1, sizeof(numbers1)/sizeof(int), "12345");

    int numbers2[] = {3, 32, 321};
    verify("Test2", numbers2, sizeof(numbers2)/sizeof(int), "321323");

    int numbers3[] = {3, 323, 32123};
    verify("Test3", numbers3, sizeof(numbers3)/sizeof(int), "321233233");

    int numbers4[] = {1, 11, 111};
    verify("Test4", numbers4, sizeof(numbers4)/sizeof(int), "111111");

    int numbers5[] = {321};
    verify("Test5", numbers5, sizeof(numbers5)/sizeof(int), "321");

}


