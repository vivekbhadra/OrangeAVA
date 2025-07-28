// default_argument.cpp
// This program demonstrates the use of default arguments in C++.
#include <iostream>

double calculateArea(double length, double width = 1.0)
{
    return length * width;
}

int main()
{
    std::cout << "Area with one argument: " << calculateArea(5.0) << "\n";       // Output: 5.0
    std::cout << "Area with two arguments: " << calculateArea(5.0, 3.0) << "\n"; // Output: 15.0
    return 0;
}