
#include <iostream>
#include "string.h"

using namespace std;

template<typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type*>(static_cast<void*>(&src));
}

template<typename dst_type,typename src_type>
dst_type union_cast(src_type src)
{
    union{
        src_type s;
        dst_type d;
    }u;
    u.s = src;
    return u.d;
}


class A {
public:
	virtual void f() {
		cout << "A:f()" << "," << i << endl;
	}
	virtual void g() {
		cout << "A:g()" << endl;
	}

    void sum(int i, int j){
        int s = i + j;
        cout << "sum of is " << s << endl;
	}
    void add(double d) {
    }
	int i = 3;
};

class B : public A {
public:
	virtual void f() {
		cout << "B:f()" << endl;
	}

	void sum(int i, int j){

	}
};

void g() { cout << " g called" << endl; }

void test_object_virtual_function_addr(const A& b) {
	int addr = (int)(&b);
	int vtaddr = *(int*)((void*)addr);

	int vmaddr = *(int*)((void*)vtaddr);

    void *p_vt = (void*)vtaddr;
	int first_vm_addr = *(int*)p_vt;
    cout << "object 's first virtual method f() address :" << hex << first_vm_addr << endl;

    int second_vm_addr = *(((int*)p_vt)+1);
    cout << "object 's second virtual method g()  address :" << hex << second_vm_addr << endl;
}

void test_object_function_addr_A(const A& a) {
    typedef void(A::* p2sum)(int i, int j);
    typedef void(A::* p2add)(double d);

    p2sum p2sum_ = &A::sum;
    p2add p2add_ = &A::add;

    cout << "p2sum of  A:" << hex << union_cast<int, p2sum>(p2sum_) << endl;
    cout << "p2add of A:" << hex << union_cast<int, p2add>(p2add_) << endl;

}

void test_object_function_addr_B(const B& b) {
    typedef void(B::* p2sum)(int i, int j);
    typedef void(B::* p2add)(double d);

    p2sum p2sum_ = &B::sum;
    p2add p2add_ = &B::add;

    cout << "p2sum of B:" << hex << union_cast<int, p2sum>(p2sum_) << endl;
    cout << "p2add of B:" << hex << union_cast<int, p2add>(p2add_) << endl;

}

int main()
{
	A a;
	B b, bb;
	cout << "a add:" << &a << " sizeof a: " << sizeof(a) << endl;
    cout << "b add: " << &b << " sizeof b: " << sizeof(b) << endl;

	test_object_virtual_function_addr(b);
	test_object_virtual_function_addr(a);
	cout <<"look below are same or not?" << endl;
	cout <<"yeah they are same in first ,not in second !!!" << endl;

    test_object_function_addr_A(a);
    test_object_function_addr_A(b);
    cout << " are below equeal ?" << endl;

    test_object_function_addr_B(b);
    cout << "add this below" << endl;

    cout << endl;

	int addr = (int)(&b);
	int vtaddr = *(int*)((void*)addr);

	int vmaddr = *(int*)((void*)vtaddr);


	typedef void(A::* p2m)();
	typedef void(A::* p2m2)(int i, int j);
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

    cout << "union cast" << endl;
    p2m third_imple = union_cast<p2m, int>(second_vm_addr);
    (b.*third_imple)();
    cout << "...end union cast .." << endl;

	//FARPROC Func_add;
	//Func_add = GetProcAddress(LoadLibraryA("user32.dll"), "MessageBoxA");

	//*p2m_ = reinterpret_cast<p2m>(vmaddr);
	//memcpy((void*)(*(int*)(p2m_)), (void*)&vmaddr, 4);
	//(a.*(*p2m_))();

//	(a.*((p2m*)(void*)vmaddr))();

	//error C2440 : 'type cast' : cannot convert from 'void (__thiscall A::* )(void)' to 'int'
	//int addrofa_f = (int)(a.f);

	//int addrofa_f = pointer_cast<int>(&(a.f));

	p2m2 p2m2_ = &A::sum;
    (a.*p2m2_)(3, 4);
}
