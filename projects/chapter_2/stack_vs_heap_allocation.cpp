// stack_vs_heap_allocation.cpp
#include <iostream>

// Stack allocation: memory is automatically released when the function exits
void useStackMemory()
{
    int stackValue = 10;
    std::cout << "Stack value: " << stackValue << std::endl;
}

// Heap allocation: memory remains valid after the function returns
int *allocateHeapMemory()
{
    int *heapValue = new int(20); // Allocate on heap
    return heapValue;             // Return pointer to allocated heap memory
}

int main()
{
    useStackMemory(); // Variable created and destroyed inside the function

    int *heapPtr = allocateHeapMemory();                  // Heap memory still exists
    std::cout << "Heap value: " << *heapPtr << std::endl; // Dereference pointer to access value

    delete heapPtr;    // Clean up
    heapPtr = nullptr; // Safe practice

    return 0;
}
