// stack_overflow_example.cpp
#include <iostream>
void recursiveFunction()
{
    recursiveFunction();
}
int main()
{
    recursiveFunction(); // Causes stack overflow
    return 0;
}