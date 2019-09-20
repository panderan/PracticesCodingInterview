#include "numbers_appear_once.h"
#include <unistd.h>
#include <cstdlib>

int find_num_appear_once(int data[], int length, int *retval)
{
    int i = 0;
    int &ret = *retval; 

    ret = 0;
    for (i=0; i<length; i++) {
        ret = ret ^ data[i];
    }

    return 0;
}

int find_nums_appear_once(int data[], int length, int retvals[], int r_len)
{
    if (data == NULL || length < 1 || retvals == NULL || r_len < 1) {
        return -1;
    }
    
    int ret = 0, i = 0, j = 0;
    int *data1 = NULL, *data2 = NULL, d1_idx = 0, d2_idx = 0;

    for (i=0; i<length; i++) {
        ret = ret^data[i];
    }
    
    for (i=0; i<32; i++) {
        if ((0x1<<i) & ret) {
            j = i;
            break;
        }
    }

    data1 = (int*) calloc(length, sizeof(int));
    data2 = (int*) calloc(length, sizeof(int));
    
    for (i=0; i<length; i++) {
        if ((0x1<<j) & data[i]) {
            data1[d1_idx++] = data[i];
        }
        else {
            data2[d2_idx++] = data[i];
        }
    }
    
    find_num_appear_once(data1, d1_idx, &retvals[0]);
    find_num_appear_once(data2, d2_idx, &retvals[1]);

    return 0;
}

