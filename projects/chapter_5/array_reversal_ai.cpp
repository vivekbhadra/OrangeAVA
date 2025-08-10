// array_reversal_ai.cpp
// This program demonstrates how to reverse an array using std::reverse from the C++ Standard Library.
// It uses std::array for fixed-size arrays and prints the reversed array.
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> data = {1, 2, 3, 4, 5};
    std::reverse(data.begin(), data.end());

    for (int x : data)
    {
        std::cout << x << ' ';
    }

    return 0;
}