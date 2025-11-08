// condition_variable_notify_all.cpp
// This code demonstrates the use of std::condition_variable with notify_all in C++17.
// A producer thread prepares a task and notifies multiple consumer threads
// which wait for the task to be ready before processing it.
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::string task_message = "Process new batch of data";

void consumer(int id)
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Consumer " << id << ": waiting for the task...\n";

    // Wait until 'ready' becomes true
    cv.wait(lock, [] { return ready; });

    // Proceed once notified
    std::cout << "Consumer " << id << ": received task -> " << task_message << '\n';
}

void producer()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate task preparation
    {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        ready = true;                          // Set the flag to true
        std::cout << "Producer: task prepared, notifying all consumers.\n";
    } // Unlocks mutex here

    // Wake up all waiting consumers
    cv.notify_all();
}

int main()
{
    std::cout << "Main: Starting producer and multiple consumers.\n";

    // Launch several consumers
    std::vector<std::thread> consumers;
    for (int i = 1; i <= 3; ++i)
    {
        consumers.emplace_back(consumer, i); // emplace_back to construct in place
    }

    // Launch producer
    std::thread prod(producer);

    // Join all threads
    for (auto &t : consumers)
    {
        t.join();
    }
    prod.join();

    std::cout << "Main: All consumers have received the task.\n";
    return 0;
}
