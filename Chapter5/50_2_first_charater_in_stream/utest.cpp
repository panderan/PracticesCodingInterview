#include "../../utest.h"
#include "first_charater_in_stream.h"
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
    char_statistics chars;
    
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == '\0'); 

    chars.insert('g');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == 'g'); 

    chars.insert('o');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == 'g'); 

    chars.insert('o');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == 'g'); 

    chars.insert('g');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == '\0'); 

    chars.insert('l');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == 'l'); 

    chars.insert('e');
    CPPUNIT_ASSERT_MESSAGE("Test1", chars.first_appearing_once() == 'l'); 

    return;
}


