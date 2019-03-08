#include <iostream>

using namespace std;

template<class T, T t>
class my_int_const {
public:
    constexpr static T value = t;
    typedef T  value_type;
    typedef my_int_const<T, t> type;

    constexpr operator value_type()  { return value;}
};

template<class T, T t>
constexpr T my_int_const<T, t>::value;

int main() {
    typedef my_int_const<int, 3> const3;
    typedef my_int_const<int, 4> const4;
    const3 c3;

    int x = c3;
    cout << x << endl;

    constexpr int m = c3;
    cout << m << endl;

    cout <<"const3:value " << const3::value << endl;
    cout <<"const4:value " << const4::value << endl;
}
