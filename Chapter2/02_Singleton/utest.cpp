#include "../../utest.h"
#include "singleton1.h"
#include <cstring>
#include <unistd.h>

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
    singleton1 *s1 = NULL, *s2 = NULL;

    s1 = singleton1::get_instance();
    usleep(100);
    s2 = singleton1::get_instance();

    CPPUNIT_ASSERT(s1->get_data() == s2->get_data());
}


