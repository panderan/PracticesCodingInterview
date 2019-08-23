#include "k_least_numbers.h"
#include <unistd.h>
#include <set>

using namespace std;

bool g_error = false;

int partition(int numbers[], int length)
{
    int start = 0, end = 0, target = 0;

    if (numbers == NULL || length < 1) {
        return -1;
    }

    target = *(numbers);
    start = 0;
    end = length-1;

    while (start < end) {
        for (; start<end && *(numbers+end)>=target; end--);
        *(numbers+start) = *(numbers+end);
        for (; start<end && *(numbers+start)<target; start++);
        *(numbers+end) = *(numbers+start);
    }

    *(numbers+start) = target;

    return start;

}

void get_least_numbers(int *input, int length, int *output, int n)
{
    int start = 0, end = 0, index = 0, i = 0;

    g_error = false;
    if (input == NULL || length < 1 || output == NULL || n < 1) {
        g_error = true;
        return;
    }

    start = 0;
    end = length;
    index = -1;
    
    if (n < length) {
        while (start+index != n) {
		    int cur_pos = start+index;
            start = cur_pos < n ? start+index+1 : start;
            end = cur_pos < n ? end : start+index;
            index = partition(input+start, end-start);
		    if (index == -1) {
                g_error == true;
                return;
		    }
        }
    }
    else {
        n = length;
    }

    for (i = 0; i < n; i++) {
        *(output+i) = *(input+i);
    }

    return ;
}

void get_least_numbers_quick(int *input, int length, int *output, int n)
{
    int i = 0;
    multiset<int, greater<int> > mset;
    multiset<int, greater<int> >::iterator iter;
        
    g_error = false;
    if (input == NULL || length < 1 || output == NULL || n < 1) {
        g_error = true;
        return;
    }

    for (i=0; i < length; i++) {
        if (mset.size() < n) {
            mset.insert(*(input+i));
        }
        if (mset.size() == n 
            && *(input+i) < *(mset.begin())) 
        {
            mset.erase(*(mset.begin()));
            mset.insert(*(input+i));
        }
    }

    for (i=0, iter=mset.begin(); iter!=mset.end(); iter++) {
        *(output+i++)=*iter;
    }
    return ;
}








