// menu_switch_example.cpp
// This program demonstrates the use of a switch statement to handle menu options.
#include <iostream>

int main()
{
    int choice;
    std::cout << "Menu: 1) Play  2) Settings  3) Exit\nEnter choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Starting game...\n";
        break;
    case 2:
        std::cout << "Opening settings...\n";
        break;
    case 3:
        std::cout << "Exiting...\n";
        break;
    default:
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
