#include <iostream>
#include <type_traits>

using namespace std;


class HugeMem {
public:
    HugeMem(int size):sz(size > 0? size: 1) {
     mem = new int[sz];
    }

    HugeMem(){}
    ~HugeMem() {
        delete[] mem;
    }
    HugeMem(HugeMem &&rs):sz(rs.sz), mem(rs.mem) {
        cout <<"Move Constructor in HugeMem" << endl;
        rs.mem = nullptr;
    }

    int *mem;
    int sz;
};

class Moveable {
public:

    Moveable():i(new int(3)),h(1024) {}
    ~Moveable(){delete i;}
    Moveable(Moveable &&mv):i(mv.i),h(std::move(mv.h)){
        cout <<"Move in Moveable" << endl;
        mv.i = nullptr;
    }

    HugeMem h;
    int *i;
};

Moveable GetTemp() {
    Moveable tmp = Moveable();
    cout << hex << "Huge mem from " << __func__ << " @"<< tmp.h.mem << endl;
    return tmp;
}

class A {
};

class ConvertTo{
public:
    void say() { cout <<"convert to" << endl;}
};
class Convertable {
public:
     operator ConvertTo() {
        cout << "operator ()" << endl;
    return ConvertTo();
    }

    int operator ()(int k) {
        return 20 * k;
    }
};

int main()
{
    Moveable a(GetTemp());
    cout << hex << "Huge from " << __func__ << " @" << a.h.mem << endl;
    cout << std::is_move_constructible<Moveable>::value << endl;
    cout << std::is_move_constructible<A>::value << endl;

    Convertable ctable;
    ConvertTo ct(ctable);

    cout << dec<< ctable(4) << endl;
    return 0;
}
