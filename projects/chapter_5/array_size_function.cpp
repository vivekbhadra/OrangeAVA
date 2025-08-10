
// array_size_function.cpp
// This program demonstrates how to use std::array and its size() function
// to traverse an array and print its elements in C++.

#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    std::cout << "The array contains " << numbers.size() << " elements.\n";

    return 0;
}
