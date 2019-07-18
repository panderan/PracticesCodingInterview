#include "../../utest.h"
#include "string_path_in_matrix.h"
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
    const char* matrix1 = "ABTGCFCSJDEH";
    const char* str1 = "BFCE";
    CPPUNIT_ASSERT_MESSAGE("Test1", has_path(matrix1, 3, 4, str1) == true);

    const char* matrix2 = "ABCESFCSADEE";
    const char* str2 = "SEE";
    CPPUNIT_ASSERT_MESSAGE("Test2", has_path(matrix2, 3, 4, str2) == true);

    const char* matrix3 = "ABTGCFCSJDEH";
    const char* str3 = "ABFB";
    CPPUNIT_ASSERT_MESSAGE("Test3", has_path(matrix3, 3, 4, str3) == false);

    const char* matrix4 = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str4 = "SLHECCEIDEJFGGFIE";
    CPPUNIT_ASSERT_MESSAGE("Test4", has_path(matrix4, 5, 8, str4) == true);

    const char* matrix5 = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str5 = "SGGFIECVAASABCEHJIGQEM";
    CPPUNIT_ASSERT_MESSAGE("Test5", has_path(matrix5, 5, 8, str5) == true);

    const char* matrix6 = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str6 = "SGGFIECVAASABCEEJIGOEM";
    CPPUNIT_ASSERT_MESSAGE("Test6", has_path(matrix6, 5, 8, str6) == false);

    const char* matrix7 = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str7 = "SGGFIECVAASABCEHJIGQEMS";
    CPPUNIT_ASSERT_MESSAGE("Test7", has_path(matrix7, 5, 8, str7) == false);

    const char* matrix8 = "AAAAAAAAAAAA";
    const char* str8 = "AAAAAAAAAAAA";
    CPPUNIT_ASSERT_MESSAGE("Test8", has_path(matrix8, 3, 4, str8) == true);

    const char* matrix9 = "AAAAAAAAAAAA";
    const char* str9 = "AAAAAAAAAAAAA";
    CPPUNIT_ASSERT_MESSAGE("Test9", has_path(matrix9, 3, 4, str9) == false);

    const char* matrix10 = "A";
    const char* str10 = "A";
    CPPUNIT_ASSERT_MESSAGE("Test10", has_path(matrix10, 1, 1, str10) == true);

    const char* matrix11 = "A";
    const char* str11 = "B";
    CPPUNIT_ASSERT_MESSAGE("Test11", has_path(matrix11, 1, 1, str11) == false);

    CPPUNIT_ASSERT_MESSAGE("Test12", has_path(NULL, 0, 0, NULL) == false);
}


