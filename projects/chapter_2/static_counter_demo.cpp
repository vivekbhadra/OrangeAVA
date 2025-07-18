// static_counter_demo.cpp
#include <iostream>

// Function with a static local variable
void counter()
{
    static int count = 0; // This retains its value between calls
    count++;
    std::cout << "Counter: " << count << std::endl;
}

int main()
{
    counter(); // Output: Counter: 1
    counter(); // Output: Counter: 2
    counter(); // Output: Counter: 3
    return 0;
}
