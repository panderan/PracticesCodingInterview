#include "print_1_to_max_of_n_digits.h"
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <cstdio>

bool increment(char * strnum, int len) 
{
    int n_take_over = 1;

    for (int i=len-1; i>=0; i--) {
        int c = *(strnum+i) - '0';
        c = c+n_take_over;
        n_take_over = c/10;
        c = c%10;
        *(strnum+i) = c+'0';
    }
    
    return n_take_over ? false : true;

}

void print_1_to_max_of_n_digits(int n)
{
    if (n < 1) {
        return ;
    }

    char *strnum = NULL;
    strnum = (char *)calloc(n+1, sizeof(char));
    memset(strnum, '0', n);
    
    while (increment(strnum, n)) {
        char *start = NULL;
        for (start=strnum; *start=='0' && start-strnum<n; start++);
        printf("%s ", start);
    }
}

