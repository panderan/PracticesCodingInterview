#include "../../utest.h"
#include "print_1_to_max_of_n_digits.h"
#include <cstring>
#include <cstdio>

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
    printf("\n");
    print_1_to_max_of_n_digits(1);
    printf("\n");
    print_1_to_max_of_n_digits(2);
    printf("\n");
    print_1_to_max_of_n_digits(3);
    printf("\n");
    print_1_to_max_of_n_digits(0);
    printf("\n");
    print_1_to_max_of_n_digits(-1);
    return;
}

