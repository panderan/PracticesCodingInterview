#include "../../utest.h"
#include "first_not_repeating_char.h"
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
    char retval;

    retval = first_not_repeating_char("google");    
    printf("%c\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test1", retval == 'l');

    retval = first_not_repeating_char("aabccdbd");    
    printf("%c\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test2", retval == '\0');

    retval = first_not_repeating_char("abcdefg");    
    printf("%c\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test3", retval == 'a');

    retval = first_not_repeating_char(NULL);    
    printf("%c\n", retval);
    CPPUNIT_ASSERT_MESSAGE("Test4", retval == '\0');

    return;
}


