// /home/vbhadra/OrangeAVA/projects/chapter_12/ai_assisted_thread_safe_queue.cpp
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

template <typename T> class ThreadSafeQueue
{
  public:
    ThreadSafeQueue() = default;
    ThreadSafeQueue(const ThreadSafeQueue &) = delete;
    ThreadSafeQueue &operator=(const ThreadSafeQueue &) = delete;

    // Push a value into the queue (copy)
    void push(const T &value)
    {
        {
            std::lock_guard<std::mutex> lock(m_);
            q_.push(value);
        }
        cv_.notify_one();
    }

    // Push a value into the queue (move)
    void push(T &&value)
    {
        {
            std::lock_guard<std::mutex> lock(m_);
            q_.push(std::move(value));
        }
        cv_.notify_one();
    }

    // Try to pop. Returns std::optional<T> (empty if queue was empty)
    std::optional<T> try_pop()
    {
        std::lock_guard<std::mutex> lock(m_);
        if (q_.empty())
            return std::nullopt;
        T value = std::move(q_.front());
        q_.pop();
        return value;
    }

    // Blocking pop. Waits until an item is available.
    T wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [this]() { return !q_.empty(); });
        T value = std::move(q_.front());
        q_.pop();
        return value;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m_);
        return q_.empty();
    }

    size_t size() const
    {
        std::lock_guard<std::mutex> lock(m_);
        return q_.size();
    }

  private:
    mutable std::mutex m_;
    std::condition_variable cv_;
    std::queue<T> q_;
};

// Small demonstration: producer-consumer
int main()
{
    ThreadSafeQueue<int> q;

    std::thread producer(
        [&q]()
        {
            for (int i = 0; i < 10; ++i)
            {
                q.push(i);
                std::cout << "Produced: " << i << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            // no sentinel anymore; producer simply finishes
        });

    std::thread consumer(
        [&q]()
        {
            while (true)
            {
                auto opt = q.wait_and_pop_optional();
                if (!opt)
                {
                    // shutdown requested and queue empty -> exit
                    break;
                }
                std::cout << "Consumed: " << *opt << '\n';
            }
        });

    producer.join();

    // request shutdown after producer finished producing
    q.shutdown();

    consumer.join();

    return 0;
}