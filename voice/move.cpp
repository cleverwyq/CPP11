#include <iostream>
#include <type_traits>

using namespace std;
int n_cons = 0;
int c_cons = 0;
int m_cons = 0;
int des = 0;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(1000)){
        cout << "construcotr "<<++n_cons <<endl;
    }
    HasPtrMem(const HasPtrMem &r):d(new int(*r.d)) {
        cout << "copy cons "<<++c_cons<<endl;
    }

    HasPtrMem(HasPtrMem && r):d(r.d) {
        r.d = nullptr;
        cout <<"Move cons "<<++m_cons<<endl;
    }
    ~HasPtrMem() {
        delete d;
        cout <<"Destructor " << ++des <<endl;
    }

//    HasPtrMem& operator = (const HasPtrMem& r) {
//        cout << " assign constr " << endl;
//        return *this;
//    }


    int *d;
};

HasPtrMem GetTemp()
{
    HasPtrMem a;
    cout << "resource from "<<__func__ << " "<<a.d << endl;
    return a;
}
int main()
{
    cout << "nullptr" <<endl;
//    HasPtrMem p = GetTemp();
//    cout << "resource from "<< __func__ << " "<<p.d <<endl;
    cout << "another one"<<endl;
    n_cons = m_cons = c_cons = des = 0;
    HasPtrMem&& q = GetTemp();
    cout << "exit" << endl;

    HasPtrMem a;
    cout<<"a " << a.d << endl;
    HasPtrMem b(move(a));
    cout <<"a " << a.d <<endl;
    cout <<"b " << b.d <<endl;
    cout<<std::is_move_constructible<HasPtrMem>::value<<endl;

    int *pp = nullptr;
    int *qq = new int(4);
    cout<<"..."<<endl;
    cout << (pp == qq)<<endl;
    cout << (pp != qq) << endl;
    return 0;
}
//only p
//construcotr 1
//resource from GetTemp 0x2791548
//Move cons 1
//Destructor 1
//Move cons 2
//Destructor 2
//resource from main 0x2791548
//Destructor 3

//only q
//another one
//construcotr 1
//resource from GetTemp 0x31518
//Move cons 1
//Destructor 1
//exit
//Destructor 2
