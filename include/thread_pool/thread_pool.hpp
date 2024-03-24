#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>
#include <unordered_set>
#include <unordered_map>
#include <atomic>
#include <vector>

#pragma once


class ThreadPool {
public:
    ThreadPool(uint32_t num_threads);

    ThreadPool(uint32_t min_threads, uint32_t max_threads);

    void set_max_tasks(int max_tasks);

    template <typename Func, typename ...Args>
    int64_t add_task(const Func& task_func, Args&&... args) {
        if (tasks_queue.size() >= _max_tasks) {
            std:: cout << "Max tasks reached! Decline\n" << std::endl;
            return -1;
        }

        if (tasks_queue.size() > 0 && threads.size() < high_watermark) {
            std::cout << "Creating extra thread\n";
            auto new_thread = std::thread(&ThreadPool::run, this);
            std::cout << "[THREAD POOL] WORKER THREAD " << new_thread.get_id() << " CREATED" << std::endl;
            threads[new_thread.get_id()] = (std::move(new_thread));
        }

        int64_t task_idx = last_idx++;

        std::lock_guard<std::mutex> q_lock(q_mtx);
        tasks_queue.emplace(std::async(std::launch::deferred, task_func, args...), task_idx);
        q_cv.notify_one();
        return task_idx;
    }

    ~ThreadPool();

private:

    void run();

    std::queue<std::pair<std::future<void>, int64_t>> tasks_queue;
    std::mutex q_mtx;
    std::condition_variable q_cv;

    std::unordered_map<std::thread::id, std::thread> threads;

    std::atomic<bool> quite{ false };
    std::atomic<uint64_t> last_idx = 0;

    uint32_t low_watermark;
    uint32_t high_watermark;
    uint32_t _max_tasks = 1024;
    std::chrono::milliseconds timeout = std::chrono::milliseconds(2000);
    std::mutex thread_count_mtx;
    std::chrono::steady_clock::time_point last_thread_increase_time;
};