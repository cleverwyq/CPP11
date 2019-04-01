#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <string.h>
#include <ext/aligned_buffer.h>

using namespace std;

struct  Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes

    short s;          // 2 bytes
    short ss;
    char arr[3];
    char c;
};

struct  __attribute__((aligned)) {} a ;
struct b{} ;

union __type1
{
    char __data[35];
    decltype(a) sa;
};

union __type2
{
    char __data[50];
    decltype(a) sa;
};

union __type3
{
    char __data[50];
    b sb;
};

struct Person
{
int age;
double salary;
char cb;char cc;
int a;
char ca[9];
int b;

};
int main()
{
//	struct S1 {short f[3];};
//	struct S2 {short f[3];} __attribute__((aligned(64)));
//	struct S5 {short f[40];} __attribute__((aligned(64)));
//	fprintf(stdout, "S1 size: %d, S2 size: %d, S5 size: %d\n",
//		sizeof(struct S1), sizeof(struct S2), sizeof(struct S5)); // 6, 64, 128
//
//	typedef int more_aligned_int __attribute__((aligned(16)));
//	fprintf(stdout, "aligned: %d, %d\n", alignof(int), alignof(more_aligned_int)); // 4, 16
//
//	struct S3 {more_aligned_int f;};
//	struct S4 {int f;};
//	fprintf(stdout, "S3 size: %d, S4 size: %d\n", sizeof(struct S3), sizeof(struct S4)); // 16, 4
//
//	int arr[2] __attribute__((aligned(16))) = {1, 2};
//	fprintf(stdout, "arr size: %d, arr aligned: %d\n", sizeof(arr), alignof(arr)); // 8, 16
//
//	struct S6 {more_aligned_int f;} __attribute__((packed));
//	fprintf(stdout, "S6 size: %d\n", sizeof(struct S6)); // 4
//
//	char c __attribute__((aligned(16))) = 'a';
//	fprintf(stdout, "c size: %d, aligned: %d\n", sizeof(c), alignof(c)); // 1, 16
//
//	struct S7 {double f;} __attribute__((aligned(4)));
//	fprintf(stdout, "S7 size: %d, algined: %d\n", sizeof(struct S7), alignof(struct S7)); // 8, 8
//
//	struct S8 {double f;} __attribute__((__aligned__(32)));
//	fprintf(stdout, "S8 size: %d, algined: %d\n", sizeof(struct S8), alignof(struct S8)); // 32, 32

    cout << sizeof(a) << " is a size" << endl;    //16
    cout << sizeof(b) << " is b size" << endl;     //1
    cout << sizeof(__type1) << " is type1 size align:" << alignof(__type1) <<endl;   //48 16
    cout << sizeof(__type2) << " is type2 size align:" << alignof(__type2) << endl;   //64 16
    cout << sizeof(__type3) << " is type3 size align:" << alignof(__type3) << endl;    //50 1

    cout << endl;
    cout << sizeof(Person) << "," << alignof(Person) << endl;   //16 8
    typedef std::aligned_storage<70>::type mytype;
    cout <<sizeof(mytype) << "," << alignof(mytype) << endl;   //80 16
    cout << "name is " << typeid(mytype).name() << endl;
    typedef  __gnu_cxx::__aligned_buffer<Person> alignType;
    alignType at1;
    using atype = decltype(at1._M_storage);
    cout << "sizeof storage:" << sizeof(at1._M_storage) << ", align:" << alignof(atype)<<endl;
    cout <<"name :" << typeid(atype).name() << endl;
    cout << "sizeof Person:" << sizeof(Person) << "  align of Person:" << alignof(Person) << endl;

    Person p;
    memset((void*)&p, 0, sizeof(p));
    p.age = 24;
    p.salary = 34.567;
    p.a = 2;
    p.b = 3;
    strcpy(p.ca, "hello");
    p.cb = 'b';
    p.cc = 'c';
	return 0;
}

