#include "Stack.h"
#include "Vector.h"
#include <iostream>

void DFS(const Vector< Vector<size_t>>& graph, Vector<bool>& visited, size_t start)
{
    size_t nodesCount = graph.size();

    for(size_t i = 0; i < nodesCount; ++i)
    {
        visited[i] = false;
    }

    stack<size_t> s;
    s.push(start);

    size_t current;
    while(!s.is_empty())
    {
        current = s.pop();
        if(!visited[current])
        {
            visited[current] = true;
            for(size_t i = 0; i < nodesCount; ++i)
            {
                if(graph[current][i] != 0)
                {
                    s.push(i);
                }
            }
        }
    }
}

bool isConnected(const Vector< Vector<size_t>>& graph)
{
    size_t nodesCount = graph.size();
    Vector<bool> visited(nodesCount);

    DFS(graph, visited, 0);

    for(size_t i = 0; i < nodesCount; ++i)
    {
        if(!visited[i])
        {
            return false;
        }
    }

    return true;
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

    if(isConnected(graph))
    {
        std::cout << "Yes." << std::endl;
    }
    else
    {
        std::cout << "No." << std::endl;
    }

    return 0;
}

