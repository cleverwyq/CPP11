#include <iostream>
#include <algorithm>
#include <future>
#include <vector>
#include <numeric>
#include <mutex>
using namespace std;

mutex m;
int k = 0;
template<typename RAIter>
int my_accum(RAIter begi, RAIter endi)
{
    m.lock();
    //k++;
    //cout<<k<<"th"<<endl;
    m.unlock();

    cout<<this_thread::get_id()<<endl;
    auto len =  endi - begi;
    if (endi - begi < 1000)
        return std::accumulate(begi, endi, 0);

    auto mid = begi + len/2;
    auto handle = std::async(my_accum<RAIter>, mid, endi);
    auto sum = my_accum(begi, mid);

    return sum + handle.get();

}
int main()
{
    vector<int> v(10000, 1);
    cout << my_accum(v.begin(), v.end())<< endl;
    return 0;
}


