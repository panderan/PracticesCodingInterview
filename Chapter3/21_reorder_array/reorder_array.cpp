#include "reorder_array.h"
#include <unistd.h>

void reorder_odd_event(int data[], unsigned int length)
{
    int start_idx = 0, end_idx = 0;

    if (data == NULL) {
        return ;
    }

    end_idx = length - 1;
    while (true) {
        for (; start_idx<length && (*(data+start_idx)&0x1)==1; start_idx++);
        for (; end_idx >=0 && (*(data+end_idx)&0x1)==0; end_idx--);
        if (end_idx < start_idx) {
            break;
        }
        *(data+start_idx) = *(data+start_idx) ^ *(data+end_idx);
        *(data+end_idx) = *(data+start_idx) ^ *(data+end_idx);
        *(data+start_idx) = *(data+start_idx) ^ *(data+end_idx);
    }
    return ;
}

void reorder_odd_event_ex(int data[], unsigned int length, bool (*func)(int))
{
    int start_idx = 0, end_idx = 0;

    if (data == NULL || func == NULL) {
        return ;
    }

    end_idx = length - 1;
    while (true) {
        for (; start_idx<length && (*func)(*(data+start_idx)) == false; start_idx++);
        for (; end_idx >=0 && (*func)(*(data+end_idx)) == true; end_idx--);
        if (end_idx < start_idx) {
            break;
        }
        *(data+start_idx) = *(data+start_idx) ^ *(data+end_idx);
        *(data+end_idx) = *(data+start_idx) ^ *(data+end_idx);
        *(data+start_idx) = *(data+start_idx) ^ *(data+end_idx);
    }
    return ;
}
