#include <iostream>
#include <typeinfo>

using namespace std;

template<class T>
struct A {
    void f(int) {cout <<"f(int"<<endl;}
    template<class U>
    void f(U) { cout <<"f(U)"<<endl;}
};

template<class T>
void f(T t)
{
    A<T> a;
    a.f(4);
    a.f(a);

    a.f(t);
    a.f<>(t);
    a.template f<>(t);
}

template<class T>
struct B {
    template<class T2>
    struct C {
        C() {
            cout << "C constructor" << endl;
        }
    };

    B() {
        cout << "B constructor" << endl;
    }
};

template<class T, template<class X> class TT = T::template C>
struct D{
        D() {
        cout << "D constructor" << endl;
        cout << typeid(T).name()<<endl;
        }


    TT<T> t;

    T t1;
};

int main()
{
    A<float> a;
    f(a);

    D<B<int>> db;
    return 0;
}
