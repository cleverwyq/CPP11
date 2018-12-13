#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <functional>

using namespace std;
struct S {
    double operator()(char, int&);
    float operator()(int) { return 1.0;}
};



template<class A, class B>
class same1 {
    public:
    same1(){
        cout <<"cons A B" <<endl;
    }
     operator int() {
        return 0;
    }
};


template<class A>
class same1<A,A> {
    public:
            same1(){
        cout <<"cons A A" <<endl;
    }

     operator int() {
        return 1;
    }
};

template<class A>
A double_A(A a)
{
    return a * 2;
}

constexpr int return_int(int x)
{
    return x;
}

int main()
{
    std::result_of<S(char, int&)>::type c;
    cout << typeid(c).name()<< endl;         //d

    typedef int (*funPtr)(int);
    std::result_of<funPtr(int)>::type z;
    cout << typeid(z).name() <<endl;         //i
    cout << typeid(funPtr).name() <<endl;         //PFiiE

    int (*funPtr2)(int) = return_int;
    cout <<"func ptr use:" << (*funPtr2)(44)<<endl;; //44
    cout <<"func ptr use:" << typeid(funPtr2).name()<<endl;; //PFiiE
    int i = 0;
    cout << typeid(i).name() << endl;   //i
    cout << std::is_same<decltype(c), double>::value<<endl;
    cout << std::is_same<decltype(c), double>()<<endl;
    cout <<"self define" <<endl;
    cout << same1<int, int >()<<endl;
    cout<<"sep"<<endl;
    cout << same1<int, double>()<<endl;
    return 0;
}
