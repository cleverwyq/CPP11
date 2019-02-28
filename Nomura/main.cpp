#include <iostream>

using namespace std;

template<class T>
void func() noexcept(noexcept(T())){
    cout << noexcept(T()) << endl;
    cout << "Call func in " << __func__ << endl;
    throw 2;
}

class A {
public :
    A() noexcept {}
};

class B {
public :
    B()  { throw 1;}
};
int main()
{
    cout << "Hello world!" << endl;
    try {
        func<B>();
    }
    catch(...) {
        cout << "exp caught from B" << endl;
    }

    cout << "again" << endl;
    try {
        func<A>();
    }
    catch(...) {
        cout << "exp from A caught" << endl;
    }

    return 0;
}
