// factorial.cpp
// Demonstrates recursion in C++ to compute factorial.
#include <iostream>
using namespace std;

// Function to calculate factorial recursively
unsigned long long factorial(int n)
{
    if (n <= 1)
        return 1;                // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
}

int main()
{
    int n;
    cout << "Enter a non-negative integer to compute its factorial: ";
    cin >> n;

    // Basic input validation
    if (n < 0)
    {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    unsigned long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}