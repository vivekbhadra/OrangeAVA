// type_conversions.cpp
#include <iostream>
int main()
{
    double pi = 3.14159;
    int truncated = pi; // Implicit conversion, fractional part lost
    std::cout << "Double pi = " << pi << std::endl;
    std::cout << "Truncated int = " << truncated << std::endl;
    return 0;
}