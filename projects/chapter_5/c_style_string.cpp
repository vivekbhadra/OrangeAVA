// c_style_string.cpp
// This program demonstrates the use of C-style strings in C++.
// It shows how to print a C-style string using std::cout and manual traversal.
#include <iostream>

int main()
{
    char name[] = "Alice";

    std::cout << "Using std::cout: " << name << '\n';

    std::cout << "Manual traversal: ";
    for (int i = 0; name[i] != '\0'; ++i)
    {
        std::cout << name[i];
    }
    std::cout << '\n';

    return 0;
}