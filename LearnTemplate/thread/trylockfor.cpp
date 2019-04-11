#define _GTHREAD_USE_MUTEX_TIMEDLOCK

#include <iostream>
#include <chrono>


#include <thread>
#include <mutex>
#include <vector>
#include <sstream>
using namespace std;


mutex cout_mutex;
std::timed_mutex mutex;

int job(int id) {using MS = std::chrono::milliseconds;
        std::ostringstream stream;
        for (int i = 0; i < 4; i++) {
            if (mutex.try_lock_for(MS(200))){
                stream << "success ";
                this_thread::sleep_for(MS(200));
                mutex.unlock();
            }
            else {
                stream << "fail... ";
                this_thread::sleep_for(MS(200));
            }
        }

        cout_mutex.lock();
        cout << "[" << id << "]:" << stream.str() << endl;
        cout_mutex.unlock();
}

int main()
{
    vector<thread> vt;
    for (int i = 0; i < 4; i++) {
        vt.emplace_back(job, i + 1);

    }
    for (auto& i: vt) i.join();
}
