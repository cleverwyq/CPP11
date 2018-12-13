#include <iostream>
#include <string>
#include <utility>

using namespace std;
void f(int& x) {
    cout << "lvalue ref f(" << x <<")" <<endl;
}

void f(const int& x){
    cout <<"lvalue ref to const f(" << x << ")" << endl;
}

void f(int&& x) {
    cout <<"rvalue ref f("<<x<<")"<<endl;
}

template<class T>
void f(T&&){}       // P is an rvalue reference to cv-unqualified T (forwarding reference)
template<class T>
void g(const T&&){} // P is an rvalue reference to cv-qualified T (not special)


int main()
{    std::string s1 = "Test";
//  std::string&& r1 = s1;           // error: can't bind to lvalue

//     std::string& r2 = s1 + s1;     //error: invalid initialization of non-const reference of type 'std::string& {aka std::basic_string<char>&}' from an rvalue of type 'std::basic_string<char>'|

    const std::string& r2 = s1 + s1; // okay: lvalue reference to const extends lifetime
//  r2 += "Test";                    // error: can't modify through reference to const

    std::string&& r3 = s1 + s1;      // okay: rvalue reference extends lifetime
    r3 += "Test";                    // okay: can modify through reference to non-const
    std::cout << r3 << '\n';

    int i = 1;
    const int ci = 2;
//    const int&& crl = ci; error: cannot bind 'const int' lvalue to 'const int&&'|
    f(i);
    f(ci);
    f(3);                  //call f(&&), if no f(&&) call f(const &), if no f(const &) error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'|
    f(move(3));
    f(move(i));
    f(move(ci));   //okay: same with f(ci);

    int &&x = 1;
    f(x);
    f(forward<int&&>(x));
    f(move(x));

//    int && y = i; error: cannot bind 'int' lvalue to 'int&&'
    int && y = move(i);
    cout << i << "," <<y <<endl;
//    int && z = ci;error: invalid initialization of reference of type 'int&&' from expression of type 'const int'|

    cout << ">>>>>>>>>>>>>>>"<< endl;
        //int i;
     f(i); // argument is lvalue: calls f<int&>(int&) (special case)
     f(0); // argument is not lvalue: calls f<int>(int&&)

     //error: cannot bind 'int' lvalue to 'const int&&'|
     //g(i); // deduces to g<int>(const int&&), which
                   // cannot bind an rvalue reference to an lvalue
}
