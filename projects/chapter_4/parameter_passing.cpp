// parameter_passing.cpp
// This program demonstrates different methods of parameter passing in C++.
#include <iostream>

void byValue(int x)
{
    x++;
}

void byReference(int &x)
{
    x++;
}

void byPointer(int *x)
{
    (*x)++;
}

int main()
{
    int a = 5, b = 5, c = 5;

    byValue(a);
    byReference(b);
    byPointer(&c);

    std::cout << "Value of a after passing byValue(): " << a << "\n";     // Output: 5
    std::cout << "Value of b after passing byReference(): " << b << "\n"; // Output: 6
    std::cout << "Value of c after passing byPointer(): " << c << "\n";   // Output: 6

    return 0;
}