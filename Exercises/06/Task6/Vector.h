#pragma once

template <typename T>
class Vector
{
private:
    T* elements;
    size_t currentSize;
    size_t capacity;

    void copy(const Vector<T>& v);
    void erase();

public:
    Vector(size_t capacity = 100);

    Vector(const Vector<T>& other);
    Vector<T>& operator = (const Vector<T>& other);

    ~Vector();

    T& operator [] (size_t index);
    T operator [] (size_t index) const;

    size_t size() const;
    void push(T elem);
    void removeAt(size_t index);
    void insertAt(size_t index, const T& elem);

    void popFront();
    void pushFront(const T& elem);

    void resize(size_t newSize);
};

template <typename T>
Vector<T>::Vector(size_t capacity)
{
    capacity = capacity;
    elements = new T[capacity];
    currentSize = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& other)
{
    if(this != & other)
    {
        erase();
        copy(other);
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    erase();
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    capacity = other.capacity;
    currentSize = other.currentSize;
    elements = new T[capacity];

    for(size_t i = 0; i < currentSize; ++i)
    {
        elements[i] = other.elements[i];
    }
}

template <typename T>
void Vector<T>::erase()
{
    delete [] elements;
}

template <typename T>
void Vector<T>::resize(size_t newSize)
{
    capacity = newSize;
    T* temp = new T[capacity];

    for(size_t i = 0; i < currentSize; ++i)
    {
        temp[i] = elements[i];
    }

    T* oldElements = elements;
    elements = temp;
    delete [] oldElements;
}

template <typename T>
T& Vector<T>::operator [](size_t index)
{
    return elements[index];
}

template <typename T>
T Vector<T>::operator [](size_t index) const
{
    return elements[index];
}

template <typename T>
size_t Vector<T>::size() const
{
    return currentSize;
}

template <typename T>
void Vector<T>::push(T elem)
{
    if(currentSize == capacity)
    {
        resize(capacity * 2);
    }

    elements[currentSize] = elem;

    ++currentSize;
}

template <typename T>
void Vector<T>::removeAt(size_t index)
{
    if(index < 0 || index > currentSize - 1)
    {
        return;
    }

    for(size_t i = index; i < currentSize - 1; ++i)
    {
        elements[i] = elements[i + 1];
    }

    --currentSize;

    if(currentSize < 0.25 * capacity)
    {
        resize(capacity * 0.5);
    }
}

template <typename T>
void Vector<T>::insertAt(size_t index, const T& elem)
{
    if(index < 0 || index > currentSize - 1)
    {
        return;
    }

    if(currentSize + 1 > capacity)
    {
        resize(capacity * 2);
    }

    if(index < 0 || index > currentSize - 1)
    {
        return;
    }

    for(size_t i = currentSize; i > index; --i)
    {
        elements[i] = elements[i - 1];
    }

    currentSize++;

    elements[index] = elem;
}

template <typename T>
void Vector<T>::popFront()
{
    removeAt(0);
}

template <typename T>
void Vector<T>::pushFront(const T& elem)
{
    insertAt(0, elem);
}
