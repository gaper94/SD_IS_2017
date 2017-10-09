#include <iostream>

void SimpleCalculator(int argc, char** argv);
void WordsCalculator(int argc, char** argv);
void Average(int argc, char** argv);
void Sort(int argc, char** argv);
void PrintUsage();

int main(int argc, char** argv)
{
    std::cout << "Number of given arguments: " << argc << std::endl;
    // The first elements is always the name of the execvutable
    std::cout << argv[0] << std::endl;
    // Print given arguments
    for (int i = 1; i < argc; i++)
    {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    //SimpleCalculator(argc - 1, &argv[1]);
    //WordsCalculator(argc - 1, &argv[1]);
    //Average(argc - 1, &argv[1]);
    //Sort(argc - 1, &argv[1]);
    return 0;
}

void SimpleCalculator(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Expected 3 arguments, but given " << argc << std::endl;
        std::cout << "Usage: <left_operand> <operator> <right_operand>" << std::endl;
        return;
    }
    int leftOperand = atoi(argv[1]);
    int rightOperand = atoi(argv[3]);
    // operator
    char operation = argv[2][0];
    int result = 0;
    switch (operation)
    {
        case '+':
        {
            result = leftOperand + rightOperand;
            break;
        }
        case '-':
        {
            result = leftOperand - rightOperand;
            break;
        }
        case '*':
        {
            result = leftOperand * rightOperand;
            break;
        }
        case '/':
        {
            if (rightOperand != 0)
            {
                result = leftOperand / rightOperand;
            }
            else
            {
                std::cout << "Invalid division by zero";
            }
            break;
        }
        default:
        {
            std::cout << "Invalid operator given" << std::endl;
            return;
        }
    }
    std::cout << "The result of the expression is " << result << std::endl;
}

void WordsCalculator(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Expected 3 arguments, but given " << argc << std::endl;
        std::cout << "Usage: <left_operand> <operator> <right_operand>" << std::endl;
        return;
    }
    int leftOperand = atoi(argv[1]);
    int rightOperand = atoi(argv[3]);
    // operator
    char* operation = argv[2];
    int result = 0;
    if (strcmp(operation, "addition") == 0)
    {
        result = leftOperand + rightOperand;
    }
    else if (strcmp(operation, "subtraction") == 0)
    {
        result = leftOperand - rightOperand;
    }
    else if (strcmp(operation, "multiplication") == 0)
    {
        result = leftOperand * rightOperand;
    }
    else if (strcmp(operation, "division") == 0)
    {
        if (rightOperand != 0)
        {
            result = leftOperand / rightOperand;
        }
        else
        {
            std::cout << "Invalid division by zero";
        }
    }
    else
    {
        std::cout << "Invalid operator given" << std::endl;
        return;
    }
    std::cout << "The result of the expression is " << result << std::endl;
}

void Average(int argc, char** argv)
{
    std::cout << "The average of ";
    double sum = 0;
    for (int i = 1; i < argc; i++)
    {
        double number = atof(argv[i]);
        std::cout << number << ", ";
        sum += number;
    }
    std::cout << " is " << sum / (argc - 1) << std::endl;
}

void Sort(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Not enough parameters" << std::endl;
        return;
    }
    int numbersCount = argc - 1; // argc - 1 because first argument is exe name
    int* numbers = new int[numbersCount];
    for (int i = 0; i < numbersCount; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }
    //
    for (int i = 0; i < numbersCount; i++)
    {
        for (int j = 0; j < numbersCount - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    //
    std::cout << "Sorted: ";
    for (int i = 0; i < numbersCount; i++)
    {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;
    delete[] numbers;
}