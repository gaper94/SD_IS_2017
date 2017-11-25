#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template<class T>
class stack
{
public:
    stack() {}
    ~stack() {}
    stack(const stack& other);
    stack& operator=(const stack& rhs);

    bool is_empty() const;
    void push(const T& data);
    T pop();

    T& peek();
    const T& peek() const;
private:
    linked_list<T> container;
};

#include "Stack.hpp"
#endif // STACK_H