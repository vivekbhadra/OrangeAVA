// do_while_basic_example.cpp
// This program demonstrates how a do...while loop executes at least once

#include <iostream>

int main()
{
    int number;

    do
    {
        std::cout << "Enter a number greater than 10: ";
        std::cin >> number;
    } while (number <= 10);

    std::cout << "Thank you! You entered: " << number << "\n";
    return 0;
}