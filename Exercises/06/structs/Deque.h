#ifndef DEQUE__H
#define DEQUE_H
#include "LinkedList.h"

template<class T>
class deque
{
public:
    deque() {}
    ~deque() {}
    deque(const deque& other);

    deque& operator=(const deque& rhs);

    bool is_empty() const;
    size_t size() const;

    void push_front(const T& data);
    void push_back(const T& data);
    T pop_front();
    T pop_back();

    T& peek_front();
    const T& peek_front() const;

    T& peek_back();
    const T& peek_back() const;
private:
    linked_list<T> container;
};

#include "Deque.hpp"

#endif // DEQUE__H