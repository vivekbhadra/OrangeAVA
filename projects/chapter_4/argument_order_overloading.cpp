// argument_order_overloading.cpp
// Demonstrates how type, number, and order of arguments affect function overloading in C++.

#include <iostream>

void display(int a)
{
    std::cout << "Function with (int) called\n";
}

void display(double a)
{
    std::cout << "Function with (double) called\n";
}

void display(int a, double b)
{
    std::cout << "Function with (int, double) called\n";
}

void display(double a, int b)
{
    std::cout << "Function with (double, int) called\n";
}

int main()
{
    display(10);      // Calls: display(int)
    display(5.4);     // Calls: display(double)
    display(5, 3.14); // Calls: display(int, double)
    display(3.14, 5); // Calls: display(double, int)

    return 0;
}