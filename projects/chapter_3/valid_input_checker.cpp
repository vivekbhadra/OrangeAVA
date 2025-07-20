// valid_input_checker.cpp
// This program checks if the user input is a positive number
// If the input is invalid, it prompts the user to enter a valid number
#include <iostream>

int main()
{
    int number;
    std::cout << "Enter a positive number: ";
    std::cin >> number;

    while (number <= 0)
    {
        std::cout << "Invalid! Enter a positive number: ";
        if (!(std::cin >> number))
        {
            std::cout << "Not a number! Stopping.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return 1;
        }
    }

    std::cout << "You entered: " << number << "\n";
    return 0;
}