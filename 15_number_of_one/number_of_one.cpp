#include "number_of_one.h"

int number_of_one(int n)
{
    int count = 0;

    while(n) {
        n = (n-1)&n;
        count++;
    }

    return count;
}

int number_of_one2(int n)
{
    int flag = 1, count = 0;

    while (flag) {
        if (flag & n)
            count++;
        flag = flag << 1;
    }

    return count;
}
