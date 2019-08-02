#include "print_matrix.h"
#include <cstdio>

void _print_matrix_in_circle(int **numbers, int columns, int rows, int start, int out_arr[], int &out_idx)
{   
    for (int i = start-1; i <= columns-start; i++) {
        out_arr[out_idx++] = numbers[start-1][i];
    }

    for (int i = (start-1)+1; i <= rows-start; i++) {
        out_arr[out_idx++] = numbers[i][columns-start];
    }

    for (int i = columns-start-1; i >= start-1; i--) {
        out_arr[out_idx++] = numbers[rows-start][i];
    }

    for (int i = rows-start-1; i > start-1; i--) {
        out_arr[out_idx++] = numbers[i][start-1];
    }
}

void print_matrix_in_circle(int **numbers, int out_arr[], int columns, int rows)
{
    int out_idx = 0;
    if (numbers == NULL || columns < 1 || rows < 1) {
        return ;
    }

    for (int i = 1; i <= (columns+1)/2 && i <= (rows+1)/2; i++) {
        _print_matrix_in_circle(numbers, columns, rows, i, out_arr, out_idx);
    }
    return;
}
