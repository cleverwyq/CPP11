#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    std::basic_stringstream<char> ss;
    ss << "hello";
    cout << ss.str();
}
