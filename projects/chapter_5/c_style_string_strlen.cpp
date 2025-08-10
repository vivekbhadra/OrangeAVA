// c_style_string_strlen.cpp
// This program demonstrates efficient traversal of a C-style string
// using std::strlen by storing the length beforehand.

#include <cstring> // Required for std::strlen
#include <iostream>

int main()
{
    char name[] = "Alice";

    std::size_t length = std::strlen(name); // Store length once for efficiency

    std::cout << "Using std::strlen for traversal: ";
    for (std::size_t i = 0; i < length; ++i)
    {
        std::cout << name[i];
    }
    std::cout << '\n';

    return 0;
}
