#include "replace_spaces.h"
#include <unistd.h>
#include <cstring>

void replace_blank(char str[], int length)
{
    if (str == NULL || length < 1) {
        return;
    }

    int total_blanks = 0, i = 0, j = 0;
    for (i = 0 ; i < strlen(str); i++) {
        if (*(str+i) == ' ') {
            total_blanks++;
        }
    }
    
    int rp_len = 0;
    if ((rp_len = strlen(str) + total_blanks*2) > length) {
        return;
    }
    
    for(i = strlen(str)-1, j = rp_len-1; i!=j;i--,j--) {
        if (str[i] != ' ') {
            str[j] = str[i];
        }
        else {
            memcpy(str+j-2, "%20", 3);
            j-=2;
        }
    }
}
