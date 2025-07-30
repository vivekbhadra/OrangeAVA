// unit_converter_with_recursive.cpp
// This program provides a menu for converting between different units, including a recursive conversion option.
#include <iostream>
using namespace std;

// Function declarations for unit conversions
double kmToMiles(double km)
{
    return km * 0.621371;
}

double milesToKm(double miles)
{
    return miles * 1.60934;
}

double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToFahrenheitRecursive(double celsius)
{
    if (celsius == 0)
        return 32;                                                // Base case: 0°C = 32°F
    return celsiusToFahrenheitRecursive(celsius - 1) + 9.0 / 5.0; // Recursive step
}

void displayMenu()
{
    cout << "\nUnit Converter Menu:\n";
    cout << "1. Kilometers to Miles\n";
    cout << "2. Miles to Kilometers\n";
    cout << "3. Celsius to Fahrenheit (Iterative)\n";
    cout << "4. Fahrenheit to Celsius\n";
    cout << "5. Celsius to Fahrenheit (Recursive)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
}

int main()
{
    int choice;
    double value;

    while (true)
    {
        displayMenu();
        cin >> choice;

        // Check for valid menu choice
        if (choice == 6)
        {
            cout << "Exiting program.\n";
            break;
        }
        if (choice < 1 || choice > 6)
        {
            cout << "Invalid choice. Please select 1-6.\n";
            continue;
        }

        // Get value to convert
        cout << "Enter the value to convert: ";
        cin >> value;

        // Validate input
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();             // Clear error state
            cin.ignore(10000, '\n'); // Discard invalid input
            continue;
        }

        // Perform conversion based on choice
        switch (choice)
        {
        case 1:
            cout << value << " km = " << kmToMiles(value) << " miles\n";
            break;
        case 2:
            cout << value << " miles = " << milesToKm(value) << " km\n";
            break;
        case 3:
            cout << value << " Celsius = " << celsiusToFahrenheit(value) << " Fahrenheit\n";
            break;
        case 4:
            cout << value << " Fahrenheit = " << fahrenheitToCelsius(value) << " Celsius\n";
            break;
        case 5:
            cout << value << " Celsius = " << celsiusToFahrenheitRecursive(value) << " Fahrenheit (recursive)\n";
            break;
        }
    }

    return 0;
}