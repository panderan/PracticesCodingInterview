#ifndef _MIN_IN_STACK_H
#define _MIN_IN_STACK_H

#include <stack>
#include <exception>

template <typename T>
class stack_with_min 
{
    private:
        std::stack<T> m_data;
        std::stack<T> m_min;

    public:
        stack_with_min(){}
        ~stack_with_min(){}

    public:
        void push(const T &value);
        void pop();
        const T& top() const;
        const T& min() const;
        bool empty() const;
        size_t size() const;
};

template<typename T>
void stack_with_min<T>::push(const T &value)
{
    m_data.push(value);
    if (m_min.empty()) {
        m_min.push(value);
    }
    else {
        const T cur_min = m_min.top();
        if (cur_min < value) {
            m_min.push(cur_min);
        }
        else {
            m_min.push(value);
        }
    }
}

template <typename T>
void stack_with_min<T>::pop()
{
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& stack_with_min<T>::top() const
{
    return m_data.top();
}

template <typename T>
const T& stack_with_min<T>::min() const
{
    if (m_min.size() < 0 || m_data.size() < 0) {
        throw std::range_error("stack is empty.");
    }
    return m_min.top();
}

template <typename T>
bool stack_with_min<T>::empty() const 
{
    return m_data.empty();
}

template <typename T>
size_t stack_with_min<T>::size() const
{
    return m_data.size();
}

#endif
