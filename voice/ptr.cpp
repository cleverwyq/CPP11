#include <iostream>
#include <memory>
#include <utility>

using namespace std;
int main()
{
    unique_ptr<int> p = unique_ptr<int>(new int(8));
    std::cout << *p ;

//    unique_ptr<int> q = std::make_unique
//    cout<< *q ;
    return 0;
}
