#include <iostream>

class Base
{
public:
    int f(int i){
        return 9;
    }
};

class D:public Base
{
public:
    using Base::f;
    int f(double d) {
        return 10;
    }
};

class DeleConstructor
{
public:
    DeleConstructor(){
    }

    //error: mem-initializer for 'DeleConstructor::i' follows constructor delegation
//    DeleConstructor(int j):DeleConstructor(),i(j) {
//    }
private:
    int i = 20;
};

constexpr getConst(int x)
{
//    error: body of constexpr function 'constexpr int getConst(int)' not a return-statement|
//        int m = 4;
        return x > 3 ?x * 2 : x;
}

int main()
{
    int k;
    std::cin>>k;
      int j = 5;
      if ( k < 3) j = 2;
    int arr[getConst(j)];
    using namespace std;
    cout <<"size:"<<sizeof(arr)/sizeof(arr[0])<<endl;
    D d;
    std::cout<<d.f(4)<<std::endl;
    int *p = new int(40);
    using namespace std;
    cout<<*p<<endl;
    int *q = new int[40];
    cout<<*q<<endl;
    return 0;
}
