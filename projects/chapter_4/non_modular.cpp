// non_modular.cpp
// Demonstrates a monolithic function with no logical separation.

#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "Enter a positive integer: ";
    cin >> input;

    if (input <= 0)
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    int result = input * 2;
    cout << "Processed result: " << result << endl;

    return 0;
}