#include "../../utest.h"
#include "more_than_half_number.h"
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

    int numbers1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    error_flag_mthn = false;
    ret = more_than_half_num_quick(numbers1,sizeof(numbers1)/sizeof(int)); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test1", ret == 2 && error_flag_mthn == false);

    int numbers2[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    error_flag_mthn = false;
    ret = more_than_half_num_quick(numbers2,sizeof(numbers2)/sizeof(int)); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test2", ret == 0 && error_flag_mthn == true);

    int numbers3[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    error_flag_mthn = false;
    ret = more_than_half_num_quick(numbers3,sizeof(numbers3)/sizeof(int)); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test3", ret == 2 && error_flag_mthn == false);

    int numbers4[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    error_flag_mthn = false;
    ret = more_than_half_num_quick(numbers4,sizeof(numbers4)/sizeof(int)); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test4", ret == 2 && error_flag_mthn == false);

    int numbers5[] = {1};
    error_flag_mthn = false;
    ret = more_than_half_num_quick(numbers5,sizeof(numbers5)/sizeof(int)); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test5", ret == 1 && error_flag_mthn == false);

    error_flag_mthn = false;
    ret = more_than_half_num_quick(NULL,0); 
    printf("%d\n", ret);
    CPPUNIT_ASSERT_MESSAGE("Test6", ret == 0 && error_flag_mthn == true);

    return;
}


