// segfault_example.cpp
// This program demonstrates a segmentation fault by accessing an out-of-bounds index in an array.
#include <iostream>

int main()
{
    int numbers[3] = {10, 20, 30};

    std::cout << "Accessing numbers[5]...\n";
    std::cout << numbers[5] << std::endl; // Undefined behaviour

    return 0;
}
