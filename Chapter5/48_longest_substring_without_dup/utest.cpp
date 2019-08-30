#include "../../utest.h"
#include "longest_substring_without_dup.h"
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
    int retval = 0;
    
    retval = longest_substring_without_dup("abcacfrar");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 4);

    retval = longest_substring_without_dup("acfrarabc");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == 4);

    retval = longest_substring_without_dup("arabcacfr");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 4);

    retval = longest_substring_without_dup("aaaa");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == 1);

    retval = longest_substring_without_dup("abcdefg");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test5", retval == 7);

    retval = longest_substring_without_dup("aaabbbccc");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test6", retval == 2);

    retval = longest_substring_without_dup("abcdcba");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test7", retval == 4);

    retval = longest_substring_without_dup("abcdaef");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test8", retval == 6);

    retval = longest_substring_without_dup("a");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test9", retval == 1);

    retval = longest_substring_without_dup("");
    printf("%d\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test10", retval == 0);

    return;
}


