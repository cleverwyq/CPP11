#include <iostream>
#include <stdlib.h>

using namespace std;

#define combine(A, B) A##B
#define WARN_IF(EXP) cout<<#EXP<<endl;
#define DECLARE_CTOR(T) T();
#define IMPLEMENT_CLASS22(TClass) cout<< (char*)#TClass + 1 <<endl;
class MyChar
{
public:
    DECLARE_CTOR(MyChar);
    int combine(my, Var);

    //int combine(int a, int b) {return a+b;}
};

int globalInt = -3;

class gclass
{
public:
    static gclass *ptr;
    static gclass *GetInstance()
    {
        if (ptr == nullptr)
            ptr = new gclass();
         return ptr;
    }

    void play (){};
private:
    gclass()
    {
        globalInt = 5;
    }
};

gclass* gclass::ptr = nullptr;


class gclass2
{
public:
    static gclass2 g;
    void play(){}
private:
    gclass2()
    {
        globalInt = 7;
    }
};

gclass2 gclass2::g;

MyChar::MyChar()
{

    combine(my, Var) = 20;
    cout<<"In ctor"<<endl;
}

int main()
{

    //gclass::GetInstance()->play();
    //gclass2::g.play();
    cout<<globalInt<<endl;

    int myVar = 20;
    cout<<combine(my, Var)<<endl;
    WARN_IF(ZERO==0 DD);

    MyChar mc;
    cout<<mc.combine(my, Var) * 2<<endl;;

    IMPLEMENT_CLASS22(AaMyChara);
    cout << "Hello world!" << endl;
    return 0;
}
