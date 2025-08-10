#include <iostream>

int main()
{
    int numbers[3] = {1, 2, 3};
    std::cout << "Accessing out of bound element:" << numbers[5] << "\n"; // This will cause undefined behavior
    return 0;
}