#ifndef NODE_H
#define NODE_H

template<class T>
struct node
{
    T data;
    node<T>* next = nullptr;
};

#endif // NODE_H