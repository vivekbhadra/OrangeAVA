// array_indexing_char.cpp
// This program demonstrates how to declare a char array and access its elements using indexing in C++.
#include <iostream>

int main()
{
    // Declare and initialise a char array
    char letters[5] = {'A', 'B', 'C', 'D', 'E'};

    // Access and print each element using indexing
    std::cout << "First letter: " << letters[0] << std::endl;
    std::cout << "Second letter: " << letters[1] << std::endl;
    std::cout << "Third letter: " << letters[2] << std::endl;
    std::cout << "Fourth letter: " << letters[3] << std::endl;
    std::cout << "Fifth letter: " << letters[4] << std::endl;

    return 0;
}