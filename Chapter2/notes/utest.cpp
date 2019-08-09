#include "utest.h"
#include "binary_search.h"
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,15};
    int target = 5;
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 0)==-1);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 1)==0);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 2)==1);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 3)==2);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 4)==3);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 5)==4);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 6)==5);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 7)==6);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 8)==7);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 9)==8);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 10)==9);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 11)==10);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 12)==11);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 13)==-1);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 15)==12);
    CPPUNIT_ASSERT_MESSAGE("Test1", binary_search(arr, 13, 14)==-1);
}


