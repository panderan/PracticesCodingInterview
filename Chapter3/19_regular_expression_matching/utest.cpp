#include "../../utest.h"
#include "regular_expression_matching.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test01", match("", "")==true);
    CPPUNIT_ASSERT_MESSAGE("Test02", match("", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test03", match("", ".")==false);
    CPPUNIT_ASSERT_MESSAGE("Test04", match("", "c*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test05", match("a", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test06", match("a", "a.")==false);
    CPPUNIT_ASSERT_MESSAGE("Test07", match("a", "")==false);
    CPPUNIT_ASSERT_MESSAGE("Test08", match("a", ".")==true);
    CPPUNIT_ASSERT_MESSAGE("Test09", match("a", "ab*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test10", match("a", "ab*a")==false);
    CPPUNIT_ASSERT_MESSAGE("Test11", match("aa", "aa")==true);
    CPPUNIT_ASSERT_MESSAGE("Test12", match("aa", "a*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test13", match("aa", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test14", match("aa", ".")==false);
    CPPUNIT_ASSERT_MESSAGE("Test15", match("ab", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test16", match("ab", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test17", match("aaa", "aa*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test18", match("aaa", "aa.a")==false);
    CPPUNIT_ASSERT_MESSAGE("Test19", match("aaa", "a.a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test20", match("aaa", ".a")==false);
    CPPUNIT_ASSERT_MESSAGE("Test21", match("aaa", "a*a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test22", match("aaa", "ab*a")==false);
    CPPUNIT_ASSERT_MESSAGE("Test23", match("aaa", "ab*ac*a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test24", match("aaa", "ab*a*c*a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test25", match("aaa", ".*")==true);
    CPPUNIT_ASSERT_MESSAGE("Test26", match("aab", "c*a*b")==true);
    CPPUNIT_ASSERT_MESSAGE("Test27", match("aaca", "ab*a*c*a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test28", match("aaba", "ab*a*c*a")==false);
    CPPUNIT_ASSERT_MESSAGE("Test29", match("bbbba", ".*a*a")==true);
    CPPUNIT_ASSERT_MESSAGE("Test30", match("bcbbabab", ".*a*a")==false);
    return;
}

