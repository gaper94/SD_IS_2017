#include <cstring>
#include <iostream>
#include "Vector.h"
#include "CarRecord.h"

bool isDecreasingArgumentMark(const char* str)
{
    return strcmp(str, "-d") == 0;
}

bool isFilterArgumentMark(const char* str)
{
    return strcmp(str, "-filter") == 0;
}

void filterUnsigned(Vector<CarRecord>& carRecords, CarRecord::Parameter filterParameter, unsigned value)
{
    Vector<size_t> indexesToRemove;
    size_t recordsCount = carRecords.size();

    for(size_t i = 0; i < recordsCount; ++i)
    {
        if(value != carRecords[i].getUnsignedParameterValue(filterParameter))
        {
            indexesToRemove.push(i);
        }
    }

    size_t indexesToRemoveCount = indexesToRemove.size();
    for(size_t i = 0; i < indexesToRemoveCount; ++i)
    {
        carRecords.removeAt(indexesToRemove[i] - i);
    }
}

void filterString(Vector<CarRecord>& carRecords, CarRecord::Parameter filterParameter, const char* value)
{
    Vector<size_t> indexesToRemove;
    size_t recordsCount = carRecords.size();

    for(size_t i = 0; i < recordsCount; ++i)
    {
        if(strcmp(value, carRecords[i].getStringParameterValue(filterParameter)) != 0)
        {
            indexesToRemove.push(i);
        }
    }

    size_t indexesToRemoveCount = indexesToRemove.size();
    for(size_t i = 0; i < indexesToRemoveCount; ++i)
    {
        carRecords.removeAt(indexesToRemove[i] - i);
    }
}

void filterFuelConsumption(Vector<CarRecord>& carRecords, double value)
{
    Vector<size_t> indexesToRemove;
    size_t recordsCount = carRecords.size();

    for(size_t i = 0; i < recordsCount; ++i)
    {
        if(value != carRecords[i].getAverageFuelConsumption())
        {
            indexesToRemove.push(i);
        }
    }

    size_t indexesToRemoveCount = indexesToRemove.size();
    for(size_t i = 0; i < indexesToRemoveCount; ++i)
    {
        carRecords.removeAt(indexesToRemove[i] - i);
    }
}

//returns true if lhs is bigger than rhs (or smaller, if decreasing is selected)
bool compare(const CarRecord& lhs, const CarRecord& rhs, CarRecord::Parameter parameter, bool decreasing)
{
    bool isLess = false;

    if(parameter == CarRecord::PRODUCTION_YEAR || parameter == CarRecord::POWER)
    {
        unsigned lhsValue = lhs.getUnsignedParameterValue(parameter),
                 rhsValue = rhs.getUnsignedParameterValue(parameter);

        if(decreasing)
        {
            isLess = (lhsValue < rhsValue);
        }
        else
        {
            isLess = (lhsValue > rhsValue);
        }
    }
    else if(parameter == CarRecord::REGISTRATION_NUMBER || parameter == CarRecord::BRAND ||
            parameter == CarRecord::MODEL)
    {
        const char* lhsValue = lhs.getStringParameterValue(parameter),
                    *rhsValue = rhs.getStringParameterValue(parameter);

        if(decreasing)
        {
            isLess = (strcmp(lhsValue, rhsValue) < 0);
        }
        else
        {
            isLess = (strcmp(lhsValue, rhsValue) > 0);
        }
    }
    else if(parameter == CarRecord::FUEL_CONSUMPTION)
    {
        double lhsValue = lhs.getAverageFuelConsumption(), rhsValue = rhs.getAverageFuelConsumption();

        if(decreasing)
        {
            isLess = (lhsValue < rhsValue);
        }
        else
        {
            isLess = (lhsValue > rhsValue);
        }
    }

    return isLess;
}

