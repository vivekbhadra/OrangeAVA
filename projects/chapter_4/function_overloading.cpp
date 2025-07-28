// function_overloading.cpp
// This program demonstrates function overloading in C++.
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << add(3, 4) << "\n";     // Calls int version: 7
    std::cout << add(3.5, 4.2) << "\n"; // Calls double version: 7.7
    return 0;
}