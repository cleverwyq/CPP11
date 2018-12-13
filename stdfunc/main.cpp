#include <iostream>
#include <functional>

using namespace std;

void printSum(int i)
{
    cout << i <<endl;
}

class Foo
{
public:
    int mem(int x)
    {
        cout << x * x <<endl;
        return x ;
    }
    void print_add(int x)
    {
        cout << x++ <<",_num "<< _num<< endl;
    }
    Foo(int num):_num(num)
    {

    }
public:
    int _num;
};

void g(void (*pf)(int), int b)
{
    (*pf)(b);
}

void g2(void (pf)(int), int b)
{
    (pf)(b);
}

class PrintSumClass
{
public:
    void operator()(int x)
    {
        cout<<"callable object :" << x <<endl;
    }
};
int main()
{
    cout << "sizeof short="<< sizeof(short)<<endl;
    int * ppp = static_cast<int*>((void*)0x000017);
    cout<< *ppp<<endl;
    function<void(int)> f_printSum = printSum;
    f_printSum(20);

    function<int(int)> f_lamba = [](int x)->int { return x*x;};
    cout<<f_lamba(30)<<endl;

    function<void(void)> f_bind = std::bind(printSum, 3);
    f_bind();
    //error: conversion from 'int (Foo::*)(int)' to non-scalar type 'std::function<int(int)>' requested|
    //function<int(int)> f_mem = &Foo::mem;

    function<int (Foo, int)> f_mem = &Foo::mem;
    Foo foo(30);
    f_mem(foo, 20);

    function<int(Foo)> f_mem_num = &Foo::_num;
    cout<<f_mem_num(foo)<<endl;

    cout<<"..."<<endl;
    function<void(int)> f_obj = bind(&Foo::print_add, foo, std::placeholders::_1);
    f_obj(3);

    Foo foo2(45);
    function<void(int)> f_obj2 = bind(&Foo::print_add, foo2, std::placeholders::_1);
    f_obj2(3);

    function<void(int)> f_call_obj = PrintSumClass();
    f_call_obj(2);

    g(printSum, 5);
    g2(printSum, 5);
    return 0;
}
