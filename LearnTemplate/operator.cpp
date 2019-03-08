/*
by learn

struct integral_constant

in type_traits
*/

#include <iostream>
#include <type_traits>

using namespace std;

class A {
public:
    A(int i) {
        this->i = i;
    }

    //used to convert the object itself to int
    operator int() {
        cout << "__cplusplus " << __cplusplus << endl;
        cout << "convert func" << endl;
        return i * i;
    }

    //error: 'A::operator A(int, int)' must take 'void'|
    //operator A(int i, int j) {
    //    cout << "convert from i and j" << endl;
    //    return A(i + j);
    //}

    //make the object like a function
    int operator ()(int i, int j) {
        cout << "operator ()" << endl;
        return i + j;
    }

    //make the object like a functor
    int operator ()(string name) {
        cout << "say " << name << endl;
    }

    A operator()() {
        cout << "default " << i << endl;
        A a(i);
        return a;
    }

private:
    int i;
};


int main()
{
    A a(2);
    int convertedA = a;
    cout << convertedA << endl;

    int sum = a(4, 6);
    cout << sum << endl;

    a("Young");
    int ia = a();
    typedef integral_constant<int, 4>  const4;

    cout <<"::value " << const4::value << endl;
    const4 c4;
    int converted_c4 = c4;
    cout <<"converted c4: " << converted_c4 << endl;

    //error: no match for call to '(const4 {aka std::integral_constant<int, 4>}) ()'|
    //because __cplusplus == 201103 !!!
    //int cc4 = c4();
    cout << "also c4 :" << c4 << endl;

    //error: 'class std::basic_string<char>' is not a valid type for a template non-type parameter|
    //typedef integral_constant<string, "hello"> const_string_hello;
    //cout <<"::value" << const_string_hello::value << endl;

    true_type tt;
    cout << "tt value ->" << tt << endl;
    cout << "Hello world!" << endl;
    return 0;
}
