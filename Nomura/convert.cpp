#include <iostream>

using namespace std;


class ConvertTo{
public:
    void say() { cout <<"convert to" << endl;}
};
class Convertable {
public:
     operator ConvertTo () {
        cout << "operator ()" << endl;
    return ConvertTo();
    }

    int operator ()(int k) {
        return 20 * k;
    }
};

int main() {
 Convertable ctb;
 ConvertTo ct(ctb);
 ct.say();
}
