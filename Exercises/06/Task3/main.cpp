#include "Queue.h"
#include <iostream>

template <typename T>
T minElement(queue<T> q)
{
    T min = q.dequeue();

    while(!q.is_empty())
    {
        if(q.peek_first() < min)
        {
            min = q.dequeue();
        }
        else
        {
            q.dequeue();
        }
    }

    return min;
}

int main()
{
    queue<int> q;
    q.enqueue(3);
    q.enqueue(0);
    q.enqueue(-100);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(-20);

    std::cout << minElement<int>(q) << std::endl;

    return 0;
}

