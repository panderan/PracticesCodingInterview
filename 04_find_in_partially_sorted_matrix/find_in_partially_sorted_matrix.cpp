#include "find_in_partially_sorted_matrix.h"
#include <unistd.h>

bool find(int* matrix, int rows, int columns, int number)
{
    int c_row = 0, c_col = 0;

    if (matrix == NULL || rows < 1 || columns < 1) {
        return false;
    }

    c_row = 0;
    c_col = columns-1;

    while(c_row < rows || c_col >= 0) {
        if (number == matrix[c_row*columns+c_col]) {
            return true;
        }

        if (number < matrix[c_row*columns+c_col]) {
            c_col -= 1;
        }
        else {
            c_row += 1;
        }
    }

    return false;
}
