// Write multiple overloaded versions of a function named 'print' in C++.
// Each version should take a different type or number of arguments.
// For example: one with int, one with double, one with two parameters (int, string), etc.
#include <iostream>
#include <string>
using namespace std;

// Overloaded function to print an integer
void print(int value)
{
    cout << "Integer: " << value << endl;
}

void print(double value)
{
    cout << "Double: " << value << endl;
}
void print(int value, const string &text)
{
    cout << "Integer: " << value << ", Text: " << text << endl;
}
void print(const string &text)
{
    cout << "Text: " << text << endl;
}
void print(char value)
{
    cout << "Character: " << value << endl;
}
void print(bool value)
{
    cout << "Boolean: " << (value ? "true" : "false") << endl;
}
int main()
{
    print(42);                 // Calls the int version
    print(3.14);               // Calls the double version
    print(100, "Hello World"); // Calls the int and string version
    print("Just a string");    // Calls the string version
    print('A');                // Calls the char version
    print(true);               // Calls the bool version

    return 0;
}
