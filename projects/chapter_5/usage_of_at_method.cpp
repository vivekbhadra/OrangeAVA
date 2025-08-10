// usage_of_at_method.cpp
// This program demonstrates the use of the at() method in std::array
// to safely access elements and handle out-of-bounds access.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {10, 20, 30};

    try
    {
        std::cout << "Accessing data.at(5): ";
        std::cout << data.at(5) << '\n'; // Throws std::out_of_range
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return 0;
}
