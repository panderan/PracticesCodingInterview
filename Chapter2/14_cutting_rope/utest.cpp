#include "utest.h"
#include "cut_rope.h"
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
    CPPUNIT_ASSERT_MESSAGE("Test1", max_product_cut_rope(1) == 0);
    CPPUNIT_ASSERT_MESSAGE("Test2", max_product_cut_rope(2) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", max_product_cut_rope(3) == 2);
    CPPUNIT_ASSERT_MESSAGE("Test4", max_product_cut_rope(4) == 4);
    CPPUNIT_ASSERT_MESSAGE("Test5", max_product_cut_rope(5) == 6);
    CPPUNIT_ASSERT_MESSAGE("Test6", max_product_cut_rope(6) == 9);
    CPPUNIT_ASSERT_MESSAGE("Test7", max_product_cut_rope(7) == 12);
    CPPUNIT_ASSERT_MESSAGE("Test8", max_product_cut_rope(8) == 18);
    CPPUNIT_ASSERT_MESSAGE("Test9", max_product_cut_rope(9) == 27);
    return;
}

void unit_test::second_test()
{
    CPPUNIT_ASSERT_MESSAGE("Test1", max_product_cut_rope2(1) == 0);
    CPPUNIT_ASSERT_MESSAGE("Test2", max_product_cut_rope2(2) == 1);
    CPPUNIT_ASSERT_MESSAGE("Test3", max_product_cut_rope2(3) == 2);
    CPPUNIT_ASSERT_MESSAGE("Test4", max_product_cut_rope2(4) == 4);
    CPPUNIT_ASSERT_MESSAGE("Test5", max_product_cut_rope2(5) == 6);
    CPPUNIT_ASSERT_MESSAGE("Test6", max_product_cut_rope2(6) == 9);
    CPPUNIT_ASSERT_MESSAGE("Test7", max_product_cut_rope2(7) == 12);
    CPPUNIT_ASSERT_MESSAGE("Test8", max_product_cut_rope2(8) == 18);
    CPPUNIT_ASSERT_MESSAGE("Test9", max_product_cut_rope2(9) == 27);
}
