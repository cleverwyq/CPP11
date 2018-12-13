#include <iostream>
#include <memory>

using namespace std;

class Browser
{
public:
    void log() {cout<<"Browser..."<<endl;}
};
int main()
{
    Browser b;
    Browser *p = &b;

    unique_ptr<Browser> uptr(p);
    uptr->log();

    shared_ptr<Browser> sptr(p);
    sptr->log();

    shared_ptr<Browser> sptr2(uptr.get());
    sptr2->log();

    if (uptr)
    {
        cout<<"go on .."<<endl;
    }

    unique_ptr<Browser> uptr2(std::move(uptr));
    if (uptr)
    {
        cout<<"go on .."<<endl;
    }
    if (uptr2)
    {
        cout<<"uptr2 go on.."<<endl;
    }

    if (sptr2) sptr2->log();

    cout << "Hello world!" << endl;
    return 0;
}
