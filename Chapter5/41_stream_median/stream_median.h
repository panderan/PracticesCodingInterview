#ifndef _STREAM_MEDIAN_H
#define _STREAM_MEDIAN_H

#include <algorithm>
#include <vector>
#include <functional>

template <typename T>
class array_with_median
{
    private:
        std::vector<T> min;
        std::vector<T> max;

    public:
        array_with_median(){}
        ~array_with_median(){}

    public:
        void insert(T a);
        T get_median();
};

template<typename T>
void array_with_median<T>::insert(T a)
{
    if (min.size() - max.size() > 0) {
        if (max.size() > 0 && a < max[0]) {
            max.push_back(a);
            push_heap(max.begin(), max.end(), std::less<T>());

            a = max[0];
            pop_heap(max.begin(), max.end(), std::less<T>());
            max.pop_back();
        }

        min.push_back(a);
        push_heap(min.begin(), min.end(), std::greater<T>());
    }
    else {
        if (min.size() > 0 && a > min[0]) {
            min.push_back(a);
            push_heap(min.begin(), min.end(), std::greater<T>());

            a = min[0];
            pop_heap(min.begin(), min.end(), std::greater<T>());
            min.pop_back();
        }

        max.push_back(a);
        push_heap(max.begin(), max.end(), std::less<T>());
    }
}

template <typename T>
T array_with_median<T>::get_median()
{
    if (max.size() == min.size() ) {
        return (max[0]+min[0])/2;
    }
    else {
        return max[0];
    }
}

#endif
