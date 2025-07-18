// memory_explorer.cpp
#include <iostream>
int main()
{
    int i = 42;
    double d = 3.14;
    char c = 'A';
    std::cout << "Value of i: " << i << ", Address: " << &i << ", Size: " << sizeof(i) << std::endl;
    std::cout << "Value of d: " << d << ", Address: " << &d << ", Size: " << sizeof(d) << std::endl;
    std::cout << "Value of c: " << c << ", Address: " << (void *)&c << ", Size: " << sizeof(c) << std::endl;
    return 0;
}