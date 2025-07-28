// pass_by_reference.cpp
// This program demonstrates the concept of pass by reference in C++.
#include <iostream>

void increment(int &x)
{
    std::cout << "Before increment (x): " << x << std::endl;
    x++;
    std::cout << "After increment (x): " << x << std::endl;
}

int main()
{
    int b = 5;
    increment(b);
    std::cout << "After pass by reference (b): " << b << std::endl; // Output: 6
    return 0;
}