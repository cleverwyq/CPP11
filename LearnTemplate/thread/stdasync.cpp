#include <iostream>
#include <future>
#include <thread>

using namespace std;

int f()
{
    this_thread::sleep_for(std::chrono::seconds(5));
    cout << "long time right?\n";
    return 100;
}

int main()
{
    cout << "before async\n";
    auto handle = std::async(std::launch::async, f);
    cout << "end async\n";
    int ft = handle.get();
    cout << ft << endl;
}
