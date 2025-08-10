// bubble_sort_ai.cpp
// This program demonstrates the bubble sort algorithm using std::array in C++.
// It sorts an array of integers in ascending order and prints the sorted array.
#include <array>
#include <iostream>

void bubbleSort(std::array<int, 5> &arr)
{
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        for (std::size_t j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    std::array<int, 5> data = {5, 3, 4, 1, 2};
    bubbleSort(data);

    for (int x : data)
    {
        std::cout << x << ' ';
    }

    return 0;
}
