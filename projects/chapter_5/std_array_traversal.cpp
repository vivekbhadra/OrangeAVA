// std_array_access.cpp
// This program demonstrates how to access elements in a std::array in C++.
// It shows the use of both operator[] and .at() for element access.
// It also illustrates how to traverse the array and print its elements.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    // Accessing elements using operator[] and .at()
    std::cout << "First element (operator[]): " << numbers[0] << '\n';
    std::cout << "Third element (.at()): " << numbers.at(2) << '\n';
    std::cout << "Total number of elements: " << numbers.size() << '\n';

    // Traversing the array
    std::cout << "Array elements: ";
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}