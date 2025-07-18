// volatile_demo.cpp
#include <chrono>
#include <iostream>
#include <thread>
volatile bool running = true; // Assume another thread sets running = false
int main()
{
    std::cout << "System running: " << running << "\n";
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 1 second
    }
    std::cout << "System stopped: " << running << std::endl;
    return 0;
}
