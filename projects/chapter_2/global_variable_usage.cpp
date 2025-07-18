// global_variable_usage.cpp
#include <iostream>
int globalVar = 100; // global variable
void useGlobal()
{
    std::cout << "Value of globalVar: " << globalVar << std::endl;
}
int main()
{
    useGlobal();
    return 0;
}