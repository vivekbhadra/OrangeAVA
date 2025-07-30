// argument_order_overloading.cpp
// Demonstrates default argument mixed with overloading causes ambiguity in C++.
#include <iostream>
void print(int a, int b = 10)
{
    std::cout << "Function with (int, int) called\n";
}

void print(int a)
{
    std::cout << "Function with (int) called\n";
}

int main()
{
    print(10); // ambiguous call, could be print(int) or print(int, int)
    print(5, 3);
    return 0;
}