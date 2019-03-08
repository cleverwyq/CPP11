#include <iostream>
#include <type_traits>

using namespace std;

class TA {
public:
    void tell() {
        cout << "TA tell" << endl;
    }
};

class TB {
public:
    void tell() {
        cout << "TB tell" << endl;
    }
};

class TaValue {
public:
    const static int value = 2;

};

class TaValue0 {
public:
    const static int value = 0;

};

class TbValue {
public:
    //error: 'constexpr' needed for in-class initialization of static data member 'const double TbValue::value' of non-integral type [-fpermissive]|
    //static const double value = 3.456;
    const static int value;
};

int const TaValue::value;
const int TbValue::value =3;


int main() {
    conditional<1==2, TA, TB>::type a;
    a.tell();

    //error: the value of 'ia' is not usable in a constant expression|
    //int ia = 4;
    //conditional<ia == 3, TB, TA>::type b;

    //error: 'value' is not a member of 'TA'|
    //__or_<TA, TB> aorb;

    __or_<TaValue, TbValue> aorb;
    cout << "or 1->" <<  aorb.value << endl;   //2

    __and_<TaValue, TbValue> aandb;
    cout << aandb.value <<endl;   //3

    __and_<TaValue0, TbValue> aandb2;
    cout << aandb2.value << endl;  //0

    __and_<TbValue, TaValue0> aandb3;   //0
    cout << aandb3.value << endl;

    cout <<"is float -> " << is_floating_point<float>() <<endl;     //1
    cout <<"is_array -> " <<  is_array<TaValue>::value << endl;     //0
    cout <<"is_array -> " <<  is_array<TaValue[]>::value << endl;   //1
    cout <<"is_array -> " <<  is_array<TaValue[4]>::value << endl;   //1
}
