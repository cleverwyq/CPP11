#include <iostream>

using namespace std;

int main() {
//    cout << sizeof (int) << endl;
//    cout << sizeof (long long) << endl;
//    int *p;
//    cout << sizeof (p) << endl;

    double ld = 4.14;
    int a = ld;
    int b = ld;
    cout << a << "," << b << endl;

    int i = 0;
    const int ci = 42;
    int j = 0;
    int* const p1 = &i;

//    error: assignment of read-only variable 'p1'|
//    p1 = &j;

    i = 30;

    cout << "i change to " << *p1 << endl;
  *p1 = 21;
  cout << "i change to " << *p1 << endl;
  *p1 = ++(*p1);

  cout << "i change to " << *p1 << endl;

    const int *p2;
    p2 = &i;
    cout <<" p2 point to " << *p2 << endl;

//    error: assignment of read-only location '* p2'|
//    *p2 = 33;

    p2 = &ci;
    cout <<"now p2 to " << *p2 << endl;

//    error: 'p2t' declared as reference but not initialized|
//    decltype(*p2) p2t;

//     error: 'refs' declared as reference but not initialized|
//     decltype((i)) refs;
     decltype(i) ivalue;
}
