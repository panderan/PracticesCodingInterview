#include "max_value_of_gifts.h"
#include <unistd.h>
#include <cstdlib>

int get_max_value(const int *values, int rows, int cols)
{
    int **max_values = NULL, i = 0, r = 0, c = 0;
    int max = 0, top = 0, left = 0, cur = 0;

    if (values == 0 || rows < 1 || cols < 1) {
        return 0;
    }

    max_values = (int **) calloc(rows, sizeof(int *));
    for (i=0; i<rows; i++) {
        *(max_values+i) = (int *) calloc(cols, sizeof(int));
    }

    for (r=0; r<rows; r++) {
        for (c=0; c<cols; c++) {
            cur = *(values+r*cols+c);
            top = r>0 ? *(*(max_values+r-1)+c) : 0;
            left = c>0 ? *(*(max_values+r)+c-1) : 0;
            max = top>left ? top : left;
            if (max > 0) {
                cur += max;
            }
            *(*(max_values+r)+c) = cur;
        }
    }

    max = *(*(max_values+rows-1)+cols-1);
    for (i=0; i<rows; i++) {
        free(*(max_values+i));
    }
    free(max_values);

    return max;
}

int get_max_value_quick(const int *values, int rows, int cols)
{
    int *max_values = NULL, i = 0, r = 0, c = 0;
    int max = 0, top = 0, left = 0, cur = 0;

    if (values == 0 || rows < 1 || cols < 1) {
        return 0;
    }

    max_values = (int *) calloc(cols, sizeof(int));

    for (r=0; r<rows; r++) {
        for (c=0; c<cols; c++) {
            cur = *(values+r*cols+c);
            top = max_values[c];
            left = c>0 ? max_values[c-1] : 0;
            max = top>left ? top : left;
            if (max > 0) {
                cur += max;
            }
            max_values[c] = cur;
        }
    }
    
    max = max_values[cols-1];
    free(max_values);

    return max;
}

