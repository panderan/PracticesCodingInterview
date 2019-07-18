#include "../../utest.h"
#include "min_number_in_rotated_array.h"
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
    int array1[] = { 3, 4, 5, 1, 2 };
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    int array4[] = { 1, 0, 1, 1, 1 };
    int array5[] = { 1, 2, 3, 4, 5 };
    int array6[] = { 2 };

	CPPUNIT_ASSERT_MESSAGE("Test1", min(array1, sizeof(array1) / sizeof(int)) == 1);
	CPPUNIT_ASSERT_MESSAGE("Test2", min(array2, sizeof(array2) / sizeof(int)) == 1);
	CPPUNIT_ASSERT_MESSAGE("Test3", min(array3, sizeof(array3) / sizeof(int)) == 1);
	CPPUNIT_ASSERT_MESSAGE("Test4", min(array4, sizeof(array4) / sizeof(int)) == 0);
	CPPUNIT_ASSERT_MESSAGE("Test5", min(array5, sizeof(array5) / sizeof(int)) == 1);
	CPPUNIT_ASSERT_MESSAGE("Test6", min(array6, sizeof(array6) / sizeof(int)) == 2);
	CPPUNIT_ASSERT_MESSAGE("Test7", min(NULL, 0) == 0);
 
}


