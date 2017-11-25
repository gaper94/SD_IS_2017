#include "String.h"

#include <cassert>
#include <utility>
#include <cstring>

String::String(const char* str)
{
    if(str == nullptr)
    {
        currentSize = 1;
        data = new char[currentSize];
        data[0] = '\0';
    }
    else
    {
        currentSize = strlen(str) + 1;
        data = new char[currentSize];
        strcpy(data, str);
    }

    capacity = currentSize;
}

String::String(const String& other)
{
    copy(other);
}

String& String::operator = (const String& other)
{
    if(this != & other)
    {
        erase();
        copy(other);
    }

    return *this;
}

String::~String()
{
    erase();
}

void String::copy(const String& other)
{
    capacity = other.capacity;
    currentSize = other.currentSize;
    data = new char[capacity];

    for(size_t i = 0; i < currentSize; ++i)
    {
        data[i] = other.data[i];
    }
}

void String::erase()
{
    delete [] data;
}

void String::resize(size_t newSize)
{
    capacity = newSize;
    char* temp = new char[capacity];

    for(size_t i = 0; i < currentSize; ++i)
    {
        temp[i] = data[i];
    }

    char* oldData = data;
    data = temp;
    delete [] oldData;
}


char& String::operator [](size_t index)
{
    assert(index < length());

    return data[index];
}

char String::operator [](size_t index) const
{
    assert(index < length());

    return data[index];
}

String& String::operator += (char c)
{
    if(currentSize == capacity)
    {
        resize(currentSize * 2);
    }

    data[currentSize - 1] = c;
    data[currentSize] = '\0';
    ++currentSize;

    return *this;
}

size_t String::length() const
{
    return currentSize - 1;
}

void String::reverse()
{
    size_t mid = (currentSize - 1) / 2;

    for(size_t i = 0; i < mid; ++i)
    {
        std::swap(data[i], data[currentSize - i - 2]);
    }
}

std::ostream& operator << (std::ostream& os, const String& string)
{
    os << string.data;

    return os;
}
