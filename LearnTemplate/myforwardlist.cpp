#include <forward_list>
#include <iostream>
#include <string>


using namespace std;

class A {
public:
    int *get1() {return 0;}
    int *get2() {return 0;}
    int *get3() {return 0;}
    char a[3];
};


int main()
{
    //3
    cout << sizeof(A) << endl;
    A a1, a2;
    cout <<hex << (int)&a2 <<"-"<< (int)&a1 << endl;

    forward_list<string> fl;
    fl = {"Hello", "from", "Young"};

    //4,4,4
    cout <<sizeof(typename
	std::aligned_storage<sizeof(string), std::alignment_of<string>::value>::type)<<","<< sizeof(string)<<"," << alignof(string)<<endl;
    auto it = fl.begin();
    fl.insert_after(it, "Emily");

    it = fl.begin();
    it = std::next(it, 2);
    for(auto it = fl.begin(); it != fl.end(); it++ ) {

        cout << *it << endl;
    }
    cout << sizeof(typename forward_list<string>::iterator::_Node)<<endl;
}
