#include <tuple>
#include <iostream>
#include <typeinfo>

using namespace std;

class Fooo
{
public:

};

template<typename T, typename=void>
class Bar
{
public:

};

template<int N>
class TryN : private TryN<N-1>{
public:
    TryN():TryN<N-1>(), value(N){}
    int value;
    int get() {
        cout << N << "-->" << value << endl;
        TryN<N-1>::get();
        return value;
    }
};

template<>
class TryN<1> {
public:
    TryN():value(1){}
    int value;
    int get() { cout << value << endl;}
};

class TRY :public TryN<4>
{

};
int main()
{

    TRY mytry;
    mytry.get();
    cout << "sizeof TRY:" << sizeof(TRY) << endl;

    cout << typeid(tuple<int, char, double>).name() << endl;//St5tupleIIicdEE
    cout << typeid(tuple<>).name() << endl;//St5tupleIIEE
//    tuple<> zero_t = make_tuple();
//
//    tuple<int> t = make_tuple(2);
//    cout << std::get<0>(t) << endl;
//
//    tuple<int, int, int> t2 = make_tuple(1,2,3);
//    cout << get<2>(t2) << endl;

    auto t4 = make_tuple("10000", "2", "3", "4");
    cout << "sizeof t4 "<< sizeof(t4) << endl;        //16
    //error: no match for 'operator=' (operand types are 'std::tuple<const char*, const char*, const char*, const char*>'
    //and 'std::tuple<int, int>')|
    //t4 = make_tuple(1,2);

    auto t5 = make_tuple(1,2,3);

    auto t6 = tuple_cat(t4, t5);
    cout << "Done!" << endl;

    int first, second, third;
    std::tie(first, second, third) = t5;
    cout << "second is " << second << endl;

    auto ft1 = std::forward_as_tuple(2);
    cout << "forward as tuple 1 type: " << typeid(ft1).name() << endl;
    //compile error: 'type' is not a member of 'std::enable_if<false, Fooo>'|
    //cout << typeid(enable_if<1==2, Fooo>::type).name() << endl; //4Fooo

    Bar<int> b;
    Bar<int, int> bb;


    //error: wrong number of template arguments (3, should be 2)|
    //Bar<int, int, void> bbb;

    Bar<int, string> bstring;
    cout << "sizeof Bar:" << sizeof(bstring) << endl;
}
