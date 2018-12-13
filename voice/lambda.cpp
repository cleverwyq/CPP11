#include <iostream>

using namespace std;

int  test_lambda(int input_i)
{
    auto f = [input_i](int lam_i)->int {
        cout<<"compare"<<endl;
        return input_i > lam_i ? input_i :lam_i;
    };

    return f(20);
}

int main()
{
    cout << test_lambda(30);
    cout << endl <<test_lambda(10);
}
