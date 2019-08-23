#include "greatest_sum_of_subarray.h"
#include <unistd.h>
#include <stdint.h>

bool g_error = false;

int find_greatest_sum_of_subarray(int data[], int length)
{
    int start = 0, max = 0, max_start = 0, cur_sum = 0, contin = 0;
    int i = 0;

    g_error = false;
    if (data == NULL || length < 1) {
        g_error = true;
        return 0;
    }
    
    for (i=1, start=0, max=data[0], max_start=0, contin=1, cur_sum=data[0]; i<length; i++) {
        if (cur_sum > 0) {
            cur_sum += data[i];
        }
        else {
            start = i;
            cur_sum = data[i];
        }

        if (cur_sum > max) {
            max = cur_sum;
            max_start=start;
            contin=i-max_start+1;
        }
    }
    
    return max;
}
