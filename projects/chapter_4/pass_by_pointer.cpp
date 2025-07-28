// pass_by_pointer.cpp
// This program demonstrates the concept of pass by pointer in C++.
#include <iostream>

void increment(int *x)
{
    (*x)++; // Increment the value pointed to by x
}

int main()
{
    int c = 5;
    increment(&c);
    std::cout << "Value of c after calling increment(): " << c << "\n";
    return 0;
}