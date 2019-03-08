#include <iostream>
#include <type_traits>
#include <typeinfo>


using namespace std;

template<class T>
class my_is_function:public false_type {
};

template<class _Ret, class... _Args>
class my_is_function<_Ret(_Args...)>:public true_type {

};

template<class _Ret, class _Cls>
class my_is_function<_Ret _Cls::*>:public true_type {
};

class ABC {
private:
    int k;
public:
    int func() { return 2;}
    int func_with_param(int j) { return j + 1;}
    static int static_mem;
};

int ABC::static_mem = 1;

int global_func() { return 3;}

int main()
{
    //FivE
    cout << "global_func -> " << typeid(global_func).name() <<"," << typeid(decltype(global_func)).name() << endl;

    //error: type/value mismatch at argument 1 in template parameter list for 'template<class T> class my_is_function'|
    //error:   expected a type, got 'global_func'|
    //cout << my_is_function<global_func>::value << endl;

    cout << my_is_function<decltype(global_func)>::value << endl;

    //M3ABCFivE
    cout << "A::func ->" << typeid(decltype(ABC::func)).name() << endl;
    cout << "&A::func ->" << typeid(decltype(&ABC::func)).name() << endl;
    cout << my_is_function<decltype(ABC::func)>::value << endl;
    cout << my_is_function<decltype(ABC::func_with_param)>::value << endl;
    //cout << my_is_function<&A::func>::value << endl;

    cout <<"A::static -> " << my_is_function<decltype(ABC::static_mem)>::value << endl;


    cout << "others"<<endl;
    cout << __is_standard_layout(ABC) << endl;
    return 0;
}
