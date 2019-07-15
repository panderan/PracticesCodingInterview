#include "utest.h"
#include "assignment_operator.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void unit_test::setUp()
{
    const char * text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;

    str2 = str1;
    CPPUNIT_ASSERT(strcmp(str1.getData(), str2.getData()) == 0);

    str1 = str1;
    CPPUNIT_ASSERT(strcmp(text, str2.getData()) == 0);

    str3 = str2 = str1;
    CPPUNIT_ASSERT(strcmp(text, str2.getData()) == 0);
    CPPUNIT_ASSERT(strcmp(text, str3.getData()) == 0);
    return;
}

void unit_test::tearDown()
{
    return;
}

void unit_test::first_test()
{
    return;
}


