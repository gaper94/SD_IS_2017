#include "Queue.h"
#include "Vector.h"
#include <iostream>

void BFS(const Vector< Vector<size_t>>& graph, Vector<bool>& visited, size_t start)
{
    size_t nodesCount = graph.size();

    for(size_t i = 0; i < nodesCount; ++i)
    {
        visited[i] = false;
    }

    queue<size_t> q;
    q.enqueue(start);

    size_t current;

    while(q.is_empty())
    {
        current = q.dequeue();
        visited[current] = true;

        for(size_t i = 0; i < nodesCount; ++i)
        {
            if(graph[current][i] != 0)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }
    }
}

int main()
{
    Vector< Vector <size_t> > graph;

    size_t nodesCount;
    std::cin >> nodesCount;

    size_t current;

    for(size_t i = 0; i < nodesCount; ++i)
    {
        graph.push(Vector<size_t>());

        for(size_t j = 0; j < nodesCount; ++j)
        {
            std::cin >> current;
            graph[i].push(current);
        }
    }

    Vector<bool> visited;

    BFS(graph, visited, 0);

    return 0;
}

