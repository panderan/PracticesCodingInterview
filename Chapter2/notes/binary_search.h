#ifndef _SEARCH_H
#define _SEARCH_H

#include <unistd.h>

int compare_int(int a, int b)
{
    return a-b;
}

template<typename T>
int binary_search_ex(T arr[], int length, T target, int (*compare)(T t1, T t2))
{
    int s_idx = 0, m_idx = 0, e_idx = 0, ret = 0;

    if (arr == NULL || length < 1) {
        return -1;
    }

    s_idx = 0;
    e_idx = length-1;
    m_idx = (e_idx-s_idx)/2+s_idx;

    
    while (e_idx >= s_idx) {
        if ((ret=compare(arr[m_idx], target)) == 0) {
            return m_idx;
        }

        // 大于零，start右移；
        // 小于零，end左移；
        if (ret<0) {
            s_idx = m_idx+1;
            m_idx = (e_idx-s_idx)/2+s_idx;
        }
        else {
            e_idx = m_idx-1;
            m_idx = (e_idx-s_idx)/2+s_idx;
        }
    }
    return -1;
}

#define binary_search(arr, length, target) binary_search_ex(arr, length, target, compare_int)

#endif
