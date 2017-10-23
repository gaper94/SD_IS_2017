#include <cstring>
#include <fstream>
#include <iostream>

const size_t MAX_ROW_LENGTH = 1024;

void printLines(const char* filename, int lines)
{
    std::ifstream is;
    is.open(filename);

    if(!is)
    {
        std::cout << filename << " : File does not extst or could not be opened." << std::endl;
        return;
    }

    std::cout << "### " << filename << " ###" <<  std::endl;

    size_t i = 0;

    char str[MAX_ROW_LENGTH];

    while((i < lines || lines == -1))
    {
        is.getline(str, MAX_ROW_LENGTH);

        if(is.eof())
        {
            break;
        }

        std::cout << str << std::endl;

        ++i;
    }
}

bool isLinesCountOptionMarker(const char* str)
{
    return std::strcmp(str, "-l") == 0;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isNonNegativeNumber(const char* str)
{
    if(str == NULL)
    {
        return false;
    }

    size_t i = 0;
    while(str[i] != '\0')
    {
        if(!isDigit(str[i]))
        {
            return false;
        }

        ++i;
    }

    return true;
}

int toNonNegativeNumber(const char* str)
{
    int number = 0;

    size_t i = 0;
    while(str[i] != '\0')
    {
        number *= 10;
        number += str[i] - '0';

        ++i;
    }

    return number;
}

int main(int argc, char** argv)
{
    if(argc < 2 ||
      (argc == 2 && isLinesCountOptionMarker(argv[1])) ||
      (argc == 3 && isLinesCountOptionMarker(argv[1]) && isNonNegativeNumber(argv[2])))
    {
        std::cout << "Too fiew arguments passed." << std::endl;
        return 0;
    }

    if(argc >= 3 && isLinesCountOptionMarker(argv[1]) && !isNonNegativeNumber(argv[2]))
    {
        std::cout << "Non-negative nuber must be passed after -l." << std::endl;
        return 0;
    }

    int lines = -1;
    size_t firstFilenameIndex = 1;

    if(isLinesCountOptionMarker(argv[1]))
    {
        lines = toNonNegativeNumber(argv[2]);
        firstFilenameIndex = 3;
    }

    for(size_t i = firstFilenameIndex; i < argc; ++i)
    {
        printLines(argv[i], lines);
    }

    return 0;
}
