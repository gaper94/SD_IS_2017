#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template<class T>
class queue
{
public:
    queue() {}
    ~queue() {}
    queue(const queue& other);
    queue& operator=(const queue& rhs);

    bool is_empty() const;
    void enqueue(const T& data);
    T dequeue();

    T& peek_first();
    const T& peek_first() const;
    T& peek_last();
    const T& peek_last() const;
private:
    linked_list<T> container;
};

#include "Queue.hpp"
#endif // QUEUE_H