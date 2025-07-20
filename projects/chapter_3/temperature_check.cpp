// temperature_check.cpp
// This program checks if the entered temperature is above 30 degrees Celsius.
#include <iostream>
int main()
{
    int temperature;
    std::cout << "Enter temperature (°C): ";
    std::cin >> temperature;
    if (temperature > 30)
    {
        std::cout << "It's a hot day!\n";
    }
    return 0;
}