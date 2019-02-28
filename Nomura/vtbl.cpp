
#include <iostream>
#include "string.h"

using namespace std;

template<typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type*>(static_cast<void*>(&src));
}


class A {
public:
	virtual void f() {
		cout << "A:f()" << "," << i << endl;
	}
	virtual void g() {
		cout << "A:g()" << endl;
	}
	int i = 3;
};

class B : public A {
public:
	virtual void f() {
		cout << "B:f()" << endl;
	}
};

void g() { cout << " g called" << endl; }
int main()
{
	A a;
	B b;
	cout << "a add:" << &a << endl;

	int addr = (int)(&b);
	int vtaddr = *(int*)((void*)addr);

	int vmaddr = *(int*)((void*)vtaddr);


	typedef void(A::* p2m)();
	p2m *p2m_ = reinterpret_cast<p2m*>(vtaddr);
	cout << "sizeof p2m" << " " << sizeof(p2m_) << endl;
	(a.*(*p2m_))();
	cout << hex << int(p2m_) << endl;
	p2m_ = reinterpret_cast<p2m*>(vtaddr + 4);
	(a.*(*p2m_))();

	cout << "........." << endl;

	void *p_vt = (void*)vtaddr;
	int first_vm_addr = *(int*)p_vt;

	p2m another_imple;
	cout << "sizeof p2m " << sizeof(p2m) << endl;
	memcpy((void*)&another_imple, (void*)&first_vm_addr, 4);
	(a.*another_imple)();

	int second_vm_addr = *(((int*)p_vt)+1);
	memcpy((void*)&another_imple, (void*)&second_vm_addr, 4);
	(a.*another_imple)();
	int m = 0;

	//FARPROC Func_add;
	//Func_add = GetProcAddress(LoadLibraryA("user32.dll"), "MessageBoxA");

	//*p2m_ = reinterpret_cast<p2m>(vmaddr);
	//memcpy((void*)(*(int*)(p2m_)), (void*)&vmaddr, 4);
	//(a.*(*p2m_))();

//	(a.*((p2m*)(void*)vmaddr))();

	//error C2440 : 'type cast' : cannot convert from 'void (__thiscall A::* )(void)' to 'int'
	//int addrofa_f = (int)(a.f);

	//int addrofa_f = pointer_cast<int>(&(a.f));

	typedef void(*ptr2g)();
	ptr2g p2 = g;
	cout << "g :" << p2 << "," << &g << endl;
	(*&g)();
	cout << "end g" << endl;

	typedef void (A::*ptr2m)();
	ptr2m p1 = &A::f;
	(a.*p1)();

	A a2;
	a2.i = 4;
	(a2.*p1)();

	//(a.*p1)();
	//cout << "a.f add:" << (a.*p1) << endl;


	auto trick = reinterpret_cast<void*>((&a) + 1);
	cout << &a << "," << &a + 1 << "," << trick << endl;
	//auto trick_p = reinterpret_cast<ptr2m>(trick);
	//(a.*trick_p)();
}
