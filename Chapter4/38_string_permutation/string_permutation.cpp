#include "string_permutation.h"

int _permutation(char *src, char *cur, int length)
{

}

int permutation(char *src)
{
    int length = 0;
    char * cur = NULL;

    if (src == NULL) {
        return 0;
    }
    length = strlen(src);
    cur = calloc(length, sizeof(char));
     
    _permutation(src, cur, length, 0);
}
