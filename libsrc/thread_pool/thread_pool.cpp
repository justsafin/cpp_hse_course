#include "thread_pool/thread_pool.hpp"

ThreadPool::ThreadPool(uint32_t num_threads) {
    low_watermark = num_threads;
    high_watermark = num_threads;
    std::cout << "Creating tp " << low_watermark << high_watermark << std::endl;

    for (uint32_t i = 0; i < high_watermark; ++i) {
        auto new_thread = std::thread(&ThreadPool::run, this);
        std::cout << "[THREAD POOL] WORKER THREAD " << new_thread.get_id() << " CREATED" << std::endl;
        threads[new_thread.get_id()] = (std::move(new_thread));
    }
};

ThreadPool::ThreadPool(uint32_t min_threads, uint32_t max_threads) {
    low_watermark = min_threads;
    high_watermark = max_threads;

    for (uint32_t i = 0; i < low_watermark; ++i) {
        auto new_thread = std::thread(&ThreadPool::run, this);
        std::cout << "[THREAD POOL] WORKER THREAD " << new_thread.get_id() << " CREATED" << std::endl;
        threads[new_thread.get_id()] = (std::move(new_thread));
    }
};

ThreadPool::~ThreadPool() {
    quite = true;
    std::cout << "Destructor Thread pool"; 
    for (auto & [thread_id, thread] : threads) {
        if (thread.joinable())
            thread.join();

        std::cout << "[THREAD POOL] WORKER THREAD " << thread_id << " FINISHED" << std::endl;
    }

};

void ThreadPool::set_max_tasks(int max_tasks) {
    _max_tasks = uint32_t(max_tasks);
}

void ThreadPool::run() {
    while (!quite) {

        auto timeout_time = std::chrono::steady_clock::now() + timeout;

        std::unique_lock<std::mutex> lock(q_mtx);
        q_cv.wait_for(lock, timeout, [this]()->bool { return !tasks_queue.empty() || quite;});

        if (std::chrono::steady_clock::now() > timeout_time) {
            std::unique_lock<std::mutex> thread_count_lock(thread_count_mtx);
            if (threads.size() > low_watermark) {
                std::thread::id timeout_thread_id = std::this_thread::get_id();

                threads[timeout_thread_id].detach();
                threads.erase(timeout_thread_id);
                std::cout << "[THREAD POOL] EXTRA WORKER THREAD " << timeout_thread_id << " STOPPED" << std::endl;
                return;
            }
        }

        if (!tasks_queue.empty()) {
            auto elem = std::move(tasks_queue.front());
            tasks_queue.pop();
            lock.unlock();

            elem.first.get();
        }
    }
};
