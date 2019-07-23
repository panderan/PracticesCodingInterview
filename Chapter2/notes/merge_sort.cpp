#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <queue>
#include "sort.h"

using namespace std;

static int merge(int arr1[], int tmparr[], int s_idx, int m_idx, int e_idx)
{
    int i = 0, j = 0, tmpidx = 0;
    for (i=s_idx, j=m_idx; i < m_idx && j < e_idx;) {
        if (*(arr1+i) < *(arr1+j)) {
            *(tmparr+tmpidx++) = *(arr1+i);
            i++;
        }
        else {
            *(tmparr+tmpidx++) = *(arr1+j);
            j++;
        }
    }

    for (; i<m_idx; *(tmparr+tmpidx++) = *(arr1+i), i++);
    for (; j<e_idx; *(tmparr+tmpidx++) = *(arr1+j), j++);
    for (tmpidx=0; tmpidx < e_idx; *(arr1+tmpidx) = *(tmparr+tmpidx),tmpidx++);
    memcpy(arr1, tmparr, sizeof(int)*e_idx);
    return 0;
}

static int _merge_sort_recursion(int arr[], int tmparr[], int length)
{
    int s_idx = 0, m_idx = 0, e_idx = 0;    /* start, middle, end */
    int retval = 0;

    s_idx = 0;
    e_idx = length;
    m_idx = (e_idx+1)/2;

    if (e_idx > 1) {
        retval += _merge_sort_recursion(arr, tmparr, m_idx-s_idx);
        retval += _merge_sort_recursion(arr+m_idx, tmparr+m_idx, e_idx-m_idx);
        retval += merge(arr, tmparr, s_idx, m_idx, e_idx);
        if (retval) {
            return 1;
        }
    }
    return 0;
}

// 递归实现
int merge_sort_recursion(int arr[], int length) 
{
    int *tmparr = NULL;
    
    tmparr = (int *) alloca(sizeof(int) * length);
    if (tmparr == NULL) {
        return 1;
    }

    return _merge_sort_recursion(arr, tmparr, length);
}

// 循环实现
int merge_sort_loop(int arr[], int length)
{
    int *tmparr = NULL;
    
    tmparr = (int *) alloca(sizeof(int) * length);
    if (tmparr == NULL) {
        return 1;
    }

    typedef struct seg {
        int *arr;
        int *tmparr;
        int length;
    } seg_t;
    std::queue<seg_t> q;
     
    int i = 0, j = 0;
    for (i=0; i<length; i++) {
        seg_t s = {arr+i, tmparr+i, 1};
        q.push(s);
    }

    while (q.size() != 1) {
        seg_t s1 = q.front();
        q.pop();
        seg_t s2 = q.front();

        if (s1.arr+s1.length != s2.arr) {
            q.push(s1);
            continue;
        }
        q.pop();

        int s_idx = 0, m_idx = 0, e_idx = 0;    /* start, middle, end */
        int retval = 0;

        s_idx = 0;
        e_idx = s1.length+s2.length;
        m_idx = s1.length;

        retval = merge(s1.arr, s1.tmparr, s_idx, m_idx, e_idx);
        s1.length += s2.length;
        q.push(s1);
    }
    return 0;
}

