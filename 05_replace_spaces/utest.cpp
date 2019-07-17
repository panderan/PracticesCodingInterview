#include "../utest.h"
#include "replace_spaces.h"
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
    const int length = 100;
    char str1[length] = "hello world";
    char str2[length] = " helloworld";
    char str3[length] = "helloworld ";
    char str4[length] = "hello  world";
    char str6[length] = "";
    char str7[length] = " ";
    char str8[length] = "helloworld";
    char str9[length] = "   ";

    replace_blank(str1, length);
    CPPUNIT_ASSERT_MESSAGE("TEST1", strcmp(str1, "hello\%20world") == 0);

    replace_blank(str2, length);
    CPPUNIT_ASSERT_MESSAGE("TEST2", strcmp(str2, "\%20helloworld") == 0);

    replace_blank(str3, length);
    CPPUNIT_ASSERT_MESSAGE("TEST3", strcmp(str3, "helloworld\%20") == 0);

    replace_blank(str4, length);
    CPPUNIT_ASSERT_MESSAGE("TEST4", strcmp(str4, "hello\%20\%20world") == 0);

    replace_blank(NULL, 0);

    replace_blank(str6, length);
    CPPUNIT_ASSERT_MESSAGE("TEST6", strcmp(str6, "") == 0);

    replace_blank(str7, length);
    CPPUNIT_ASSERT_MESSAGE("TEST7", strcmp(str7, "\%20") == 0);

    replace_blank(str8, length);
    CPPUNIT_ASSERT_MESSAGE("TEST8", strcmp(str8, "helloworld") == 0);

    replace_blank(str9, length);
    CPPUNIT_ASSERT_MESSAGE("TEST9", strcmp(str9, "\%20\%20\%20") == 0);

}


