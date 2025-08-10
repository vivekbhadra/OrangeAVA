// vector_size_vs_capacity.cpp
// This program demonstrates the difference between size and capacity of a vector
// in C++. It shows how to reserve memory, add elements, and observe changes in size and capacity.
#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> data = {1, 2, 3};

    std::cout << "Valid access:\n";
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        std::cout << "data[" << i << "] = " << data[i] << '\n';
    }

    std::cout << "\nAttempting out-of-bounds access:\n";
    int x = data[5];                        // Undefined behaviour: index 5 is out of bounds
    std::cout << "data[5] = " << x << '\n'; // This line may print garbage or crash

    return 0;
}
