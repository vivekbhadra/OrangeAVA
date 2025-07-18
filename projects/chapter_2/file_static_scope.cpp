// file_static_scope.cpp
#include <iostream>

// This variable is only visible within this file
static int internalVar = 10;

void showInternal()
{
    std::cout << "Internal variable value: " << internalVar << std::endl;
}

int main()
{
    showInternal();
    return 0;
}