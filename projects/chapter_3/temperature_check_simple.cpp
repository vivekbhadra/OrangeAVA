// temperature_check_simple.cpp
// This program checks if the entered temperature is above 30 degrees Celsius.
#include <iostream>
int main()
{
    int temperature;
    std::cout << "Enter temperature (°C): ";
    std::cin >> temperature;

    if (temperature > 30)
    {
        std::cout << "Hot";
    }
    else
    {
        std::cout << "Not hot";
    }
    return 0;
}