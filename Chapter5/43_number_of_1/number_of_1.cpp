#include "number_of_1.h"
#include <math.h>

int number_of_1(unsigned int n)
{
    int lev = 0, low = 0, high = 0, quo = 0, retval = 0;

    if (n < 10) {
        return n > 0 ? 1 : 0;
    }

    for (lev=0; n/(int)(pow(10,lev))>9; lev++);
    high = n;
    low = n % (int)(pow(10,lev)) + 1; 
    quo = n / (int)(pow(10,lev));

    if (quo > 1) {
        retval += (int)(pow(10,lev));
    }
    else {
        retval += low;
    }

    retval += lev * (int)(pow(10,lev-1)) * quo;

    return retval + number_of_1(low-1);
}

