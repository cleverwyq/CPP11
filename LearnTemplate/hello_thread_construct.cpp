#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <map>>


using namespace std;

map<string, string> pages;
mutex page_mutex;


void save_page(const string &url)
{
    this_thread::sleep_for(chrono::seconds(2));
    string result = "mock content";

    lock_guard<mutex> guard(page_mutex);
    pages[url] = result;
}

void f1(int n)
{
    for (int i = 0; i < 5; i++) {
            cout << "Thread 1 exe:" << endl;
            ++n;
            this_thread::sleep_for(chrono::milliseconds(20));
    }
}

void f2(int& n)
{
    for (int i = 0; i < 5; i++) {
            cout << "Thread 2 exe:" << endl;
            ++n;
            this_thread::sleep_for(chrono::milliseconds(20));
    }
}

class foo
{
public:
    void bar()
    {
        for(int i = 0; i < 5; i++) {
            cout << "thread 3 exec:" << endl;
            ++n;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
    }
    int n = 0;
};

void independentThread()
{
        cout << "Starting concurrent:\n";
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Existing concurrent:\n";

}

void mainThread()
{
        unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

    cout << "Starting main:\n";
    thread t(independentThread);
    t.detach();
    this_thread::sleep_for(chrono::seconds(2));
    cout << "End main\n";
}

void save_pages()
{
    string s[] = {"hello", "world", "foo", "bar", "now"};
    for(int i = 0; i < 5; i++) {
        thread t(save_page, s[i]);
        t.join();
    }

    for(auto &p:pages)
        cout << p.first << "->" <<p.second << endl;
}
int main()
{
//    int n = 0;
//    thread t2(f1, n + 1);
//
//
//    thread t3(f2, ref(n));
//
//
//    foo f;
//    thread t4(&foo::bar, &f);
//    t4.join();t2.join();t3.join();
//    cout << "final value of n is : " << n << endl;
//    cout << "final value of foo.n is " << f.n << endl;

    ///////////////////////////
    //mainThread();
    //this_thread::sleep_for(chrono::seconds(10));

    ///////////////////////////
    save_pages();
}
