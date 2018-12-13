#include <iostream>
using namespace std;


class Parent
{
public:
    void f() {
        cout << "Parent.f" <<endl;
    }

    virtual void g() {
        cout << "Parent.g" <<endl;
    }

    void h() {
    }

    void i() {
        cout << "Parent::i()" << endl;
    }
};

class ChildOne :public Parent
{
public:
    void f() {
        cout << "ChildOne.f" <<endl;
    }

    void g() {
        cout << "ChildOne.g" <<endl;
    }
    void h(int ) {
    }

    void i(int) {
        Parent::i();
        cout << "ChildOne::i()" <<endl;
    }
};

int main()
{

    ChildOne c = ChildOne();
    Parent *p = &c;
    p->f();
    p->g();
//    p->h(2); error: no matching function for call to 'Parent::h(int)'|
    cout << "........"<<endl;
    ChildOne *pc = &c;
    pc->f();
    pc->g();
//    c.h(); //error: no matching function for call to 'ChildOne::h()'|
    pc->i(4);
}

