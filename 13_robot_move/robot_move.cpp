#include "robot_move.h"
#include <cstdlib>
#include <unistd.h>
#include <queue>

static int moving_count_core(int threshold, int rows, int cols, int c_row, int c_col, int *bitmap);
int moving_count(int threshold, int rows, int cols)
{
    int *bitmap = NULL;
    bitmap = (int *)calloc(sizeof(int), rows*cols);
    return moving_count_core(threshold, rows, cols, 0, 0, bitmap);    
} 

static int moving_count_core(int threshold, int rows, int cols, int c_row, int c_col, int *bitmap)
{
    int idxs[2] = {c_row, c_col};
    int sum = 0;
    
    if (c_row < 0 || c_row >= rows || c_col < 0 || c_col >= cols) {
        return 0;
    }

    if (*(bitmap+c_row*cols+c_col) == 1) {
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        int tmp = idxs[i];
        while (tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
    }

    if (sum > threshold) {
        return 0;
    }

    *(bitmap+c_row*cols+c_col) = 1;

    return 1 + moving_count_core(threshold, rows, cols, c_row+1, c_col, bitmap) \
             + moving_count_core(threshold, rows, cols, c_row, c_col+1, bitmap) \
             + moving_count_core(threshold, rows, cols, c_row-1, c_col, bitmap) \
             + moving_count_core(threshold, rows, cols, c_row, c_col-1, bitmap);
}

int moving_count2(int threshold, int rows, int cols)
{
    int *bitmap = NULL;
    typedef struct point {
        int col;
        int row;
    } point_t;
    point_t p = {0, 0};
    std::queue<point_t> q;
    int count = 0;

    bitmap = (int *)calloc(sizeof(int), rows*cols);
    q.push(p);

    while (q.empty() == false) {
        point_t tmp_p = q.front();
        q.pop();

        if (tmp_p.row < 0 || tmp_p.row >= rows || tmp_p.col < 0 || tmp_p.col >= cols) {
            continue;
        }

        if (*(bitmap+tmp_p.row*cols+tmp_p.col) == 1) {
            continue;
        }
        *(bitmap+tmp_p.row*cols+tmp_p.col) = 1;

        int sum = 0; 
        int idxs[2] = {tmp_p.row, tmp_p.col};
        for (int i = 0; i < 2; i++) {
            int tmp = idxs[i];
            while (tmp != 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
        }

        if (sum > threshold) {
            continue;
        }

        count++;
        point_t q1 = {tmp_p.col+1, tmp_p.row};
        point_t q2 = {tmp_p.col, tmp_p.row+1}; 
        point_t q3 = {tmp_p.col-1, tmp_p.row}; 
        point_t q4 = {tmp_p.col, tmp_p.row-1};
        q.push(q1);
        q.push(q2);
        q.push(q3);
        q.push(q4);
    }

    return count;
}

