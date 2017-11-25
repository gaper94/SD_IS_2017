#include "Stack.h"
#include "String.h"
#include <iostream>

void sumBigNaturalNumbers(const String& left, const String& right, String& result)
{
    stack<int> leftStack, rightStack;

    size_t length = left.length();

    for(size_t i = 0; i < length; ++i)
    {
        leftStack.push(left[i] - '0');
    }

    length = right.length();

    for(size_t i = 0; i < length; ++i)
    {
        rightStack.push(right[i] - '0');
    }

    int addToNextDigit = 0;
    int currentSum;

    while(!leftStack.is_empty() && !rightStack.is_empty())
    {
        currentSum = leftStack.peek() + rightStack.peek() + addToNextDigit;

        addToNextDigit = 0;

        if(currentSum >=  10)
        {
            addToNextDigit = 1;
            currentSum -= 10;
        }

        result += ( '0' + currentSum);
        leftStack.pop();
        rightStack.pop();
    }

    if(!leftStack.is_empty())
    {
        currentSum = leftStack.peek() + addToNextDigit;

        addToNextDigit = 0;

        if(currentSum >=  10)
        {
            addToNextDigit = 1;
            currentSum -= 10;
        }
        result += ( '0' + currentSum);
        leftStack.pop();

        while(!leftStack.is_empty())
        {
            currentSum = leftStack.peek() + addToNextDigit;

            addToNextDigit = 0;

            if(currentSum >=  10)
            {
                addToNextDigit = 1;
                currentSum -= 10;
            }

            result += ( '0' + currentSum);
            leftStack.pop();
        }
    }
    else if(!rightStack.is_empty())
    {
        currentSum = rightStack.peek() + addToNextDigit;

        addToNextDigit = 0;

        if(currentSum >=  10)
        {
            addToNextDigit = 1;
            currentSum -= 10;
        }
        result += ( '0' + currentSum);
        rightStack.pop();

        while(!rightStack.is_empty())
        {
            currentSum = rightStack.peek() + addToNextDigit;

            addToNextDigit = 0;

            if(currentSum >=  10)
            {
                addToNextDigit = 1;
                currentSum -= 10;
            }

            result += ( '0' + currentSum);
            rightStack.pop();
        }
    }
    else
    {
        if(addToNextDigit > 0)
        {
            result += ( '0' + currentSum);
        }
    }

    result.reverse();
}

int main()
{
    String left("1234567890");
    String right("98765432100223");
    String result;

    sumBigNaturalNumbers(left, right, result);

    std::cout << result << std::endl;

    return 0;
}

