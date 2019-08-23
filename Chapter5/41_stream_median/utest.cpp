#include "../../utest.h"
#include "stream_median.h"
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
    array_with_median<double> numbers;

   	numbers.insert(5);
    CPPUNIT_ASSERT_MESSAGE("Test1", numbers.get_median() - 5 < 0.0000001);
    numbers.insert(2);
    CPPUNIT_ASSERT_MESSAGE("Test2", numbers.get_median() - 3.5 < 0.0000001);
    numbers.insert(3);
    CPPUNIT_ASSERT_MESSAGE("Test3", numbers.get_median() - 3 < 0.0000001);
    numbers.insert(4);
    CPPUNIT_ASSERT_MESSAGE("Test4", numbers.get_median() - 3.5 < 0.0000001);
    numbers.insert(1);
    CPPUNIT_ASSERT_MESSAGE("Test5", numbers.get_median() - 3 < 0.0000001);
    numbers.insert(6);
    CPPUNIT_ASSERT_MESSAGE("Test6", numbers.get_median() - 3.5 < 0.0000001);
    numbers.insert(7);
    CPPUNIT_ASSERT_MESSAGE("Test7", numbers.get_median() - 4 < 0.0000001);
    numbers.insert(0);
    CPPUNIT_ASSERT_MESSAGE("Test8", numbers.get_median() - 3.5 < 0.0000001);
    numbers.insert(8);
    CPPUNIT_ASSERT_MESSAGE("Test9", numbers.get_median() - 4 < 0.0000001);
 
    return;
}


