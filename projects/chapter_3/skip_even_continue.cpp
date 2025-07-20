// skip_even_continue.cpp
// This program prints odd numbers between 1 and 10.
#include <iostream>
int main()
{
    std::cout << "Odd numbers between 1 and 10:\n";
    for (int i = 1; i <= 10; ++i)
    {
        if (i % 2 == 0)
        {
            continue; // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}