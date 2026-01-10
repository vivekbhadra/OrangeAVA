#include <benchmark/benchmark.h>
#include <shared_mutex>
#include <mutex>
#include <map>
#include <string>

// Global data shared across threads
std::map<std::string, int> cache = { {"alpha", 1}, {"beta", 2}, {"gamma", 3} };
std::mutex mtx;
std::shared_mutex smtx;

// --- MUTEX BENCHMARKS ---

static void BM_Mutex_Read(benchmark::State& state) {
    for (auto _ : state) {
        std::lock_guard<std::mutex> lock(mtx);
        int val = cache["alpha"];
        benchmark::DoNotOptimize(val);
    }
}
// Run this with 1, 2, 4, and 8 concurrent threads
BENCHMARK(BM_Mutex_Read)->ThreadRange(1, 8);

// --- SHARED_MUTEX BENCHMARKS ---

static void BM_SharedMutex_Read(benchmark::State& state) {
    for (auto _ : state) {
        std::shared_lock<std::shared_mutex> lock(smtx);
        int val = cache["alpha"];
        benchmark::DoNotOptimize(val);
    }
}
BENCHMARK(BM_SharedMutex_Read)->ThreadRange(1, 8);

// --- MIXED WORKLOAD (Readers + Writers) ---
// Google Benchmark allows you to define how many threads do what 
// but for a simple "Mixed" test, we can use a custom counter
static void BM_Mixed_SharedMutex(benchmark::State& state) {
    for (auto _ : state) {
        // Use parentheses for thread_index()
        if (state.thread_index() == 0) { 
            std::unique_lock<std::shared_mutex> lock(smtx);
            cache["alpha"]++;
        } else {
            std::shared_lock<std::shared_mutex> lock(smtx);
            int val = cache["alpha"];
            benchmark::DoNotOptimize(val);
        }
    }
}
BENCHMARK(BM_Mixed_SharedMutex)->Threads(4); // 1 writer (thread 0), 3 readers

BENCHMARK_MAIN();
