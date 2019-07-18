#include "../../utest.h"
#include "queue_with_two_stacks.h"
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
    queue<char> q;
    char a;
     
    q.append_tail('a');
    q.append_tail('b');
    q.append_tail('c');

    a = q.delete_head();
    CPPUNIT_ASSERT_MESSAGE("Test1", a == 'a');
    a = q.delete_head();
    CPPUNIT_ASSERT_MESSAGE("Test1", a == 'b');
    q.append_tail('d');
    a = q.delete_head();
    CPPUNIT_ASSERT_MESSAGE("Test1", a == 'c');
    q.append_tail('e');
    a = q.delete_head();
    CPPUNIT_ASSERT_MESSAGE("Test1", a == 'd');
    a = q.delete_head();
    CPPUNIT_ASSERT_MESSAGE("Test1", a == 'e');
    return;
}


