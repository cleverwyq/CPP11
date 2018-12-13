#include <iostream>
#include <functional>

using namespace std;

struct Foo {
    Foo(int num):num_(num){}
    void print_add(int i) {
        cout << num_ + i << endl;
    }

    int num_;
};

void print_num(int i)
{
    cout << i << " single function"<< endl;
}

struct PrintNum
{
    void operator()(int i)
    {
        cout << "obj call " << i <<endl;
    }
};

int main()
{
    function<void(int)> f_display = print_num;
    f_display(-9);

    auto f_display_lambda = [](){print_num(42);};
    f_display_lambda();

    auto f_display_bind = bind(print_num, 33);
    f_display_bind();

    function<void(Foo&, int)> f_display_mem_add = &Foo::print_add;
    Foo f(45);
    f_display_mem_add(f, 30);

    function<int(Foo&)> f_to_mem_data = &Foo::num_;
    cout << "num_" << f_to_mem_data(f) <<endl;

    function<void(int)> f_bind_mem = std::bind(&Foo::print_add, f, std::placeholders::_1);
    f_bind_mem(4);

    function<void(int)> f_obj = PrintNum();
    f_obj(33);

    return 1;
}
