#include "Queue.h"
#include <iostream>

template <typename T>
queue<T> mergeSortedQueues(queue<T> left, queue<T> right)
{
    queue<T> result;

    while(!left.is_empty() && !right.is_empty())
    {
        if(left.peek_first() <= right.peek_first())
        {
            result.enqueue(left.dequeue());
        }
        else
        {
            result.enqueue(right.dequeue());
        }
    }

    while(!left.is_empty())
    {
        result.enqueue(left.dequeue());
    }
    while(!right.is_empty())
    {
        result.enqueue(right.dequeue());
    }

    return result;
}

int main()
{
    queue<int> left;
    left.enqueue(-100);
    left.enqueue(-20);
    left.enqueue(0);
    left.enqueue(3);
    left.enqueue(5);
    left.enqueue(20);

    queue<int> right;
    right.enqueue(-20);
    right.enqueue(-10);
    right.enqueue(10);
    right.enqueue(20);

    queue<int> result = mergeSortedQueues<int>(left, right);

    while(!result.is_empty())
    {
        std::cout << result.dequeue() << " ";
    }

    std::cout << std::endl;

    return 0;
}

