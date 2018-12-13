#include <iostream>
#include <string>
using namespace std;


class Foo
{
public:
    Foo (int j):i(j) {}

    void MemFunc(string str)
    {
        cout << str <<endl;
        cout << i <<endl;
        cout<<"...."<<endl;
    }
private :
    int i;
};
int main()
{
    Foo f(4);
    void (Foo::*ptr)(string) = &Foo::MemFunc;

    (f.*ptr)("hello");

    Foo *g = new Foo(5);
    (g->*ptr)("world");

    //cout << "Hello world!" << endl;
    return 0;
}
