#include "inverse_pairs.h"
#include <cstdlib>
#include <unistd.h>

int inverse_pairs_core(int data[], int length)
{
    int middle = 0, cnt = 0, i = 0, j = 0;
    int *buff = NULL, buf_idx = 0;
    
    if (data == NULL || length < 2) {
        return 0;
    }

    middle = length >> 1;
    cnt += inverse_pairs_core(data, middle);
    cnt += inverse_pairs_core(data+middle, length-middle);

    buff = (int *) alloca(length*sizeof(int));
    for (i=middle-1, j=length-1, buf_idx=length-1; i>=0 && j>=middle; buf_idx--) {
        if (data[i] > data[j]) {
            cnt+=j-middle+1;
            *(buff+buf_idx) = data[i];
            i--;
        }
        else {
            *(buff+buf_idx) = data[j];
            j--;
        }
    }

    for (;i>=0; *(buff+buf_idx--) = data[i--]);
    for (;j>=middle; *(buff+buf_idx--) = data[j--]);
    for (buf_idx=0; buf_idx<length; data[buf_idx]=buff[buf_idx], buf_idx++);

    return cnt;
}

int inverse_pairs(int data[], int length)
{
    return inverse_pairs_core(data, length);
}
