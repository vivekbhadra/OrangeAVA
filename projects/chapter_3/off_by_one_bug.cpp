// off_by_one_bug.cpp
// This program prints numbers from 0 to 5, but it has an off-by-one error
// The loop condition should be i < 5 instead of i <= 5 to avoid printing 5
#include <iostream>

int main()
{
    for (int i = 0; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}