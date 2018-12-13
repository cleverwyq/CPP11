#include <iostream>

using namespace std;

bool isTrue(int a)
{
    return true;
}

typedef bool (*func_ptr)(int);
typedef bool (&func_ref)(int);

struct FTCharArrayTester
{
	template <uint32 N>
	static char (&Func(const TCHAR(&)[N]))[2];   //C++11 can not compile
	static char (&Func(...))[1];
};

int main()
{
    func_ptr a = isTrue;
    if (a(2))
        cout << "Hello world!" << endl;

    func_ref b = isTrue;
    if (b(4))
        cout<<"Ref works"<<endl;
    return 0;
}
