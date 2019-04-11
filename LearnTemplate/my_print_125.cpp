#include <iostream>
#include <tuple>
using namespace std;


template<int N>
void print()
{
    print<N-1>();
    cout << N << endl;
}

template<>
void print<1>()
{
    cout << 1 << endl;
}

int main()
{
    //print<10>();

    cout << sizeof(tuple<int>)<< endl;  //4
    cout << sizeof(tuple<double>) << endl;  //8
    cout << sizeof(tuple<int, double>) << endl;  //16

    cout << sizeof(tuple<int, int>) << endl;  //8
    cout << sizeof(tuple<int, double, int, int>) << endl; //24

    cout << sizeof(tuple<string>) << ", sizeof string " << sizeof(string) << endl;  //4

    auto t4 = make_tuple("100000",20,30,"helloworld");
    cout << "done" << endl;
}
