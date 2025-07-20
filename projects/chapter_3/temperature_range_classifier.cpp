// temperature_range_classifier.cpp
// This program classifies the temperature into different ranges.
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
    else if (temperature >= 20)
    {
        std::cout << "Warm";
    }
    else if (temperature > 10)
    {
        std::cout << "Cool";
    }
    else if (temperature >= 4)
    {
        std::cout << "Cold";
    }
    else
    {
        std::cout << "Too cold!";
    }

    return 0;
}