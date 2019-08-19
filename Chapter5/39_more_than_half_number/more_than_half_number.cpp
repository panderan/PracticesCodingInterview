#include "more_than_half_number.h"
#include <unistd.h>

bool error_flag_mthn = false;

bool check(int number[], int length, int target)
{
    int middle = 0, cnt = 0, i = 0;

    if (number == NULL || length < 1) {
        return false;
    }

    for (cnt=0,i=0; i<length; i++) {
        cnt += *(number+i) == target ? 1 : 0;
    }

    middle = length >> 1;
    return cnt > middle ? true : false;
}

int partition(int number[], int length)
{
    int choose = 0;
    int s_idx = 0, e_idx = 0;

    if (number == NULL || length < 1) {
        error_flag_mthn = true;
        return 0;
    }

    choose = *number;
    s_idx = 0;
    e_idx = length - 1;

    while (s_idx < e_idx) {
        for (;s_idx<e_idx && *(number+e_idx)>=choose; e_idx--);
        *(number+s_idx) = *(number+e_idx);
        for (;s_idx<e_idx && *(number+s_idx)<choose; s_idx++);
        *(number+e_idx) = *(number+s_idx);
    }
    *(number+s_idx) = choose;

    return s_idx;
}

int more_than_half_num(int *number, int length)
{
    int middle = 0, index = 0;
    int start = 0, end = 0;
    
    error_flag_mthn = false;
    if (number == NULL || length < 1) {
        error_flag_mthn = true;
        return 0;
    }
    
    middle = length >> 1;
    index = -1;
    start = 0;
    end = length;

    while (start+index != middle) {
        end = start+index>middle ? start+index : end;
        start = start+index<middle ? start+index+1: start;
        index = partition(number+start, end-start);
    }
    
    if (check(number, length, *(number+middle))) {
        return *(number+middle);
    }
    else {
        error_flag_mthn = true;
        return 0;
    }
}

int more_than_half_num_quick(int *number, int length)
{
    int target = 0, cnt = 0, i = 0;

    error_flag_mthn = false;
    if (number == NULL || length < 1) {
        error_flag_mthn = true;
        return 0;
    }
    
    for (cnt = 0, i = 0; i < length; i++) {
        if (cnt) {
            if (target == *(number+i)) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        else {
            target = *(number+i);
            cnt = 1;
        }
    }

    if (check(number, length, target)) {
        return target;
    }
    else {
        error_flag_mthn = true;
        return 0;
    }
}
