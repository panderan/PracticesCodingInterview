#include "first_not_repeating_char.h"
#include <unistd.h>

char first_not_repeating_char(const char* str)
{
    int map[256] = {0}, i = 0;
    
    if (str == NULL || *str == '\0') {
        return 0;
    }

    for (i=0; i<256; map[i++]=0);
    for (i=0; *(str+i)!='\0'; i++) {
        map[*(str+i)]++;
    }
    for (i=0; *(str+i)!='\0'; i++) {
        if (map[*(str+i)] == 1) {
            return *(str+i);
        }
    }
    return 0;
}
