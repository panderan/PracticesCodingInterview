#include "utest.h"
#include "power.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test1", power(2,3)-8<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test2", power(-2,3)-(-8)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test3", power(2,-3)-(0.125)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test4", power(2,0)-(1)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test5", power(0,0)-(1)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test6", power(0,4)-(0)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test7", power(0,-4)-(0)<0.00000001==true && g_power_error==true);
    return;
}

void unit_test::second_test()
{
    CPPUNIT_ASSERT_MESSAGE("Test1", power_fast(2,3)-8<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test2", power_fast(-2,3)-(-8)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test3", power_fast(2,-3)-(0.125)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test4", power_fast(2,0)-(1)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test5", power_fast(0,0)-(1)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test6", power_fast(0,4)-(0)<0.00000001==true && g_power_error==false);
    CPPUNIT_ASSERT_MESSAGE("Test7", power_fast(0,-4)-(0)<0.00000001==true && g_power_error==true);
    return;
}

