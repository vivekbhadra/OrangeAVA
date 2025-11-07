// condition_variable_example.cpp
// This code demonstrates the use of std::condition_variable in C++17.
// A producer thread prepares data and notifies a consumer thread
// which waits for the data to be ready before processing it.
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::string message;

void producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        message = "Data prepared by producer";
        ready = true;
        std::cout << "Producer: message prepared.\n";
    }
    cv.notify_one(); // Notify one waiting thread
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait until ready becomes true
    std::cout << "Consumer: received -> " << message << '\n';
}

int main()
{
    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
