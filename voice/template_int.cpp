#include <iostream>
using namespace std;

template<size_t... rest>
struct MaxInteger
{

};

template<size_t arg>
struct MaxInteger<arg>: public std::integral_constant<size_t, arg>
{

};

template<size_t arg1, size_t arg2, size_t... rest>
struct MaxInteger<arg1, arg2, rest...>:public std::integral_constant<size_t,
            arg1 >= arg2 ? MaxInteger<arg1, rest...>::value : MaxInteger<arg2, rest...>::value>
{

};


int main()
{
    cout << MaxInteger<4,6,7,9, 2, 1, 12>::value<<endl;
    cout << MaxInteger<4,6,5>()<<endl;

    return 0;
}
