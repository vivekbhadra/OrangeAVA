// std_array_example.cpp
// This program demonstrates the use of std::array in C++.
// It shows how to create, initialize, and access elements in a std::array.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << "Elements in std::array: ";
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << '\n';

    return 0;
}