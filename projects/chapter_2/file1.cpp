// file1.cpp
#include <iostream>

int sharedCount = 42; // Definition

void showSharedCount()
{
    std::cout << "Shared Count: " << sharedCount << std::endl;
}