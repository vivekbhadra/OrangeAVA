// sample_program_full_specialization.cpp
// A simple C++ program that demonstrates full specialization of a class template.
#include <iostream>
#include <string>

template <typename T> class Printer
{
  public:
    void print(const T &value)
    {
        std::cout << "Generic print: " << value << "\n";
    }
};

// Full specialization for std::string
template <> class Printer<std::string>
{
  public:
    void print(const std::string &value)
    {
        std::cout << "Specialized print for string: \"" << value << "\"\n";
    }
};

int main()
{
    Printer<int> p1;
    p1.print(42); // uses generic template

    Printer<std::string> p2;
    p2.print("Hello Templates"); // uses specialized version
}
