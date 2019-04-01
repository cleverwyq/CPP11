#include <iostream>
#include <utility>


using namespace std;

struct node
{
    node *next;
    node():next(){}
};

int main()
{
    node n;
    cout << n.next << endl;
    cout <<"..." << endl;

    int *p = new int();
    cout << p << endl;

    cout << std::get<0>(std::pair<int, int>(4,6));

}
