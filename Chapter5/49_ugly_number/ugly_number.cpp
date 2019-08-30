#include "ugly_number.h"
#include <unistd.h>
#include <cstdlib>

int get_ugly_number(int index)
{
    int *uglynums = NULL;
    int multi2 = 0, multi3 = 0, multi5 = 0;
    int candidates[3], min = 0, i=0;

    if (index < 1) {
        return 0;
    }

    uglynums = (int *) alloca((index+5)*sizeof(int));
    *(uglynums+0) = 1;
    *(uglynums+1) = 2;
    *(uglynums+2) = 3;
    *(uglynums+3) = 4;
    *(uglynums+4) = 5;
    multi2 = 2;
    multi3 = 1;
    multi5 = 1;

    for (i=5; i<index; i++) {
        candidates[0] = *(uglynums+multi2)*2;
        candidates[1] = *(uglynums+multi3)*3;
        candidates[2] = *(uglynums+multi5)*5;
        min = candidates[1]<candidates[0] ? candidates[1] : candidates[0];
        min = min < candidates[2] ? min : candidates[2];
        *(uglynums+i) = min;
        for (; *(uglynums+multi2)*2<=min; multi2++);
        for (; *(uglynums+multi3)*3<=min; multi3++);
        for (; *(uglynums+multi5)*5<=min; multi5++);
    }

    return *(uglynums+index-1);
}

