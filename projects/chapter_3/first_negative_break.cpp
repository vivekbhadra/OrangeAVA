// first_negative_break.cpp
// This program prompts the user to enter up to 5 numbers.
// If a negative number is entered
#include <iostream>
int main()
{
    int number;
    std::cout << "Enter up to 5 numbers (stop on negative):\n";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Enter number: ";
        std::cin >> number;

        if (number < 0)
        {
            std::cout << "Negative number entered. Exiting loop.\n";
            break; // Exit the loop early
        }

        std::cout << "You entered: " << number << "\n";
    }
    return 0;
}
