#include <assert.h>
//////////////////////////////////////////////////////////////////////////
template<class T>
linked_list<T>::~linked_list()
{
    empty_list();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
linked_list<T>::linked_list(const linked_list& other)
{
    for (iterator<T> it = other.begin(); it != other.end(); ++it)
    {
        push_back(*it);
    }
}

//////////////////////////////////////////////////////////////////////////
template<class T>
linked_list<T>& linked_list<T>::operator=(const linked_list& rhs)
{
    if (this != &rhs)
    {
        empty_list();
        for (iterator<T> it = rhs.begin(); it != rhs.end(); ++it)
        {
            push_back(*it);
        }
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
linked_list<T>& linked_list<T>::operator+=(const linked_list& rhs)
{
    for (iterator<T> it = rhs.begin(); it != rhs.end(); ++it)
    {
        push_back(*it);
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
bool linked_list<T>::is_empty() const
{
    return size == 0;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
size_t linked_list<T>::get_size() const
{
    return size;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
void linked_list<T>::push_front(const T& data)
{
    node<T>* new_head = new node<T>;
    new_head->data = data;
    new_head->next = head;
    if (is_empty() == true)
    {
        tail = new_head;
    }
    head = new_head;
    size++;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
void linked_list<T>::push_back(const T& data)
{
    node<T>* new_tail = new node<T>;
    new_tail->data = data;
    if (is_empty() == true)
    {
        head = new_tail;
        tail = new_tail;
    }
    else
    {
        tail->next = new_tail;
        tail = new_tail;
    }
    size++;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T linked_list<T>::pop_front()
{
    assert(is_empty() == false);

    T data = head->data;
    node<T>* old_head = head;
    head = old_head->next;
    //
    if (head == nullptr)
    {
        // end of list, set tail to null as well
        tail = nullptr;
    }
    size--;
    return data;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T linked_list<T>::pop_back()
{
    assert(is_empty() == false);
    return remove_at(size - 1);
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T linked_list<T>::remove_at(size_t idx)
{
    if (idx == 0)
    {
        return pop_front();
    }
    else
    {
        node<T>* prev_node = node_at(idx - 1);
        assert(prev_node != nullptr); // invalid_idx
        assert(prev_node->next != nullptr); // invalid_idx

        node<T>* node_to_remove = prev_node->next;
        T old_data = node_to_remove->data;
        prev_node->next = node_to_remove->next;
        // When deleting last element, update tail
        if (idx == size - 1)
        {
            tail = prev_node;
        }
        delete node_to_remove;

        size--;
        return old_data;
    }
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T& linked_list<T>::peek_front()
{
    assert(head != nullptr);
    //
    return head->data;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const T& linked_list<T>::peek_front() const
{
    assert(head != nullptr);
    //
    return head->data;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T& linked_list<T>::peek_back()
{
    assert(tail != nullptr);
    //
    return tail->data;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const T& linked_list<T>::peek_back() const
{
    assert(tail != nullptr);
    //
    return tail->data;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
node<T>* linked_list<T>::node_at(size_t idx)
{
    node<T>* node_to_find = head;
    size_t curr_idx = 0;
    while (node_to_find != nullptr && curr_idx < idx)
    {
        node_to_find = node_to_find->next;
        curr_idx++;
    }
    return node_to_find;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
void linked_list<T>::empty_list()
{
    while (is_empty() == false)
    {
        pop_front();
    }
}