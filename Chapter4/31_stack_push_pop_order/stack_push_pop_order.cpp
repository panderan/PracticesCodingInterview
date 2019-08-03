#include "stack_push_pop_order.h"
#include <stack>
#include <unistd.h>

bool is_pop_push_order(const int push[], const int pop[], int length)
{
    std::stack<int> s;
    int push_idx = 0, pop_idx = 0;

    if (push == NULL || pop == NULL || length < 1) {
        return false;
    }

    s.push(push[push_idx++]);
    while (pop_idx < length) {
        if (s.top() == pop[pop_idx]) {
            s.pop();
            pop_idx++;
        }
        else {
            if (push_idx == length) {
                break;
            }
            s.push(push[push_idx++]);
        }
    }

    return push_idx==pop_idx ? true : false;
}
