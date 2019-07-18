#include "../../utest.h"
#include "find_in_partially_sorted_matrix.h"
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
    int matrix1[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int matrix2[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int matrix3[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int matrix4[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int matrix5[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int matrix6[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool retval = false;

    retval = find((int *)matrix1, 4, 4, 7);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == true);

    retval = find((int *)matrix2, 4, 4, 5);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == false);

    retval = find((int *)matrix3, 4, 4, 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == true);

    retval = find((int *)matrix4, 4, 4, 15);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == true);

    retval = find((int *)matrix5, 4, 4, 0);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == false);

    retval = find((int *)matrix6, 4, 4, 16);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == false);

    retval = find(NULL, 0, 0, 16);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == false);
    return;
}


