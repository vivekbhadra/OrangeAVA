// Create a switch menu for 3 user options with break and default
#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "Welcome to the Menu!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Option One" << endl;
    cout << "2. Option Two" << endl;
    cout << "3. Option Three" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You selected Option One." << endl;
        break;
    case 2:
        cout << "You selected Option Two." << endl;
        break;
    case 3:
        cout << "You selected Option Three." << endl;
        break;
    default:
        cout << "Invalid choice! Please select a valid option." << endl;
        break;
    }

    return 0;
}
