#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>

using namespace std;

void job()
{
    mutex m1, m2;
    std::lock(m1, m2);
    std::lock_guard<mutex> lg(m1, std::adopt_lock);

    cout << "hello" << endl;
}
int main()
{
    thread t(job);
    t.join();
    int k = 0;
    cout << "Done" << endl;
}
