// inline_square.cpp
// This program demonstrates an inline function in C++.

#include <iostream>

inline int square(int x)
{
    return x * x;
}

int main()
{
    std::cout << "Square of 4: " << square(4) << "\n";   // Output: 16
    std::cout << "Square of 10: " << square(10) << "\n"; // Output: 100
    return 0;
}