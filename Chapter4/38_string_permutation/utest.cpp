#include "../../utest.h"
#include "string_permutation.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test1", permutation("a")==1);
    CPPUNIT_ASSERT_MESSAGE("Test2", permutation("ab")==2);
    CPPUNIT_ASSERT_MESSAGE("Test3", permutation("abc")==6);
    CPPUNIT_ASSERT_MESSAGE("Test4", permutation(NULL)==0);
    CPPUNIT_ASSERT_MESSAGE("Test5", permutation("")==1);
    return;
}


