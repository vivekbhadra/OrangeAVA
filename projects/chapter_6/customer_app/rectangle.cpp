//  rectangle_member_functions.cpp
// This file demonstrates the use of member functions in a class.
// It shows how to define member functions outside the class definition.
#include "rectangle.h"

Rectangle::Rectangle(double w, double h) : width_(w), height_(h)
{
}

double Rectangle::area() const
{
    return width_ * height_;
}

double Rectangle::perimeter() const
{
    return 2.0 * (width_ + height_);
}
