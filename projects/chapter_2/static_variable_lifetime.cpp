// static_variable_lifetime.cpp
#include <iostream>
void testStatic()
{
    static int counter = 0;
    counter++;
    std::cout << counter << std::endl;
}
int main()
{
    testStatic(); // Outputs 1
    testStatic(); // Outputs 2
    return 0;
}