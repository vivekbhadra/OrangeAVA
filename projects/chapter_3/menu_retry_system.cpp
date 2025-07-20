// menu_retry_system.cpp
// This program implements a retry system for a menu selection
// It allows the user to retry entering a valid choice until they choose to exit
#include <iostream>

int main()
{
    int choice;
    do
    {
        std::cout << "Menu: 1) Play 2) Exit\nEnter choice: ";
        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 2)
        {
            std::cout << "Exiting...\n";
            return 0;
        }
        if (choice == 1)
        {
            std::cout << "Starting game...\n";
        }
        else
        {
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 1);
    return 0;
}