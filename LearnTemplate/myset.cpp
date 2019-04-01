#include <iostream>
#include <set>
#include <typeinfo>

using namespace std;

template<typename T>
struct myless
{
    bool operator()(const T& t1, const T& t2) {
        return t1.x + t1.y < t2.x + t2.y;
    }
};

class Udf
{
public:
    int x, y;
    int id;
    Udf(int id, int  x, int y):x(x),y(y),id(id){
    }

};
int main()
{
    set<double> dset, dset2;
    cout << &dset << ", " << &dset2 <<endl;

    auto res = dset.insert(3.1);
    res = dset.insert(4);
    res = dset.insert(2.11);
    res = dset.insert(5);
    Udf *u = new Udf(1,1,1);
    cout << "u add:" << u <<endl;


    cout << endl;
    cout << typeid(set<double>::pointer).name() << endl;   //Pd
    cout << typeid(set<int>::reference).name() << endl;     //i
    cout << typeid(set<int>::iterator).name() << endl;      //St23_Rb_tree_const_iteratorIiE

//    set<Udf, myless<Udf>> udfset;
//    Udf u1(1, 2,3);
//    Udf u2(2, 2,4);
//    Udf u3(3, 0, 1);
//    udfset.insert(u1);
//    udfset.insert(u2);
//    udfset.insert(u3);
//
//    for(auto it = udfset.begin(); it != udfset.end(); ++it)
//        cout << it->id << " ";

//    ?????
//    myless<Udf> comp;
//    set<Udf> udfset2(comp);
//    Udf u3(1, 2,3);
//    udfset2.insert(u3);

//      set<int> iset = {2,5,4};
//      for(auto it = iset.begin(); it != iset.end(); ++it)
//        cout << *it << " ";
}
