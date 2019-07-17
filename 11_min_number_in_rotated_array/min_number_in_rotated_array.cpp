#include "min_number_in_rotated_array.h"
#include <unistd.h>

static int min_in_order(int numbers[], int start, int end);

int min(int numbers[], int length)
{
    int start = 0, end = 0, middle = 0;
    
    if (numbers == NULL || length < 1) {
        return 0;
    }

    end = length - 1;
	if (*(numbers) < *(numbers+end)) {
		return *(numbers);
	}
    
    while (end-start!=1) {
        middle = (end-start)/2 + start;
        if (*(numbers+start) == *(numbers+end) \
            && *(numbers+middle) == *(numbers+start)) {
            return min_in_order(numbers, start, end);
        }
        if (*(numbers+middle) >= *(numbers+start)) {
            start = middle;
        }
        else if (*(numbers+middle) <= *(numbers+end)) {
            end = middle;
        }
    }
    return *(numbers+end);


}

static int min_in_order(int numbers[], int start, int end)
{
    int min = *(numbers+start);

    for (int i = start+1; i <= end; i++) {
        if (min > *(numbers+i)) {
            min = *(numbers+i);
        }
    }
    return min;
}
