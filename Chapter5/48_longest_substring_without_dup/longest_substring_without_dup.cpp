#include "longest_substring_without_dup.h"

int distance_prev_char(const char *str, int pos)
{
    char c;
    int len = 0;

    for (c=*(str+pos),len=1; len<=pos; len++) {
        if (*(str+pos-len) == c) {
            return len;
        }
    }
    return 0;
}

int longest_substring_without_dup(const char *str)
{
    int i = 0, max = 0, prev = 0, cur = 0, dist = 0;
    
    for (i=0; *(str+i)!='\0'; i++) {
        dist = distance_prev_char(str, i);
        if (dist == 0 || dist > prev) {
            cur = prev+1;
        }
        else {
            cur = dist;
        }

        max = max<cur ? cur : max;
        prev = cur;
        cur = 0;
    }

    return max;
}
