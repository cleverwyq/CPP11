#include <iostream>

using namespace std;

class A {
public:
    void tell() {
        cout << "A" << endl;
    }
};

class B: private A {
public:

    void tell2() {
        tell();
    }
//    using A::tell;
//    void tell() {
//        cout<< "B" << endl;
//    }
};

class HasPtrMem {
public:
    HasPtrMem(){}
    HasPtrMem(HasPtrMem &h):d(new int(*h.d)){}
public:
    int *d;
};
int main() {
    cout << "Hello" << endl;

    B b;
    b.tell2();

//    A &a = b;
//    a.tell();

    int *b2 = new int(20);
    cout << b2 << "," << *b2 << endl;
    HasPtrMem m1;
    HasPtrMem m2(m1);
    cout << m1.d << "," << m2.d << endl;
    return 0;
}
