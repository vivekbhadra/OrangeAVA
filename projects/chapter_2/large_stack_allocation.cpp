// large_stack_allocation.cpp
#include <iostream>
void createLargeArray()
{
    int data[1000000000]; // May exceed stack size
}
int main()
{
    createLargeArray(); // May cause stack overflow
    return 0;
}