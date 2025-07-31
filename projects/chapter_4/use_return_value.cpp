// use_return_value.cpp
#include <iostream>

// Computes the square of a number if the input is non-negative.
// Returns -1 to indicate failure for invalid (negative) input.
int safeSquare(int x)
{
    if (x < 0)
    {
        return -1; // Invalid input
    }
    return x * x;
}

int main()
{
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    int result = safeSquare(number);

    if (result == -1)
    {
        std::cerr << "Error: Cannot square a negative number.\n";
        return 1;
    }

    std::cout << "Square of " << number << " is: " << result << "\n";
    return 0;
}