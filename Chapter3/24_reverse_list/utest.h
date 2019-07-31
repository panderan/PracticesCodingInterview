#ifndef _DEFAULT_DATAREADER_TEST_ 
#define _DEFAULT_DATAREADER_TEST_

#include <iostream>
#include <cppunit/extensions/HelperMacros.h>

class unit_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(unit_test);
    CPPUNIT_TEST(first_test);
    CPPUNIT_TEST(second_test);
    CPPUNIT_TEST(third_test);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

    public:
        void first_test();
        void second_test();
        void third_test();
};





#endif 
