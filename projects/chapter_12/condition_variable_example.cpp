// condition_variable_example.cpp
// This code demonstrates the use of std::condition_variable in C++17.
// A producer thread prepares data and notifies a consumer thread
// which waits for the data to be ready before processing it.
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex mtx;             // Mutex for synchronizing access
std::condition_variable cv; // Condition variable for notification
bool ready = false;         // data availability flag
std::string message;        // Shared data

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        message = "Data prepared by producer"; // data populated by producer
        ready = true;
        std::cout << "Producer: message prepared.\n";
    }                // Unlocks mutex here
    cv.notify_one(); // Notify one waiting thread
                     // or cv.notify_all() to wake all waiting threads
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx); // we need more controlle over the lock
                                            // hence std::unique_lock, not std::lock_guard
    cv.wait(lock, [] { return ready; });    // Wait until ready becomes true
    std::cout << "Consumer: received -> " << message << '\n';
}

int main()
{
    std::thread t1(consumer); // Start consumer thread first
    std::thread t2(producer); // Then start producer thread

    t1.join(); // Wait for consumer to finish
    t2.join(); // Wait for producer to finish

    return 0;
}
