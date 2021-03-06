//////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>::queue(const queue& other)
: container(other.container)
{
}

//////////////////////////////////////////////////////////////////////////
template<class T>
queue<T>& queue<T>::operator=(const queue& rhs)
{
    if (this != &rhs)
    {
        container = rhs.container;
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////
template<class T>
bool queue<T>::is_empty() const
{
    return container.is_empty();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
void queue<T>::enqueue(const T& data)
{
    container.push_front(data);
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T queue<T>::dequeue()
{
    return container.pop_back();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T& queue<T>::peek_first()
{
    return container.peek_back();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const T& queue<T>::peek_first() const
{
    return container.peek_back();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
T& queue<T>::peek_last()
{
    return container.peek_front();
}

//////////////////////////////////////////////////////////////////////////
template<class T>
const T& queue<T>::peek_last() const
{
    return container.peek_front();
}
