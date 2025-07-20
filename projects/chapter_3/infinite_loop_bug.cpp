// infinite_loop_bug.cpp
// This program demonstrates an infinite loop due to a missing increment in the loop condition
#include <iostream>

int main()
{
    int i = 0;
    while (i < 5)
    {
        std::cout << i << " ";
        // Missing increment: i++ needed to reach i >= 5
    }
    return 0;
}