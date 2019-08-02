#include "../../utest.h"
#include "print_matrix.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void get_numbsers(int ***_numbers, int rows, int columns)
{
    int **numbers = NULL;

    *_numbers = new int*[rows];
    numbers = *_numbers;
    for(int i = 0; i < rows; ++i) {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j) {
            numbers[i][j] = i * columns + j + 1;
        }
    }
}

void free_numbers(int ***_numbers, int rows, int columns)
{
    int **numbers = *_numbers;

    for(int i = 0; i < rows; ++i) {
        delete numbers[i];
    }
    delete numbers;
    _numbers = NULL;
}

void verify(const char *message, int cols, int rows, int truth[]) 
{
    int **numbers = NULL;
    int out_arr[10240] = {0};

    get_numbsers(&numbers,rows,cols);
    print_matrix_in_circle(numbers, out_arr, cols, rows);
    
    printf("\n%s:\n", message);
    for (int i=0; i < rows*cols; i++) {
        printf("(%d-%d) ", truth[i], out_arr[i]);
        CPPUNIT_ASSERT_MESSAGE(message, truth[i] == out_arr[i]);
    }
    free_numbers(&numbers, rows, cols);
    return;
}

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
    int truth1[] = {1};
    verify("Test1", 1, 1, truth1);
    
    int truth2[] = {1,2,4,3};  
    verify("Test2", 2, 2, truth2);
    
    int truth3[] = {1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10};  
    verify("Test3", 4, 4, truth3);
    
    int truth4[] = {1,2,3,4,5,10,15,20,25,24,23,22,21,16,11,6,7,8,9,14,19,18,17,12,13};  
    verify("Test4", 5, 5, truth4);
    
    int truth5[] = {1,2,3,4,5};  
    verify("Test5", 1, 5, truth5);
    
    int truth6[] = {1,2,4,6,8,10,9,7,5,3};  
    verify("Test6", 2, 5, truth6);
    
    int truth7[] = {1,2,3,6,9,12,15,14,13,10,7,4,5,8,11};  
    verify("Test7", 3, 5, truth7);
    
    int truth8[] = {1,2,3,4,8,12,16,20,19,18,17,13,9,5,6,7,11,15,14,10};  
    verify("Test8", 4, 5, truth8);

    verify("Test9", 5, 1, truth5);

    int truth10[] = {1,2,3,4,5,10,9,8,7,6};  
    verify("Test10", 5, 2, truth10);
    
    int truth11[] = {1,2,3,4,5,10,15,14,13,12,11,6,7,8,9};  
    verify("Test11", 5, 3, truth11);
    
    int truth12[] = {1,2,3,4,5,10,15,20,19,18,17,16,11,6,7,8,9,14,13,12};  
    verify("Test12", 5, 4, truth12);

}


