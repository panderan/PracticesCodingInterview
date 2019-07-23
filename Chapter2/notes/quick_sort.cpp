#include "sort.h"
#include <queue>

using namespace std;

int quick_sort_recursion(int arr[], int length)
{
    int s_idx = 0, e_idx = 0;   // start，end index
    int base = 0;
    
    if (length < 2) {
        return 0;
    }

    base = *arr;
    s_idx = 0;
    e_idx = length-1;

    while (s_idx != e_idx) {
        for (;s_idx != e_idx; e_idx--) {
            if (*(arr+e_idx) < base) {
                *(arr+s_idx) = *(arr+e_idx);
                break;
            }
        }
        for (;s_idx!=e_idx; s_idx++) {
            if (*(arr+s_idx) > base) {
                *(arr+e_idx) = *(arr+s_idx);
                break;
            }
        }
    }
    *(arr+s_idx) = base;

    quick_sort_recursion(arr, s_idx);
    quick_sort_recursion(arr+1+s_idx, length-s_idx-1);

    return 0;
}

int quick_sort_loop(int arr[], int length) 
{
    typedef struct seg {
        int* arr;
        int length;
    } seg_t;
    queue<seg_t> q;
    int base = 0, s_idx = 0, e_idx = 0;
    
    seg_t s = {arr, length};
    q.push(s);
     
    while (q.empty() == false) {
        s = q.front();
        q.pop();
        base = *(s.arr);
        s_idx = 0;
        e_idx = s.length - 1;
        
        if (s.length < 2) {
            continue;
        }

        while (s_idx != e_idx) {
            for (;s_idx != e_idx; e_idx--) {
                if (*(s.arr+e_idx) < base) {
                    *(s.arr+s_idx) = *(s.arr+e_idx);
                    break;
                }
            }
            for (;s_idx!=e_idx; s_idx++) {
                if (*(s.arr+s_idx) > base) {
                    *(s.arr+e_idx) = *(s.arr+s_idx);
                    break;
                }
            }
        }
        *(s.arr+s_idx) = base;

        seg_t s1 = {s.arr, s_idx};
        seg_t s2 = {s.arr+1+s_idx, s.length-s_idx-1};
        q.push(s1);
        q.push(s2);
    }

    return 0;
}







