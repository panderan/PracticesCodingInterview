#ifndef _QUEUE_WITH_TWO_STACKS_H
#define _QUEUE_WITH_TWO_STACKS_H
#include <iostream>
#include <stack>
#include <exception>
#include <stdexcept>

template <typename T> class queue 
{
    public:
        queue(void){}
        ~queue(void){}

        void append_tail(const T& node);
        T delete_head();
    
    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
};

template<typename T> void queue<T>::append_tail(const T& node)
{
    stack1.push(node);
}

template<typename T> T queue<T>::delete_head()
{
    if (stack2.empty()) {
        while (stack1.empty() == false) {
           stack2.push(stack1.top());
           stack1.pop();
        }
        if (stack2.empty()) {
            std::logic_error e("queue is empty");
            throw std::exception(e);
        }
    }

    T head = stack2.top();
    stack2.pop();

    return head;
}
#endif
