// function_definition.cpp
// This program defines a function to calculate the area of a rectangle and prints the result.
#include <iostream>
using namespace std;

// Function definition
double calculateArea(double length, double width)
{
    return length * width;
}

int main()
{
    double l = 5.0;
    double w = 3.0;

    // Function call
    double area = calculateArea(l, w);

    cout << "Area: " << area << endl;

    return 0;
}