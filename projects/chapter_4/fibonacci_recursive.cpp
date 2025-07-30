// fibonacci_recursive.cpp
// Demonstrates recursion and helps trace execution for debugging.

#include <iostream>
using namespace std;

// Recursive function to compute the nth Fibonacci number
unsigned long long fibonacci(int n)
{
    if (n <= 1)
        return n;                               // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main()
{
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Error: Fibonacci not defined for negative numbers." << endl;
        return 1;
    }

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}