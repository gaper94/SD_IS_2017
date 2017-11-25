#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

template <class T>
class linked_list;

template<class T>
class iterator
{
    friend class linked_list<T>;
    iterator(node<T>* node) : _node(node) {}
public:
    iterator(const iterator&) = default;
    iterator& operator=(const iterator&) = default;

    iterator& operator++();
    iterator operator++(int);

    bool operator==(const iterator<T>& rhs);
    bool operator!=(const iterator<T>& rhs);

    T& operator*();
    const T& operator*() const;
private:
    node<T>* _node;
};

#include "ListIterator.hpp"

#endif // LIST_ITERATOR_H