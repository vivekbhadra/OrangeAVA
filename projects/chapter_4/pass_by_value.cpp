// pass_by_value.cpp
// This program demonstrates the concept of pass by value in C++.
#include <iostream>
using namespace std;

void increment(int x)
{
    x++;
    cout << "Inside function (x): " << x << endl; // Shows modified copy
}

int main()
{
    int a = 5;
    increment(a);
    cout << "After pass by value (a): " << a << endl; // Output: 5
    return 0;
}