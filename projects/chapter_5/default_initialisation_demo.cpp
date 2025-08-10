// default_initialisation_demo.cpp
// Demonstrates default initialisation of global vs local arrays

#include <iostream>

int globalArray[3]; // Default-initialised to zero (static storage)

int main()
{
    int localArray[3]; // Not initialised (automatic storage)

    std::cout << "Global array (default-initialised):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  globalArray[" << i << "] = " << globalArray[i] << "\n";
    }

    std::cout << "\nLocal array (uninitialised, contains garbage):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  localArray[" << i << "] = " << localArray[i] << "\n";
    }

    return 0;
}
