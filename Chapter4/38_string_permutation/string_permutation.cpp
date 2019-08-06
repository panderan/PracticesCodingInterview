#include "string_permutation.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

void _permutation(char *src, char *cur, int &cnt)
{
    if (*cur == '\0') {
        printf("%s\n", src);
        cnt++;
    }
    else {
        for (int i=0; *(cur+i)!='\0'; i++) {
            char c = *cur;
            *cur = *(cur+i);
            *(cur+i) = c;
            _permutation(src, cur+1, cnt);
            c = *cur;
            *cur = *(cur+i);
            *(cur+i) = c;
        }
    }
}

int permutation(const char *src)
{
    int length = 0, cnt=0;
    char * cur = NULL;

    if (src == NULL) {
        return 0;
    }
    length = strlen(src);
    cur = (char *)calloc(length+1, sizeof(char));
    strcpy(cur, src); 
     
    _permutation(cur, cur, cnt);
    free(cur);
    return cnt;
}

