// function_addition.cpp
// This program defines a function to add two integers and prints the result.
#include <iostream>

// This is a function that adds two integers and returns the result
int add(const int a, const int b)
{
    return a + b;
}

int main()
{
    const int result = add(5, 3); // Function is invoked here
    std::cout << "Sum is: " << result << std::endl;
    return 0;
}
