// string_literal_storage.cpp
// This program demonstrates the storage of string literals in C++.
// It shows how string literals are stored in the read-only section of memory.
#include <iostream>

void printGreeting()
{
    std::cout << "Inside function: "
              << "Hello, learner!" << '\n';
}

int main()
{
    std::cout << "In main: "
              << "Hello, learner!" << '\n';
    printGreeting();
    return 0;
}