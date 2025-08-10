#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;

    std::cout << "Initial state:\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(1);
    std::cout << "After push_back(1):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(2);
    std::cout << "After push_back(2):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(3);
    std::cout << "After push_back(3):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(4);
    std::cout << "After push_back(4):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.push_back(5);
    std::cout << "After push_back(5):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n\n";

    numbers.reserve(20);
    std::cout << "After reserve(20):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << "\n";

    return 0;
}
