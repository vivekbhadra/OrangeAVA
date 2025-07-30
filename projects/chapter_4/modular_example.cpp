// modular_example.cpp
// Demonstrates modular decomposition using separate functions.

#include <iostream>
using namespace std;

// Gets user input
void getInput(int &value)
{
    cout << "Enter a positive integer: ";
    cin >> value;
}

// Validates the input
bool validateInput(int value)
{
    return value > 0;
}

// Processes the input (e.g., doubles the value)
int processValue(int value)
{
    return value * 2;
}

// Displays the result
void displayResult(int result)
{
    cout << "Processed result: " << result << endl;
}

int main()
{
    int input;
    getInput(input);

    if (!validateInput(input))
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    int result = processValue(input);
    displayResult(result);

    return 0;
}