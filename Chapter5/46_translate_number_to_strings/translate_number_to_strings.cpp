#include "translate_number_to_strings.h"
#include <cmath>
#include <cstring>
#include <cstdlib>

int _get_translate_count(char number[])
{
    int len = 0, i = 0, cnt = 0;
    int f_n = 0, f_np1 = 0, f_np2 = 0;

    len = strlen(number);
    for (i=len-1; i>=0; i--) {

        if (len-i == 1) {
            f_np2 = 1;
            f_n = f_np2;
            continue;
        }
        if (len-i == 2) {
            f_np1 = 0;
            if (number[i]!='0' && (number[i]-'0')*10+(number[i+1]-'0') < 26) {
                f_np1++;
            }
            f_np1++;
            f_n = f_np1;
            continue;
        }

        if (number[i]!='0' && (number[i]-'0')*10+(number[i+1]-'0') < 26) {
            f_n = f_np1 + f_np2;
        }
        else {
            f_n = f_np1;
        }

        f_np2 = f_np1;
        f_np1 = f_n;
    }

    return f_n;
}

int get_translate_count(unsigned int number)
{
    unsigned int len = 0, num = 0, i = 0;
    char *numstr = NULL;

    for (num=number/10,len=1; num!=0; num/=10, len++);
    numstr =(char *) alloca(sizeof(char)*len+1);

    for (num=number, i=0; i<len; num/=10,i++) {
        *(numstr+len-1-i) = (num%10)+'0';
    }
    *(numstr+len) = '\0';

    return _get_translate_count(numstr);
}

