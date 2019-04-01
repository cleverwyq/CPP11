#include <unordered_set>
#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    unordered_set<int>  uoset(1);
    auto res = uoset.insert(3);
    uoset.insert(4);
    uoset.insert(2);
    uoset.insert(13);
    uoset.insert(100);
    uoset.insert(24);
    res = uoset.insert(3);

//  bucket-size 11, the order is the bucket last to first used.
//  the same bucket is in reverse insert order.
//  24 13 2 is in same bucket
//  output:
//  100 24 13 2    4    3
    for(auto it = uoset.begin(); it != uoset.end(); ++it)
        cout << *it << endl;

    cout << endl;
    auto it = uoset.find(2);
    cout << *it << endl;

    auto hfunc = uoset.hash_function();

    //error: invalid conversion from 'const char*' to 'int' [-fpermissive]|
    //cout << hfunc("34") << endl;

    //In functional_hash.h , define default hash function.
    //St4hashIiE
    cout << typeid(hfunc).name() << endl;
}
