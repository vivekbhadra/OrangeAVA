// shared_mutex_perf.cpp
#include <chrono>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <vector>
#include <iostream>

std::shared_mutex smtx;
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
        std::shared_lock<std::shared_mutex> lock(smtx);
        sink += cache["alpha"];
    }
}

void writer()
{
    for (int i = 0; i < iterations / 10; ++i)
    {
        std::unique_lock<std::shared_mutex> lock(smtx);
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

    std::cout << "shared_mutex elapsed: "
              << duration.count() << " ms\n";
}

