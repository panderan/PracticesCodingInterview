#include "missing_number.h"
#include <unistd.h>

int compare(const int numbers[], int length, int m_idx)
{
    if (numbers[m_idx] == m_idx) {
        return 1;
    }
    else {
        if (m_idx == 0 || numbers[m_idx-1] == m_idx-1) {
            return 0;
        }
        else {
            return -1;
        }
    }
}

int binary_search(const int numbers[], int length, int (*compare)(const int numbers[], int length, int m_idx))
{
    int s_idx = 0, e_idx = 0, m_idx = 0;
    int ret = 0;

    if (numbers == NULL || compare == NULL || length < 1) {
        return -1;
    }

    s_idx = 0;
    e_idx = length-1;

    while (s_idx <= e_idx) {
        m_idx = s_idx + (e_idx-s_idx)/2;
        ret = compare(numbers, length, m_idx);
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

int get_missing_number(const int numbers[], int length)
{
    int ret = 0;
    
    if (numbers[length-1] == length-1) {
        return length;
    }

    ret = binary_search(numbers, length, compare);
    return ret;
}

