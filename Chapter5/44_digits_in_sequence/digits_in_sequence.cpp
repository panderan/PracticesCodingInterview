#include "digits_in_sequence.h"
#include <math.h>

int digit_at_index(int index)
{
    int lev = 0, cnt = 0, high = 0, low = 0;
    int retval = 0, i = 0;
    
    if (index < 0) {
        return -1;
    }

    if (index == 0) {
        return index;
    }

    for (cnt=0,lev=1; cnt<index; lev++) {
        low = pow(10, lev-1);
        high = pow(10, lev)-1;
        cnt += (high-low+1)*lev;
    }
    lev--;

    index = cnt-index;
    high -= index/lev;
    index = index%lev;

    for (int i = 0; i < index; i++) {
        high = high/10;
    }
    return high%10;
}

