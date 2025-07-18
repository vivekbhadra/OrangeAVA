// local_variable_scope.cpp
#include <iostream>
void showLocal()
{
    int localVar = 42; // localVar is accessible only within this function
}
int main()
{
    showLocal(); // localVar not accessible here
    return 0;
}