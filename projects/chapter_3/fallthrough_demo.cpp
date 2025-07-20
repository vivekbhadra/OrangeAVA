// fallthrough_demo.cpp
// Demonstrates what happens when break statements are missing in a switch-case
// This program is designed to illustrate the fallthrough behavior in switch statements.

#include <iostream>

int main()
{
    int option = 2;

    std::cout << "Option selected: " << option << "\n";

    switch (option)
    {
    case 1:
        std::cout << "Case 1: One\n";
    case 2:
        std::cout << "Case 2: Two\n";
    case 3:
        std::cout << "Case 3: Three\n";
    }

    return 0;
}
