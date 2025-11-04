// thread_detach_example.cpp
// This code demonstrates the use of detached threads in C++17.
// A background thread is launched to monitor system health
// while the main thread simulates handling client requests.
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

std::atomic<bool> running(true);

void monitor_system()
{
    while (running)
    {
        std::cout << "[Monitor] Checking system health...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "[Monitor] Shutting down cleanly.\n";
}

int main()
{
    std::cout << "Main: Starting server...\n";

    // Launch a background monitoring thread and detach it
    std::thread monitor_thread(monitor_system);
    monitor_thread.detach();

    // Simulate main server activity
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Main: Handling client request " << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }

    // Signal the monitor to stop before exiting
    running = false;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Main: Server shutting down.\n";
    return 0;
}
