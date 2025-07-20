// access_control_evaluator.cpp
// This program checks whether a user is allowed access based on age and ID status.

#include <iostream>

int main()
{
    int age;
    bool hasID;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Do you have an ID? (1 = yes, 0 = no): ";
    std::cin >> hasID;

    // Access is granted if the person is 18+ and has ID, or if the person is a senior (60+)
    if ((age >= 18 && hasID) || age >= 60)
    {
        std::cout << "Access granted.\n";
    }
    else
    {
        std::cout << "Access denied.\n";
    }

    return 0;
}
