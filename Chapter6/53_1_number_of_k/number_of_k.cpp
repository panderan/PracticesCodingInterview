#include "number_of_k.h"
#include <unistd.h>

int get_first(const int data[], int length, int k, int m_idx)
{
    if (data[m_idx] >= k) {
        if (data[m_idx] == k && (m_idx == 0 || data[m_idx-1] != k)) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        return 1;
    }
}

int get_last(const int data[], int length, int k, int m_idx) 
{
    if (data[m_idx] <= k) {
        if (data[m_idx] == k && (m_idx == length-1 || data[m_idx+1] != k)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return -1;
    }
}

int binary_search(const int data[], int length, int k, int (*compare)(const int data[], int length, int k, int m_idx))
{
    int s_idx = 0, e_idx = 0, m_idx = 0;
    int ret = 0;

    s_idx = 0;
    e_idx = length-1;

    while (s_idx <= e_idx) {
        m_idx = s_idx + (e_idx-s_idx)/2;
        ret = compare(data, length, k, m_idx);
        if (ret > 0) {
            s_idx = m_idx+1;
        }
        else if (ret<0) {
            e_idx = m_idx-1;
        }
        else {
            return m_idx;
        }
    }
    
    return -1;
}

int get_number_of_k(const int data[], int length, int k)
{
   int first_idx = 0, last_idx = 0;
   
   if (data == NULL || length < 1) {
       return -1;
   }

   first_idx = binary_search(data, length, k, get_first);
   last_idx = binary_search(data, length, k, get_last);
    
    if (last_idx == -1 || first_idx == -1) {
        return 0;
    }

   return last_idx - first_idx + 1; 
}

