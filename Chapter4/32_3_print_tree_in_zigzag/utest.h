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
    CPPUNIT_TEST(fourth_test);
    CPPUNIT_TEST(fifth_test);
    CPPUNIT_TEST(sixth_test);
    CPPUNIT_TEST(seventh_test);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

    public:
        void first_test();
        void second_test();
        void third_test();
        void fourth_test();
        void fifth_test();
        void sixth_test();
        void seventh_test();
};





#endif 
