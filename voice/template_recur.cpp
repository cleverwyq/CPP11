#include <iostream>

using namespace std;

template<int N>
int Fibbo();


//error: template instantiation depth exceeds maximum of 900
//(use -ftemplate-depth= to increase the maximum) substituting
//'template<int N> int Fibbo() [with int N = -1794]'|

//My comments: N==1||N==2 is nothing during compile!!!!
//template<int N>
//int Fibbo()
//{
//    if (N == 1 || N == 2)
//    {
//        return 1;
//    }
//    else if ( N <= 0)
//        return 0;
//
//    else
//        return Fibbo<N-2>() + Fibbo<N-1>();
//
//}

template<int N>
int Fibbo()
{
    return Fibbo<N-2>() + Fibbo<N-1>();
}

template<>
int Fibbo<1>()
{
    return 1;
}

template<>
int Fibbo<2>()
{
    return 2;
}

int Fibbo2(int k)
{
    if (k==1 || k == 2)
        return k;

    return Fibbo2(k-1) + Fibbo2(k-2);
}
int main()
{
        cout << Fibbo<8>() <<endl;
    for (int k = 3; k <= 7; k++)
        cout << k<< ":" << Fibbo2(k) << endl;
}
