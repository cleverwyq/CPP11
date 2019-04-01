#include <iostream>
#include <utility>
#include <memory>

using namespace std;

class Person
{
public:
    Person() = default;
    Person(int age,string name):name(name),age(age+1){}
    string name;
    int age;

    void hello() {
        cout <<"I like programmer-" <<name << endl;
    }
};

class MyDel
{
public:
    void operator()  (Person *p) const
    {
        cout << "My deleter!!!"<< endl;
        delete p;
    }

    void operator() (Person **p) const
    {
        cout <<"My deleter 2 ** " << endl;
        delete *p;
    }
};
int main()
{
    MyDel del;
    unique_ptr<Person, MyDel> up1(new Person(21, "Emily"), del);
    up1->hello();
    (up1.operator ->())->hello();

    cout << "----- 1 =======" << endl;

    //error: no match for 'operator=' (operand types are 'std::unique_ptr<Person>' and 'std::unique_ptr<Person, MyDel>::pointer {aka Person*}')|
    //unique_ptr<Person> up2;
    Person *up2  = nullptr;
    up2 = up1.release();
    up2->hello();
    if (up1)
        cout << "up1 is true" << endl;
    else
        cout << "up1 is none" << endl;

    cout << "------2" << endl;

    unique_ptr<Person> up3(new Person(22, "Emily"));
    (*up3).hello();
    up3.operator *().hello();

    cout << "-------3" << endl;
    //C++ 14  !!!
    //    unique_ptr<Person> up4(std::make_unique<Person>(22, "Emily"));
    //    up4->hello();

    Person *temp = new Person;
    unique_ptr<Person*, MyDel> up4(&temp, del);

    cout << "----------4" << endl;
    temp = new Person();
    unique_ptr<Person> up5(temp);
    //potential issues if deleted twice???
    unique_ptr<Person> up6(temp);

    cout << "---------5" << endl;
    temp = new Person();
    Person *temp2 = new Person(33, "young");

    unique_ptr<Person, MyDel> up7(temp, del);


    up7.reset(temp2);
    //temp will invalid later!!!!!
    //temp->hello();
    up7.reset(new Person());

    cout << "--------------6" << endl;
    unique_ptr<Person> up8(new Person(3, "tom"));
    unique_ptr<Person> up9(new Person(4, "jack"));
    up8.swap(up9);
    up8->hello();

    cout << "---------7" << endl;
    //error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Person; _Dp = std::default_delete<Person>]'|
    //up8 = up9;

    up8 = std::move(up9);
    up8->hello();
    if (up9) cout << "up9 true"; else cout << "up9 false"; //false
    cout << endl;
    cout << "Done"<< endl;
}
