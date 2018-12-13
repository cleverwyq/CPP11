#include <iostream>

using namespace std;
int hello() throw(int)
{
    return 0;
}
int world() throw()
{
    return 0;
}

int python() noexcept
{
    cout<<"python"<<endl;
    return 0;
}

int java() noexcept
{
    cout<<"java"<<endl;
    throw 1;
    return 0;
}
int main()
{
    cout<<noexcept(hello())<<endl;
    cout<<noexcept(world())<<endl;
    cout<<noexcept(python())<<endl;
    cout<<java()<<endl;
    return 0;
}
