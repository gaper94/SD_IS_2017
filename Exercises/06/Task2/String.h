#pragma once

#include <cstdlib>
#include <iostream>

class String
{
private:
    char* data;
    size_t currentSize;
    size_t capacity;

    void copy(const String& v);
    void erase();

    void resize(size_t newSize);
public:
    String(const char* str = nullptr);

    String(const String& other);
    String& operator = (const String& other);

    ~String();

    char& operator [](size_t index);

    char operator [](size_t index) const;

    String& operator += (char c);

    size_t length() const;

    void reverse();

    friend std::ostream& operator << (std::ostream& os, const String& string);
};

