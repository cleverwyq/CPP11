#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <functional>


using namespace std;

int f(int x, int y) { return std::pow(x, y);}

void bind_task()
{
    packaged_task<int(int, int)> task(f); //std::bind(f, 2, 11));
    future<int> fu = task.get_future();
    task(2, 11);

    cout << "result of bind_task " << fu.get() << endl;

}

void bind_lambda()
{
    packaged_task<int(int, int)> task([](int x, int y){return std::pow(x, y);});
    future<int> fu = task.get_future();
    task(2, 10);

    cout << "result of bind lambda "<< fu.get() << endl;
}

void task_thread()
{
    packaged_task<int(int, int)> task(f);
    future<int> fu = task.get_future();

    thread t(std::move(task), 2, 4);
    t.join();

    cout << "result of thread : " << fu.get() << endl;
}
int main()
{
    bind_task();
    //bind_lambda();
    //task_thread();
}
