// short_circuit_simple.cpp
// Demonstrates short-circuit evaluation with && and ||

#include <iostream>

/* NEW: helper function added to make evaluation visible */
bool logCheck(const char* message)
{
    std::cout << message << '\n';
    return true;
}

int main()
{
    int a = 5;
    int b = 1;

    std::cout << "--- Testing && (AND) ---\n";
    if (b != 1 && logCheck("Second condition evaluated (&&)") && a / b > 1)
    {
        std::cout << "This won't print.\n";
    }
    else
    {
        std::cout << "Second part not evaluated because first condition is false.\n";
    }

    std::cout << "\n--- Testing || (OR) ---\n";
    if (a > 0 || logCheck("Second condition evaluated (||)") || b == 1)
    {
        std::cout << "Second part skipped because the first condition is true.\n";
    }

    return 0;
}

