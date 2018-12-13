#include <iostream>

using namespace std;

void error_msg(initializer_list<string> il)
{
    for(auto p=il.begin(); p != il.end(); p++)
    {
        cout<<*p<<"."<<endl;
    }
    cout << endl;
}

class innerclass
{
public:
    int a;
    int b;
    innerclass(int aa, int bb):a(aa), b(bb)
    {
        cout<<"cons"<<endl;
    }
};

class outerclass
{
private:
    innerclass a = innerclass(1,2);
    innerclass b{innerclass(3,4)};
    innerclass c{3,4};
};
int main()
{
    cout << "Hello world!" << endl;
    cout<< sizeof(long long)<<endl;
    long double ld = 3.1415;
    int a = {ld};
    cout<<"a=ld"<<a<<endl;

    initializer_list<string> il = {"hello", "world"};
    error_msg(il);
    error_msg({"error", "shift", "kkkkk"});
    outerclass o;
    return 0;
}
