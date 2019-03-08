
#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

template<typename T>
class my_is_void : public false_type {
};

template<>
struct my_is_void<void> : public true_type {

};

template<typename T>
class my_is_void_ptr : public false_type {

};

template<typename T>
class my_remove_const {
public:
    typedef  T  type;
};

template<typename T>
class my_remove_const<const T> {
public:
    typedef T type;
};

class A {
};

//template<>
//class my_is_void_ptr : public
int main() {

    cout << my_is_void<void*>::value << endl;
    cout << my_is_void<int>::value << endl;
    cout << my_is_void<double*>::value << endl;

    const int ci = 0;
    int const ic = 0;

    int temp = 20;
    int linshi;
    int *p = &temp;
    *p = 30;
    cout <<"temp change to " << temp << endl;

    const int * cip = &temp;
    cip = &linshi;
    //error: assignment of read-only location '* cip'|
    //*cip = 33;

    int * const icp = &temp;
    //error: assignment of read-only variable 'icp'|
    //icp = &linshi;
    *icp = 40;
    cout << "temp change to " << temp << endl;


    cout << "typeid(ci).name(): " << typeid(ci).name() << endl;  //i
    cout << typeid(decltype(ci)).name() << endl; //i
    cout << typeid(decltype(ic)).name() << endl;  //i
    cout << typeid(p).name() << endl;   //Pi
    cout << "typeid(cip).name(); " << typeid(cip).name() << endl;  //PKi
    cout << typeid(decltype(cip)).name() << endl; //PKi
    cout << typeid(icp).name() << endl;     //Pi

    cout << "my_is_void" << endl;
    cout << my_is_void<void>::value << endl;   //1
    cout << my_is_void<my_remove_const<const void>::type>::value << endl;   //1
    cout << my_is_void<void*>::value << endl;  //0
    cout << "-----" << endl;

    typedef my_remove_const<decltype(cip)>::type test_type;
    cout << typeid(test_type).name() << endl;

    cout << "no type meaning in const in just from name? no!!!! see error below" << endl;
    decltype(ci) b = 43;
    //error: assignment of read-only variable 'b'|
    //b = 44;
    my_remove_const<decltype(ci)>::type c = 0;
    c = 18;
    cout <<"after my remove: c is " << c << endl;

    cout << "const A -------" << endl;
    A const consta;
    cout << typeid(consta).name() << endl;    //1A
    A obja;
    cout << typeid(obja).name() << endl;        //1A
    return 0;
}
