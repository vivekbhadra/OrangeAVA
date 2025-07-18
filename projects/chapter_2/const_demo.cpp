// const_demo.cpp
#include <iostream>

int main()
{
    const float PI = 3.14159f;

    std::cout << "Value of PI (const): " << PI << std::endl;

    // Uncommenting the following line will cause a compile-time error:
    // PI = 3.14f; // Error: assignment of read-only variable 'PI'

    return 0;
}