#include <iostream>
#include <list>

using namespace std;

class A {
public:
    int i = 0;
    A():i(-1) {
        cout <<"default cons" <<endl;
    }
    A(const A& rhs):i(rhs.i) {
        cout << "copy cons" << endl;
    }

    A(A&& rhs) {
        cout << "move cons" <<endl;
    }
    A& operator = (const A& rhs) {
        this->i = rhs.i;
        cout << "assign cons" << endl;
        return *this;
    }

    A& operator = (A&& rhs) {
        this->i = rhs.i;
        cout << "move assign cons" << endl;
        return *this;
    }

    ~A() {
        cout << "destroy" << endl;
    }

};

A  getObject() { A a; return a;}
int main()
{
    cout << "------0----" <<endl;
    A z;
    A y;
    y = z;  //assign
    cout << "------1-----" << endl;
    A a;
    cout << "------2-----" << endl;
    A b = a; //copy
    cout << "------3-----" << endl;
    A c(a);
    cout << "------4-----" << endl;
    A d = getObject();
    cout << "------5-----" << endl;
    A e = std::move(d);
    cout << "------6-----" << endl;
    A f;
    f = std::move(e);
    cout << "------7-----" << endl;
    return 0;
}
