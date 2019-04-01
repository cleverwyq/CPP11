#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
class A {
public:
    template<typename T1>
    void func(T t, T1 t1) {
        cout << t.say() << ";" << t1.say() << endl;
    }

    template<typename T2>
    struct inner_template {
        void inner_say() {
            T2 t2;

            cout << "inner say:" << t2.say() <<endl;
        }

        static int si;
        typedef A value_type;
    };


};
    template<typename T>
    template<typename T2>
    int A<T>::inner_template<T2>::si = 30;


class T {
public:
    string say() {
        return "Hello From T";
    }
};

class T1:public T {
public:

    string hello() {

        return T::say();
    }

    string say() {
        return "Hello from T1";
    }
};

class T2:public T {
public:
    string say() {
        return "Hello from T2";
    }
};

enum aaa {
    x1,
    x2,
    x3 = 10,
    x4,
    x5
} x;


int main()
{
   cout << "enum  x is ->" << x << endl;         //0
   cout << typeid(decltype(x)).name() << endl;  //3aaa
   A<T> a;
   T t;
   T1 t1;
   cout << "t1.hello () ->" << t1.hello() << endl;
   a.func(t, t1);

   cout << "about inner template"<< endl;
   A<T>::template inner_template<T2>  it;
   it.inner_say();
   cout << A<T>::inner_template<T2>::si << endl;

   typedef typename A<T>:: inner_template<T2>::value_type value_type;
}
