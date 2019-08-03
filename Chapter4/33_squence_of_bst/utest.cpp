#include "../../utest.h"
#include "squence_of_bst.h"
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
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
    int data1[] = {4, 8, 6, 12, 16, 14, 10};
	CPPUNIT_ASSERT_MESSAGE("Test1", verify_squence_of_bst(data1, sizeof(data1)/sizeof(int)) == true);

//           5
//          / \
//         4   7
//            /
//           6
	int data2[] = {4, 6, 7, 5};
	CPPUNIT_ASSERT_MESSAGE("Test2", verify_squence_of_bst(data2, sizeof(data2)/sizeof(int)) == true);

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
	int data3[] = {1, 2, 3, 4, 5};
	CPPUNIT_ASSERT_MESSAGE("Test3", verify_squence_of_bst(data3, sizeof(data3)/sizeof(int)) == true);

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
    int data4[] = {5, 4, 3, 2, 1};
	CPPUNIT_ASSERT_MESSAGE("Test4", verify_squence_of_bst(data4, sizeof(data4)/sizeof(int)) == true);

    int data5[] = {5};
	CPPUNIT_ASSERT_MESSAGE("Test5", verify_squence_of_bst(data5, sizeof(data5)/sizeof(int)) == true);

    int data6[] = {7, 4, 6, 5};
	CPPUNIT_ASSERT_MESSAGE("Test6", verify_squence_of_bst(data6, sizeof(data6)/sizeof(int)) == false);

    int data7[] = {4, 6, 12, 8, 16, 14, 10};
	CPPUNIT_ASSERT_MESSAGE("Test7", verify_squence_of_bst(data7, sizeof(data7)/sizeof(int)) == false);

	CPPUNIT_ASSERT_MESSAGE("Test8", verify_squence_of_bst(NULL, 0) == false);






    return;
}


