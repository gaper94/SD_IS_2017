#include <Stack.h>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input("text.txt");

    if(!input)
    {
        std::cout << "Problem opening the file." << std::endl;
        return 0;
    }

    stack<char> s;
    char c;

    while(true)
    {
        input >> c;

        if(input.eof())
        {
            if(!s.is_empty())
            {
                std::cout<< std::endl << "All characters are processed, but the stack is not empty - wrong sequence!";
            }

            break;
        }

        if(c == '*')
        {
            if(s.is_empty())
            {
                std::cout << "Nothing to pop. The sequence is wrong.";
                break;
            }

            std::cout << s.peek();
            s.pop();
        }
        else
        {
            s.push(c);
        }
    }

    std::cout << std::endl;

    return 0;
}

