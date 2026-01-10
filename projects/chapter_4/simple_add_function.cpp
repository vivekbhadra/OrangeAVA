// simple_add_function.cpp
// This program defines a simple addition function and uses it in main.
#include <iostream>

// Function definition
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int result = add(5, 3);
    std::cout << "Result: " << result << "\n";
    return 0;
}
