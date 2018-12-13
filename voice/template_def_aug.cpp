#include <iostream>

using namespace std;

template<template <class TT = float> class T>
struct A {
    inline void f();
    inline void g() {
        T<> t;
    }
    inline void h();
};

template<template <class TT> class T>
void A<T>::f()
{
//    T<> t; error: wrong number of template arguments (0, should be 1)|
    T<char> t1;  //OK
}

template<template <class TT=int> class T>
void A<T>::h()
{
    T<> t;
}

struct X {
template<size_t i>
X * alloc() {cout<<"alloc<>" << endl; return new X();}

X* alloc() { cout<< "alloc" << endl; return new X();}
template<size_t i>
static X* adjust(){ cout<<"static adjust" << endl; return new X();}

};

template<class T>
void func_to(T* t)
{
//    T* p1 = t->alloc<200>(); error: expected primary-expression before ')' token
        T* p1 = t->template alloc<200>();

        T * p2 = t->alloc();

        T* p3 = X::adjust<3>();
        p3->alloc();
}


int main()
{
    X x;
    func_to(&x);
    return 0;
}
