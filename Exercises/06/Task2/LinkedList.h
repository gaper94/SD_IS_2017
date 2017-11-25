#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include "Node.h"
#include "ListIterator.h"

template<class T>
class linked_list
{
public:
    linked_list() {}
    ~linked_list();
    linked_list(const linked_list& other);

    linked_list& operator=(const linked_list& rhs);
    linked_list& operator+=(const linked_list& rhs);

    bool is_empty() const;
    size_t get_size() const;

    void push_front(const T& data);
    void push_back(const T& data);
    T pop_back();
    T pop_front();
    T remove_at(size_t idx);

    T& peek_front();
    const T& peek_front() const;
    T& peek_back();
    const T& peek_back() const;

    iterator<T> begin() { return iterator<T>(head); }
    iterator<T> end() { return iterator<T>(nullptr); }

private:
    node<T>* node_at(size_t idx);
    void empty_list();
    size_t size = 0;
    node<T>* head = nullptr;
    node<T>* tail = nullptr;
};

#include "LinkedList.hpp"

#endif // LINKED_LIST_H
