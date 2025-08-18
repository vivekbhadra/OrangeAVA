#include <iostream>
#include <string>
// fist_class_design.cpp
// This file demonstrates a simple class design in C++.

// Class definition for Animal
class Animal
{
  private: // Properties are private to enforce encapsulation
    std::string colour;
    std::string habitat;

  public:
    // Setter methods
    void setColour(const std::string &c)
    {
        colour = c;
    }

    void setHabitat(const std::string &h)
    {
        habitat = h;
    }

    // Getter methods (behaviours using properties)
    void showColour() const
    {
        std::cout << "This animal's colour is " << colour << ".\n";
    }

    void showHabitat() const
    {
        std::cout << "This animal lives in " << habitat << ".\n";
    }
}; // Semicolon ends the class declaration