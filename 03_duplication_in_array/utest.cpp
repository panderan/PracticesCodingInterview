#include "utest.h"
#include "duplication_in_array.h"
#include "duplication_no_edit.h"
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
    int numbers1[] = { 2, 1, 3, 1, 4 };
    int numbers2[] = { 2, 4, 3, 1, 4 };
    int numbers3[] = { 2, 4, 2, 1, 4 };
    int numbers4[] = { 2, 1, 3, 0, 4 };
    int retval = 0;
    bool retres = false;
    
    retres = duplication(numbers1, sizeof(numbers1)/sizeof(numbers1[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("1. minimum num" ,retres == true && retval == 1);

    retres = duplication(numbers2, sizeof(numbers2)/sizeof(numbers2[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("1. maximum num", retres == true && retval == 4);

    retres = duplication(numbers3, sizeof(numbers3)/sizeof(numbers3[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("1. multiple duplication num", retres == true && (retval == 4 || retval == 2));

    retres = duplication(numbers4, sizeof(numbers4)/sizeof(numbers4[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("1. no duplication num", retres == false);

    retres = duplication(NULL, 0, &retval);  
    CPPUNIT_ASSERT_MESSAGE("1. invalid input", retres == false);
}

void unit_test::second_test()
{
    int numbers1[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
    int numbers2[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int numbers3[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int numbers4[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int numbers5[] = { 1, 1};
    int numbers6[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int numbers7[] = { 1, 2, 2, 6, 4, 5, 6 };
    int numbers8[] = { 1, 2, 2, 6, 4, 5, 2 };
    int numbers9[] = { 1, 2, 6, 4, 5, 3 };
    int retval = 0;
    bool retres = false;
    
    retres = duplication2(numbers1, sizeof(numbers1)/sizeof(numbers1[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. multiple duplication num" ,retres == true && (retval == 2 || retval == 3));

    retres = duplication2(numbers2, sizeof(numbers2)/sizeof(numbers2[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. one dup num", retres == true && retval == 4);

    retres = duplication2(numbers3, sizeof(numbers3)/sizeof(numbers3[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. min dup num", retres == true && retval == 1);

    retres = duplication2(numbers4, sizeof(numbers4)/sizeof(numbers4[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. max dup mun", retres == true && retval == 8);

    retres = duplication2(numbers5, sizeof(numbers5)/sizeof(numbers5[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. two dup num", retres == true && retval == 1);

    retres = duplication2(numbers6, sizeof(numbers6)/sizeof(numbers6[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. mid dup num", retres == true && retval == 3);

    retres = duplication2(numbers7, sizeof(numbers7)/sizeof(numbers7[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. multiple dup num", retres == true && (retval == 2 || retval == 6));

    retres = duplication2(numbers8, sizeof(numbers8)/sizeof(numbers8[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. one num dup three times", retres == true && retval == 2);

    retres = duplication2(numbers9, sizeof(numbers9)/sizeof(numbers9[0]), &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. no duplication num", retres == false && retval == -1);

    retres = duplication2(NULL, 0, &retval);  
    CPPUNIT_ASSERT_MESSAGE("2. invalid input", retres == false);
}

