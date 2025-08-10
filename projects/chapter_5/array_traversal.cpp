// array_traversal.cpp
// This program demonstrates how to traverse an array and print its elements using indexing in C++.
#include <iostream>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << '\n';
    }

    return 0;
}