#include <iostream>

int main()
{
    // Copy initialisation - allows implicit narrowing
    int a = 4.2; // Allowed, but value becomes 4

    // Direct initialisation - also allows implicit narrowing
    int b(4.2); // Allowed, but value becomes 4

    // Uniform initialisation - prevents narrowing at compile time
    int c{4.2}; // Error: narrowing conversion from double to int

    int c{4}; // Valid initialisation with no narrowing

    std::cout << "Copy initialised a = " << a << std::endl;
    std::cout << "Direct initialised b = " << b << std::endl;
    std::cout << "Uniform initialised c = " << c << std::endl;

    return 0;
}