#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class A {
public:
    //A(){}
    A(int a) { this->num = a;}
private:
    int num;
};

class B
{
private :
    int num;
    A  obja;
};

class SalesData
{
public:
    int output() {cout << num *price<<endl;}
public:
   int num;
   int price;
};

SalesData&  read(istream& is, SalesData& sd)
{
    is >> sd.num >>sd.price;
    return sd;
}



int main()
{
    //A a(3);
    //B b;

    //SalesData sd;
    //read(cin, sd);
    //sd.output();

    ifstream f("command.txt");
    string text2;
    f>>text2;
    while(!f.eof())
    {

        cout<<text2<<endl;
        f>>text2;
    }
    f.close();

        char buf[200];
        FILE *file = fopen("command.txt", "r");
		fread((void*)buf, 1, 200, file);
		fclose(file);

		cout<<buf<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
