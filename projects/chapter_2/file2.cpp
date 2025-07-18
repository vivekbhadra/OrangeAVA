// file2.cpp
#include <iostream>

// Declaration only; tells the compiler this exists elsewhere
extern int sharedCount;

void showSharedCount(); // Declaration of function defined in file1.cpp

int main()
{
    std::cout << "Accessing sharedCount from file2.cpp: " << sharedCount << std::endl;
    showSharedCount(); // Call function from file1.cpp
    return 0;
}