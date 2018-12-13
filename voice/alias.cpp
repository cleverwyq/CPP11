#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
//#include <stdlib.h>

using namespace std;

template<class T>
using myv = std::vector<T>;

template<class T>
void f1(T& i) {
        cout << typeid(T).name()<<endl;
}

void f2(const int&){
}
template<unsigned N, unsigned M>
int compare(const char (&p)[N], const char (&q)[M])
{
    std::cout << N << std::endl;
    return strcmp(p, q);
}
int main()
{
    myv<int> v;
    compare("hi", "young");

    int i = 0;
    const int& cir = 5;
    cout << "ref to const 5 directly !"<< endl;
    const int ci = 0;
    f1(i);
    f1(ci);
//    f1(5); error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'|
    f2(5);
    cout <<"const int:" << typeid(ci).name()<<endl;
    cout <<"const int:" << typeid(const int&).name()<<endl;
    return 0;
}
