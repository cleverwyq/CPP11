#include <iostream>
#include <memory>

using namespace std;


template<class T1, class T2, int I>
class A
{
public:
    A() {
        cout << "Primary one "<<endl;
    }

};

template<class T, int I>
class A<T, T*,I>
{
public:
    A() {
        cout <<"Partial one" <<endl;
    }
};

int main()
{
    A<int, int, 3> a;
    A<int, int*, 5> b;
    return 0;
}
