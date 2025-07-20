// event_access_validator.cpp
// Generate a C++ program named 'Event Access Validator'
// Use logical operators to allow access if user is 21+ with ticket OR is a VIP
// Add simple input checking and comments
#include <iostream>
#include <limits>
int main()
{
    int age;
    bool hasTicket, isVIP;

    std::cout << "Enter your age: ";
    while (!(std::cin >> age) || age < 0)
    {
        std::cout << "Invalid input! Please enter a valid age: ";
        std::cin.clear();                                                   // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    std::cout << "Do you have a ticket? (1 = yes, 0 = no): ";
    while (!(std::cin >> hasTicket))
    {
        std::cout << "Invalid input! Please enter 1 for yes or 0 for no: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Are you a VIP? (1 = yes, 0 = no): ";
    while (!(std::cin >> isVIP))
    {
        std::cout << "Invalid input! Please enter 1 for yes or 0 for no: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if ((age >= 21 && hasTicket) || isVIP)
    {
        std::cout << "Access granted!\n";
    }
    else
    {
        std::cout << "Access denied!\n";
    }

    return 0;
}