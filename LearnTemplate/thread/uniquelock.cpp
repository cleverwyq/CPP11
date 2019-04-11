#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>


struct Box {
    explicit Box(int num) : num_things{num} {}

    int num_things;
    std::mutex m;
};

std::once_flag flag1, flag2;

void func()
{
   std::cout << "Simple example: called once\n";
}
void simple_do_once()
{
    std::call_once(flag1, func);
}

void transfer(Box &from, Box &to, int num)
{
    std::thread::id tid = std::this_thread::get_id();
    {
        std::lock_guard<std::mutex> lg(from.m);
        std::cout << tid<< std::endl;
    }

    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);

    from.num_things -= num;
    to.num_things += num;

    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}

int main()
{
    std::thread call1(simple_do_once);
    //std::thread call2(simple_do_once);
    call1.join();
    //call2.join();


    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();

    std::cout << acc1.num_things << "," << acc2.num_things<< std::endl;
}
