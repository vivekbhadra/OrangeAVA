// number_classification.cpp
// This program classifies a number as negative, zero, or positive
#include <iostream>

#include <iostream>

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number >= 0)
    {
        if (number == 0)
        {
            std::cout << "The number is zero.\n";
        }
        else
        {
            std::cout << "The number is positive.\n";
        }
    }
    else
    {
        std::cout << "The number is negative.\n";
    }

    return 0;
}