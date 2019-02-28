#include <memory>
#include <iostream>

using namespace std;

class A {
public:
    void tell() {cout << "tell" << endl;}
};
int main()
{
    unique_ptr<A> foo;
    if (!foo) cout << "foo is null" << endl;

    cout<<sizeof(foo)<< endl;
    int *p = 0;
    cout << sizeof(p) << endl;

    foo = unique_ptr<A>(new A);
    if (foo) foo->tell();

    unique_ptr<A> bar;

    //error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=
    //(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'|
    //bar = foo;

    //error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
    //[with _Tp = A; _Dp = std::default_delete<A>]'|
    //unique_ptr<A> tmp(foo);

    bar = move(foo);
    if (!foo) cout << "foo is n ull now" << endl;
    bar->tell();

    bar.get()->tell();

    A *pa = bar.release();
    if(!bar) cout << "bar is null after release" << endl;
    pa->tell();

    unique_ptr<A> zoo(pa);
    cout <<"zoo" << endl;
    zoo->tell();
    zoo.release();
    unique_ptr<A> zoo2(pa);
    zoo2->tell();

    int cinn;
    cin >> cinn;
}
