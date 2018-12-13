#include <iostream>

using namespace std;


class A
{
 public:
     void cfunc() const
     {
     }
     void func()
     {

     }
};
int main()
{
    cout << "Hello world!" << endl;

    int k=2, j=3;
    const int * p1 = &k;
    //*p1 = 4;
    p1 = &j;

    A a;
    const A ca;
    a.cfunc();
    ca.cfunc();
    a.func();
    //ca.func();
    return 0;
}


