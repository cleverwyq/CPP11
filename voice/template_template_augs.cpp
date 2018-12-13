
#include <iostream>

using namespace std;

template<class T>
struct A {
    struct B {};
    template<class U>
    struct C {};

    void f(T t);
};


template<>
struct A<int> {
    void f(int);
};

//template<>     ||error: template-id 'f<>' for 'void A<int>::f(int)' does not match any template declaration|
                 //template<> not used for a member of an explicitly specialized class template
void A<int>::f(int j)
{
    cout << "A<int>::f(int)"<< endl;
}

template<class T>
void A<T>::f(T t)
{
    cout <<"A<T>::f(T) " << t << endl;
}

template<>
struct A<char>::B {
    void f();
};

void A<char>::B::f() {
}

template<>
template<class U>
struct A<char>::C {
    void f();
};

template<>
template<class U>
void A<char>::C<U>::f() {
    cout << "so A::C::f()" << endl;
}

template<class T>
struct D {
    void f(int);

    template<class T2>
    void f(T2);
};

template<>
void D<double>::f(int i) {
    cout << "f(int i)" << endl;
}

template<class T>
void D<T>::f(int i) {
    cout << "f<T>(int i)" << endl;
}

template<>
template<>
void D<double>::f<int>(int i) {
    cout << "f<int> in D<double>" << endl;
}

void h()
{
    A<int> a;
    a.f(4);

    A<double> b;
    b.f(1);

    A<char>::C<int> c;
    c.f();

}

void g()
{
    D<double> d;
    d.f(4);
    D<int> d2;
    d2.f(4);

    D<double> d3;
    d3.f(4);
    D<char> d4;
    d4.f(4);
//    d4.f<>(4); undefined reference to `void D<char>::f<int>(int)'|
    d3.f<>(4);
}

class Base {
public:
    virtual void f(int i) {
        cout << "Base::f" << endl;
    }
};

class Son:public Base {
    public:
    void f(int i) {
        cout << "Son:f" <<endl;
    }

    template<class T>
//    virtual error: templates may not be 'virtual'|
    void f(T t) {
        cout << "Son<T>::f" << endl;
    }

 };

 void i() {
    Base *p = new Son();
    p->f(5);

    ((Son*)p)->template f<int>(5);
 }
int main()
{
    h();
    cout<< endl;
    g();
    cout << endl;
    i();
    return 0;
}
