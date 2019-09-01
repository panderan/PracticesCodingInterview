#include "integer_identical_to_index.h"
#include <unistd.h>

int compare(const int numbers[], int m_idx) 
{
    if (numbers[m_idx] > m_idx) {
        return -1;
    }
    else if (numbers[m_idx] < m_idx) {
        return 1;
    }
    else {
        return 0;
    }
}

int binary_search(const int numbers[], int length, int (*compare)(const int numbers[], int m_idx))
{
    int s_idx = 0, e_idx = 0, m_idx = 0;
    int ret = 0;
     
    if (numbers == NULL || length < 1 || compare == NULL) {
        return -1;
    }

    s_idx = 0;
    e_idx = length-1;

    while (s_idx <= e_idx) {
        m_idx = s_idx + (e_idx-s_idx)/2;
        ret = compare(numbers, m_idx);
        if (ret > 0) {
            s_idx = m_idx + 1;
        }
        else if (ret < 0) {
            e_idx = m_idx - 1;
        }
        else {
            return m_idx;
        }
    }
    return -1;
}

int get_number_same_as_index(const int numbers[], int length)
{
    int ret = 0;

    ret = binary_search(numbers, length, compare);
    return ret;
}





