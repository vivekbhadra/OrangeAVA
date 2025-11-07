// async_file_checksum.cpp
// This code demonstrates asynchronous file checksum computation in C++17.
// A separate thread computes the checksum of a file while the main thread
// continues executing other tasks. The result is retrieved using std::future.
#include <chrono>
#include <fstream>
#include <future>
#include <iostream>
#include <string>
#include <thread>

// Function that simulates reading a file and computing a checksum
unsigned long compute_checksum(const std::string &filename)
{
    std::cout << "Computing checksum for " << filename << ".\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate I/O delay

    unsigned long checksum = 0;
    for (char c : filename)
    {
        checksum += static_cast<unsigned long>(c);
    }
    std::cout << "Checksum computed for " << filename << "\n";
    return checksum;
}

int main()
{
    std::cout << "Main: Launching checksum task asynchronously.\n";

    // Launch the task asynchronously
    std::future<unsigned long> result = std::async(std::launch::async, compute_checksum, "data_log.txt");

    std::cout << "Main: Performing other work while checksum is computed.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // Retrieve result (blocks if computation not yet finished)
    unsigned long checksum = result.get();
    std::cout << "Main: Final checksum value = " << checksum << "\n";

    return 0;
}