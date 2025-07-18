// linking_error_demo.cpp
#include <iostream>
extern void undefined_function(); // Declared, not defined
int main()
{
    undefined_function();
    return 0;
}