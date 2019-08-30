#include "sort_array_for_min_number.h"
#include <unistd.h>
#include <cmath>

int compare(int a, int b)
{
    char num1[128], num2[128];
    int i = 0, j = 0, k = 0;

    for (i=0; a>0; num1[i++] = (a%10)+'0', a/=10);
    for (j=0; b>0; num2[j++] = (b%10)+'0', b/=10);
    for (k=0; k<j; num1[i+k] = num2[k], k++);
    for (k=0; k<i; num2[j+k] = num1[k], k++);

    for (k=0; k<i+j; k++) {
        if (num1[k] < num2[k]) {
            return 1;
        }
        if (num1[k] > num2[k]) {
            return -1;
        }
    }
    return 0;

}

int quick_sort(int numbers[], int length)
{
    int target = 0;
    int start = 0, end = 0;
         
    if (length <= 1) {
        return 0;
    }

    target = numbers[0];
    start = 0;
    end = length - 1;

    while (start != end) {
        for (; end!=start && end>0; end--) {
            if (compare(target, numbers[end]) == -1) {
                break;
            }
        }
        numbers[start] = numbers[end];

        for (; start!=end && start<length; start++) {
            if (compare(numbers[start], target) == -1) {
                break;
            }
        }
        numbers[end] = numbers[start];
    }
    numbers[start] = target;
    
    quick_sort(numbers, start);
    quick_sort(numbers+start+1, length-start-1);

    return start;
}

int print_min_number(int numbers[], int length, char output[], int outlen)
{
    int i = 0, j = 0, k = 0, num = 0, num_len = 0;

    if (numbers == NULL || length < 1 || output == NULL || outlen < 1) {
        return 1;
    }

    quick_sort(numbers, length);

    for (i=0,j=0; i<length; i++) {
        for (num=numbers[i], num_len=1; num/((int)pow(10, num_len))!=0; num_len++);
        for (k=0; num>0; num/=10, k++) {
            output[j+num_len-1-k] = (num%10)+'0';
        }
        j+=num_len;
    }
    output[j] = '\0';

    return j;
}

