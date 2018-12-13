#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <cassert>

//#ifndef ABC
//#error "Never use it"
//#endif // ABC

using namespace std;
int parallel_sum(const vector<int>& v)
{
    int sum = 0;
    for (auto i : v) {
        sum += i;
        cout<<"adding " << i <<endl;
    }

    return sum;
}

int main()
{
//    assert(100 < 0);
    const int n = 0;
    static_assert(n == 0, "wrong ");
    std::vector<int> v;
    for (int i = 1; i <= 100; i++)
        v.push_back(i);

    auto handle = std::async(std::launch::async, parallel_sum, v);
    int sum = parallel_sum(v);
    cout << "final sum is "<<handle.get() + sum <<endl;
    return 0;
}
