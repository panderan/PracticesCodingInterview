#include "duplication_no_edit.h"
#include <unistd.h>

static int num_count(int numbers[], int length, int start, int end);

bool duplication2(int numbers[], int length, int *duplication)
{
    int start = 0, end = 0, middle = 0;
    int dup_num = 0;

    if (numbers == NULL || length < 2 || duplication == NULL) {
        return false;
    }

    start = 1;
    end = length - 1;
    middle = ((end - start)>>1) + start;

    dup_num = num_count(numbers, length, start, middle);
    if (dup_num != -1) {
        *duplication = dup_num;
        return true;
    }

    dup_num = num_count(numbers, length, middle+1, end);
    if (dup_num != -1) {
        *duplication = dup_num;
        return true;
    }

    *duplication = -1;
    return false;

}

static int num_count(int numbers[], int length, int start, int end)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] < start || numbers[i] > end) {
            continue;
        }
        count++;
    }

    if (count <= end - start + 1) {
        return -1;
    }

    if (start == end) {
        return start;
    }

    int n_middle = 0, retval = -1;
    n_middle = ((end - start)>>1) + start;

    if ((retval = num_count(numbers, length, start, n_middle)) != -1) {
        return retval;
    }

    if ((retval = num_count(numbers, length, n_middle+1, end )) != -1) {
        return retval;
    }

    return -1;
}
