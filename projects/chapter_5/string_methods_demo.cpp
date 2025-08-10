// string_methods_demo.cpp
// Demonstrates common methods on std::string

#include <iostream>
#include <string>

int main()
{
    std::string sentence = "Modern C++";

    // Get the length of the string
    std::size_t len = sentence.length();
    std::cout << "Length: " << len << '\n'; // Output: 10

    // Append another string
    sentence.append(" is powerful!");
    std::cout << "After append: " << sentence << '\n'; // Output: Modern C++ is powerful!

    // Find a substring
    std::size_t pos = sentence.find("C++");
    if (pos != std::string::npos)
    {
        std::cout << "'C++' found at index: " << pos << '\n';
    }

    // Replace part of the string
    sentence.replace(7, 3, "C++20");
    std::cout << "After replace: " << sentence << '\n'; // Output: Modern C++20 is powerful!

    // Extract a substring
    std::string sub = sentence.substr(0, 6);
    std::cout << "Substring: " << sub << '\n'; // Output: Modern

    // Clear the string
    sentence.clear();
    std::cout << "Is empty after clear? " << (sentence.empty() ? "Yes" : "No") << '\n'; // Output: Yes

    return 0;
}
