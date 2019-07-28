#include "../../utest.h"
#include "numeric_string.h"
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
   	CPPUNIT_ASSERT_MESSAGE("Test1", is_numeric("100")==true);
    CPPUNIT_ASSERT_MESSAGE("Test2", is_numeric("123.45e+6")==true);
    CPPUNIT_ASSERT_MESSAGE("Test3", is_numeric("+500")==true);
    CPPUNIT_ASSERT_MESSAGE("Test4", is_numeric("5e2")==true);
    CPPUNIT_ASSERT_MESSAGE("Test5", is_numeric("3.1416")==true);
    CPPUNIT_ASSERT_MESSAGE("Test6", is_numeric("600.")==true);
    CPPUNIT_ASSERT_MESSAGE("Test7", is_numeric("-.123")==true);
    CPPUNIT_ASSERT_MESSAGE("Test8", is_numeric("-1E-16")==true);
    CPPUNIT_ASSERT_MESSAGE("Test9", is_numeric("1.79769313486232E+308")==true);
    CPPUNIT_ASSERT_MESSAGE("Test10", is_numeric("12e")==false);
    CPPUNIT_ASSERT_MESSAGE("Test11", is_numeric("1a3.14")==false);
    CPPUNIT_ASSERT_MESSAGE("Test12", is_numeric("1+23")==false);
    CPPUNIT_ASSERT_MESSAGE("Test13", is_numeric("1.2.3")==false);
    CPPUNIT_ASSERT_MESSAGE("Test14", is_numeric("+-5")==false);
    CPPUNIT_ASSERT_MESSAGE("Test15", is_numeric("12e+5.4")==false);
    CPPUNIT_ASSERT_MESSAGE("Test16", is_numeric(".")==false);
    CPPUNIT_ASSERT_MESSAGE("Test17", is_numeric(".e1")==false);
    CPPUNIT_ASSERT_MESSAGE("Test18", is_numeric("e1")==false);
    CPPUNIT_ASSERT_MESSAGE("Test19", is_numeric("+.")==false);
    CPPUNIT_ASSERT_MESSAGE("Test20", is_numeric("")==false);
    CPPUNIT_ASSERT_MESSAGE("Test21", is_numeric(nullptr)==false);
    return;
}



