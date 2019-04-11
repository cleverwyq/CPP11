#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <mutex>


using namespace std;

condition_variable cv;
mutex mtx;
void job()
{
   unique_lock<mutex> lk(mtx);
   cv.wait(lk);
}

int main()
{
    thread t(job);
    t.join();

}
