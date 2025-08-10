#include <iostream>

int main()
{
    char name[] = "Alice";

    // for (int i = 0; name[i] != '\0'; ++i)
    // {
    //     std::cout << name[i] << " ";
    // }
    std::cout << sizeof(name) << std::endl; // Outputs the size of the array including the null terminator

    return 0;
};