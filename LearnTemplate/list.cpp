#include <iostream>
#include <list>
#include <string>

using namespace std;


int main()
{
    list<string> strlist;
    strlist.insert(strlist.begin(), "hello");
    string world="world";
    strlist.push_back(world);
    string oo="OO";
    strlist.push_front("OO");

    return 0;
}
