// fixed_loop_counter.cpp
// This program demonstrates a fixed loop counter that prints numbers from 0 to 4
// It uses a while loop with a fixed condition to ensure it runs exactly 5 times
#include <iostream>

int main()
{
    int i = 0;
    while (i < 5)
    {
        std::cout << i << " ";
        i++; // Increment i to eventually make i < 5 false
    }
    std::cout << "\n";
    return 0;
}