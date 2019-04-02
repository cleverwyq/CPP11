#include <memory>
#include <iostream>

using namespace std;


struct Foo {
    ~Foo() {cout << "~Foo" << endl;};
    };
int main()
{
    weak_ptr<Foo> wptr;
    {
        auto sptr = std::make_shared<Foo>();
        auto sptr1(sptr);

        //only add weak_count , not affect use_count;
        wptr = sptr;
        cout << "wpr count inside:" << wptr.use_count() << endl;
        cout << "sptr count inside:" << sptr.use_count() << endl;
        cout << endl;
    }
    //output : ~Foo
    cout << "wpr count ouside:" << wptr.use_count() << endl;
    cout << "wpr expired :" << wptr.expired()<< endl;

    cout << "-----------1" << endl;
    {
        weak_ptr<Foo> wp1(std::move(make_shared<Foo>()));   //~Foo
        cout << "wp1 use_count:" << wp1.use_count()<< endl; //0
        cout << "wp1 expried:" << wp1.expired() << endl;;   //true
        weak_ptr<Foo> wp2(wp1);
        cout << "wp2 use_count:" << wp2.use_count()<< endl; //0
    }

        cout << "-----------2" << endl;
    {
        auto sp = make_shared<Foo>();
        weak_ptr<Foo> wp1(sp);
        cout << "wp1 use_count:" << wp1.use_count()<< endl;  //1
        cout << "wp1 expried:" << wp1.expired() << endl;   //false
        weak_ptr<Foo> wp2(wp1);
        cout << "wp2 use_count:" << wp2.use_count()<< endl; //1
        //output: ~Foo
    }

    cout << "------------3"<< endl;
    {
        weak_ptr<Foo> wp;
        cout << "wp not inited" << endl;
        auto observe = wp.lock();
        if (!observe) cout << "observe is false " << "use count:" << observe.use_count()<< endl;
        //wp = make_shared<int>(23);
        auto shared = make_shared<Foo>();
        wp = shared;
        observe = wp.lock();
        if (observe) cout << "observe is true now" << endl;
        cout << "observer use count:" << observe.use_count() << endl;
    }
        // ~Foo
}
