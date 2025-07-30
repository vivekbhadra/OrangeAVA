// stack_trace.cpp
// Demonstrates function call stack behavior in C++.
#include <iostream>
using namespace std;

void inner(int x)
{
    cout << "Inner: x = " << x << endl;
}

void outer(int y)
{
    inner(y + 1);
}

int main()
{
    outer(5);
    return 0;
}