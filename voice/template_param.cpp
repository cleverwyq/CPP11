#include <iostream>

using namespace std;

double gd = 2.1;
double* const gpd = &gd ; //new double(4.6);

template<double *pd = &gd>
class show
{
public:
    void print() {
//        &pd;  error: lvalue required as unary '&' operand|
        cout << *pd <<endl;
        cout << "" <<endl;
    }
};

template<double& rd>
class Z
{
public:
    void print() {
        &rd;
        cout << rd << endl;
        rd ++;
    }

};

//i is prvalue !!!
template<class T, int i>
void func1() {
    T t;
//    i++; error: increment of read-only location 'i' , error: lvalue required as incrment operand
//    &i; error: lvalue required as unary '&' operand|
//    int &ri = i; //error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'|

}

template<class...T, class U>
void func2()
{

}

int main()
{
    const int t1 = 4;
    func1<int, t1>();

//    func2<int, int>(); note:   template argument reduction/substitution failed, couldn't deduce template parameter 'U'|

    gd = 2.2;
    show<&gd> s;
    s.print();
    gd = 2.3;
    show<> p;
    p.print();

    Z<gd> z;
    z.print();
    z.print();

//    Z<*gpd> z1;
    return 0;
}