void sort(Vector<CarRecord>& carRecords, CarRecord::Parameter parameter, bool decreasing)
{
    size_t recordsCount = carRecords.size();
    bool swapped = true;
    int j = 0;
    CarRecord temp;

    while(swapped)
    {
        swapped = false;
        j++;

        for(size_t i = 0; i < recordsCount - j; ++i)
        {
            if(compare(carRecords[i], carRecords[i + 1], parameter, decreasing))
            {
                temp = carRecords[i];
                carRecords[i] = carRecords[i + 1];
                carRecords[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

unsigned toUnsiged(const char* str)
{
    unsigned number = 0;

    size_t i = 0;
    while(str[i] != '\0')
    {
        number *= 10;
        number += str[i] - '0';

        ++i;
    }

    return number;
}

double toNonNegativeDouble(const char* str)
 {
     double integerPart = 0;
     double fractionPart = 0;
     int divisorForFraction = 1;

     bool inFraction = false;
     int currentDigit;
     while (*str != '\0')
     {
         if (*str >= '0' && *str <= '9')
         {
             currentDigit = *str - '0';
             if (inFraction)
             {
                 fractionPart = fractionPart * 10 + currentDigit;
                 divisorForFraction *= 10;
             }
             else
             {
                 integerPart = integerPart * 10 + currentDigit;
             }
         }
         else if (*str == '.')
         {
            inFraction = true;
         }

         ++str;
     }

     return integerPart + fractionPart / divisorForFraction;
 }

int main(int argc, char** argv)
{
    if((argc < 4) ||
       (argc > 5 && isDecreasingArgumentMark(argv[2]) && isFilterArgumentMark(argv[3]) && argc < 8) ||
       (argc > 4 && isFilterArgumentMark(argv[2]) && argc < 7))
    {
        std::cout << "Too fiew arguments." << std::endl;
        return 0;
    }


    std::ifstream is;
    is.open(argv[1]);

    if(!is)
    {
        std::cout << argv[1] << " : File does not extst or could not be opened." << std::endl;
        return 0;
    }

    Vector<CarRecord> carRecords;
    while(true)
    {
        CarRecord cr;
        is >> cr;
        if(is.eof())
        {
            break;
        }

        carRecords.push(cr);
    }

    is.close();

    bool sortDecreasing = false;

    char* filterParameterStr = NULL, * filterValueStr = NULL;

    if(isDecreasingArgumentMark(argv[2]))
    {
        sortDecreasing = true;

        if(isFilterArgumentMark(argv[3]))
        {
            filterParameterStr = argv[4];
            filterValueStr = argv[5];
        }
    }
    else if(isFilterArgumentMark(argv[2]))
    {
        filterParameterStr = argv[3];
        filterValueStr = argv[4];
    }

    if(filterParameterStr != NULL && filterValueStr != NULL)
    {
        CarRecord::Parameter filterParameter = CarRecord::getParaeterWithName(filterParameterStr);

        if(filterParameter == CarRecord::UNKNOWN)
        {
            std::cout << "Undefined filter parameter name passed." << std::endl;
            return 0;
        }

        if(filterParameter == CarRecord::PRODUCTION_YEAR || filterParameter == CarRecord::POWER)
        {
            unsigned value = toUnsiged(filterValueStr);
            filterUnsigned(carRecords, filterParameter, value);
        }
        else if(filterParameter == CarRecord::REGISTRATION_NUMBER || filterParameter == CarRecord::BRAND ||
                filterParameter == CarRecord::MODEL)
        {
            filterString(carRecords, filterParameter, filterValueStr);
        }
        else if(filterParameter == CarRecord::FUEL_CONSUMPTION)
        {
            double value = toNonNegativeDouble(filterParameterStr);
            filterFuelConsumption(carRecords, value);
        }
    }

    char* sortingParameterStr = argv[argc - 2];
    CarRecord::Parameter sortingParameter = CarRecord::getParaeterWithName(sortingParameterStr);

    if(sortingParameter ==  CarRecord::UNKNOWN)
    {
        std::cout << "Unknown sorting parameter passed." << std::endl;
        return 0;
    }

    sort(carRecords, sortingParameter, sortDecreasing);

    std::ofstream os;
    os.open(argv[argc - 1]);

    if(!os)
    {
        std::cout << argv[argc - 1] << " : File does not extst or could not be opened." << std::endl;
        return 0;
    }

    size_t recordsCount = carRecords.size();

    for(size_t i = 0; i < recordsCount; ++i)
    {
        os << carRecords[i];
    }

    os.close();

    return 0;
}
