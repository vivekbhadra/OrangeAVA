// safe_access_with_at.cpp
// This program demonstrates the use of the at() method in std::array
// to safely access elements and handle out-of-bounds access.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {10, 20, 30};

    std::cout << "Accessing valid indices with .at():\n";
    std::cout << "data.at(0) = " << data.at(0) << '\n';
    std::cout << "data.at(2) = " << data.at(2) << '\n';

    // std::cout << data.at(5); // Uncommenting this line will crash the program at runtime

    return 0;
}
