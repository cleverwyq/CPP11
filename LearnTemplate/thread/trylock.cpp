#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
mutex mtx;
int page_num = 0;

void MainThread(int id)
{
    mtx.lock();
    for (int i = 0; i < 5; i ++) {
        this_thread::sleep_for(chrono::seconds(1));
        page_num ++;
        cout << "Exec thread " << id << " and num is " << page_num << endl;
    }
    mtx.unlock();
}

void SubThread(int id)
{
    this_thread::sleep_for(chrono::seconds(2));
    for (int i = 0; i < 10; i ++) {
        cout << "sub try to lock mtx "<< endl;
        bool success = mtx.try_lock();
        if (success) {
            page_num += 10;
            cout << "sub is happy and num is " << page_num << endl;
            mtx.unlock();
        }
        else {
            cout << i + 1 << "th request fail" << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));

    }
}

int main()
{
    thread t1(MainThread, 1);
    thread t2(SubThread, 2);
    t1.join();
    t2.join();
    cout << "Done !" << endl;
}
