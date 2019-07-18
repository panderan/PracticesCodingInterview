#include "duplication_in_array.h"
#include <unistd.h>

bool duplication(int numbers[], int length, int *duplication)
{
    if (numbers == NULL || length < 2 || duplication == NULL) {
        return false;
    }

    int i=0, j=0;
    for (i=0; i<length; i++) {
        if (numbers[i] == i)
            continue;
        if (numbers[i] == numbers[numbers[i]]) {
            *duplication = numbers[i];
            return true;
        }
        else {
            int tmp = numbers[numbers[i]];
            numbers[numbers[i]] = numbers[i];
            numbers[i] = tmp;
            i--;
        }
    }
    return false;
}
