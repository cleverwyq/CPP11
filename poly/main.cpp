#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

template<class InIt, class T>
InIt findElement(InIt first, InIt last, const T& val)
{
    while(first != last)
    {
        if (*first == val)
        {
            return first;
        }
        ++first;
    }

    return first;
}

class A
{
public:
    void foo()
    {
        cout<<"1"<<endl;
    }
    virtual void fun()
    {
        cout<<"2"<<endl;
    }
};
class B : public A
{
public:
    virtual void foo()
    {
        cout<<"3"<<endl;
    }
    void fun()
    {
        cout<<"4"<<endl;
    }
};
int main(void)
{
    A a;
    B b;
    A *p = &a;
    p->foo();
    p->fun();
    p = &b;
    p->foo();
    p->fun();

    A& c = b;
    c.foo();
    c.fun();

    //B& d = a;
    //d.foo();
    //d.fun();

    vector<int> i;
    i.push_back(3);
    vector<int>::iterator it;
    it = findElement(i.begin(), i.end(), 3);
    cout<<*it<<endl;

    list<string> l;
    list<string>::iterator lit = l.begin();

    l.insert(lit, "shit");

    lit = findElement(l.begin(), l.end() , "shit");
    cout<<*lit<<endl;
    return 0;
}
