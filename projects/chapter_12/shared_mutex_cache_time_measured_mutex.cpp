// mutex_perf.cpp
#include <chrono>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <iostream>

std::mutex mtx;
std::map<std::string, int> cache = {
    { "alpha", 1 },
    { "beta", 2 },
    { "gamma", 3 }
};

constexpr int iterations = 5'000'000;
volatile int sink = 0;

void reader()
{
    for (int i = 0; i < iterations; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        sink += cache["alpha"];
    }
}

void writer()
{
    for (int i = 0; i < iterations / 10; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cache["alpha"]++;
    }
}

int main()
{
    auto start = std::chrono::steady_clock::now();

    std::thread r1(reader);
    std::thread r2(reader);
    std::thread r3(reader);
    std::thread w(writer);

    r1.join();
    r2.join();
    r3.join();
    w.join();

    auto end = std::chrono::steady_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "mutex elapsed: "
              << duration.count() << " ms\n";
}

