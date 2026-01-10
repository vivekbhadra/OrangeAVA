/**
 * @file industry_lock_benchmark.cpp
 * @brief Professional-grade performance comparison between std::mutex and std::shared_mutex.
 * * This benchmark simulates a Single-Writer / Multiple-Reader (SWMR) scenario
 * to determine the throughput advantages of shared locks in read-heavy workloads.
 */

#include <benchmark/benchmark.h>
#include <cmath>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <vector>

/**
 * @struct BenchmarkContext
 * @brief Encapsulates shared resources and ensures cache-line isolation.
 * * We use alignas(64) to prevent "False Sharing," a common benchmarking pitfall
 * where two mutexes occupy the same CPU cache line, causing artificial
 * performance degradation during multi-threaded access.
 */
struct BenchmarkContext
{
    std::map<int, double> data;

    /// @brief Mutex for exclusive access testing.
    alignas(64) std::mutex regular_mtx;

    /// @brief Shared mutex for concurrent read testing.
    alignas(64) std::shared_mutex shared_mtx;

    /**
     * @brief Pre-populates the data map.
     * Called once per benchmark to prevent measuring allocation overhead.
     */
    void setup()
    {
        if (data.empty())
        {
            for (int i = 0; i < 1000; ++i)
            {
                data[i] = std::sqrt(i);
            }
        }
    }
};

/// @brief Static global context for the benchmark threads.
static BenchmarkContext g_ctx;

/**
 * @brief Simulates a non-trivial read operation.
 * * Performs 50 trigonometric calculations. This represents "real work"
 * that happens while holding the lock.
 */
void DoHeavyRead()
{
    double total = 0;
    for (int i = 0; i < 50; ++i)
    {
        total += std::sin(g_ctx.data[i % 1000]);
    }
    benchmark::DoNotOptimize(total);
}

/**
 * @brief Simulates a data update operation.
 * * Modifies an element in the shared map to represent state changes.
 */
void DoWrite()
{
    g_ctx.data[0] += 1.1;
    benchmark::DoNotOptimize(g_ctx.data[0]);
}

/**
 * @brief Benchmark: Regular Mutex with 1 Writer and N-1 Readers.
 * * Demonstrates serialization overhead where all threads must wait in line.
 * @param state Google Benchmark state object.
 */
static void BM_RegularMutex_Mixed(benchmark::State &state)
{
    g_ctx.setup();
    for (auto _ : state)
    {
        // lock_guard is always exclusive; readers block each other.
        std::lock_guard<std::mutex> lock(g_ctx.regular_mtx);

        if (state.thread_index() == 0)
        {
            DoWrite(); // Thread 0 = Writer
        }
        else
        {
            DoHeavyRead(); // Others = Readers
        }
    }
}
// Run with 8 concurrent threads (1 Writer + 7 Readers).
BENCHMARK(BM_RegularMutex_Mixed)->Threads(8)->UseRealTime();

/**
 * @brief Benchmark: Shared Mutex with 1 Writer and N-1 Readers.
 * * Demonstrates parallel reading capabilities while maintaining write safety.
 * @param state Google Benchmark state object.
 */
static void BM_SharedMutex_Mixed(benchmark::State &state)
{
    g_ctx.setup();
    for (auto _ : state)
    {
        if (state.thread_index() == 0)
        {
            // WRITER: Requires unique/exclusive access.
            std::unique_lock<std::shared_mutex> lock(g_ctx.shared_mtx);
            DoWrite();
        }
        else
        {
            // READERS: Acquire shared access simultaneously.
            std::shared_lock<std::shared_mutex> lock(g_ctx.shared_mtx);
            DoHeavyRead();
        }
    }
}
BENCHMARK(BM_SharedMutex_Mixed)->Threads(8)->UseRealTime();

// Entry point for the benchmark suite.
BENCHMARK_MAIN();