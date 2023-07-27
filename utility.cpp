#include <iostream>
#include <string>
#include <limits>

#include "utility.hpp"

bool strValidation(std::string str)
{
    if (std::cin.good())
    {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return false;
}

bool intValidation(int num, int min, int max)
{
    if (std::cin.good() && num >= min && num <= max)
    {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return false;
}
