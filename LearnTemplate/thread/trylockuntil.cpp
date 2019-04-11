#include <chrono>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;
std::timed_mutex test_mutex;

void job() {
    auto now = chrono::steady_clock::now();
        test_mutex.try_lock_until(now + std::chrono::seconds(10));
    std::cout << "hello world\n";
}

int main()
{
    std::lock_guard<std::timed_mutex> l(test_mutex);
    thread t(job);
    t.join();
}
