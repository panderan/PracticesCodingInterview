#include "utest.h"
#include "reorder_array.h" 
#include <cstring>
#include <cstdio>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

bool verify(int num[], unsigned int length)
{
    bool flag = false;
    if (num == NULL) {
        return true;
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", *(num+i));
        if (flag && (*(num+i)&0x1)==1) {
            return false;
        }
        if ((*(num+i)&0x1)==0) {
            flag = true;
        }
    }
    return true;
}

bool is_odd(int n)
{
    return (n&0x1)==1 ? true : false;
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
    int numbers1[] = {1, 2, 3, 4, 5, 6, 7};
    reorder_odd_event(numbers1, 7);
    CPPUNIT_ASSERT_MESSAGE("Test1", verify(numbers1, 7)==true); 

    int numbers2[] = {2, 4, 6, 1, 3, 5, 7};
    reorder_odd_event(numbers2, 7);
    CPPUNIT_ASSERT_MESSAGE("Test2", verify(numbers2, 7)==true); 

    int numbers3[] = {1, 3, 5, 7, 2, 4, 6};
    reorder_odd_event(numbers3, 7);
    CPPUNIT_ASSERT_MESSAGE("Test3", verify(numbers3, 7)==true); 

    int numbers4[] = {1};
    reorder_odd_event(numbers4, 1);
    CPPUNIT_ASSERT_MESSAGE("Test4", verify(numbers4, 1)==true); 

    int numbers5[] = {2};
    reorder_odd_event(numbers5, 1);
    CPPUNIT_ASSERT_MESSAGE("Test5", verify(numbers5, 1)==true); 

    reorder_odd_event(NULL, 0);
    return;
}

void unit_test::second_test()
{
    int numbers1[] = {1, 2, 3, 4, 5, 6, 7};
    reorder_odd_event_ex(numbers1, 7, is_odd);
    CPPUNIT_ASSERT_MESSAGE("Test6", verify(numbers1, 7)==true); 

    int numbers2[] = {2, 4, 6, 1, 3, 5, 7};
    reorder_odd_event_ex(numbers2, 7, is_odd);
    CPPUNIT_ASSERT_MESSAGE("Test7", verify(numbers2, 7)==true); 

    int numbers3[] = {1, 3, 5, 7, 2, 4, 6};
    reorder_odd_event_ex(numbers3, 7, is_odd);
    CPPUNIT_ASSERT_MESSAGE("Test8", verify(numbers3, 7)==true); 

    int numbers4[] = {1};
    reorder_odd_event_ex(numbers4, 1, is_odd);
    CPPUNIT_ASSERT_MESSAGE("Test9", verify(numbers4, 1)==true); 

    int numbers5[] = {2};
    reorder_odd_event_ex(numbers5, 2, is_odd);
    CPPUNIT_ASSERT_MESSAGE("Test10", verify(numbers5, 1)==true); 

    reorder_odd_event_ex(NULL, 0, NULL);
    return;
}

