// function_invocation.cpp
// This program demonstrates the invocation of a function that calculates the area of a rectangle.
#include <iostream>
using namespace std;

// Function to calculate area
double calculateArea(double length, double width)
{
    return length * width;
}

int main()
{
    // Function invocation with arguments
    double area = calculateArea(5.0, 3.0);

    cout << "Area: " << area << endl;
    return 0;
}