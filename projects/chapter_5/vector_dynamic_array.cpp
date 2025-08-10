// vector_dynamic_array.cpp
// Demonstrates how std::vector can be used as a dynamic array in C++
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores; // Empty vector

    // Adding elements dynamically
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(78);

    // Accessing and modifying elements
    std::cout << "First score: " << scores[0] << '\n';
    scores.at(2) = 80; // safely modifying the third score

    // Traversing using index-based loop
    std::cout << "All scores: ";
    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::cout << scores[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
