#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int get_len(const string& content)
{
    //PKc
    cout << typeid(content.c_str()).name() << content << endl;
    cout << "max size = " << size_t(-1)/sizeof(string) << endl;
}

struct President
{
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "   " <<name << " - I am being constructed.\n";
    }
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "   " << name <<" - I am being moved.\n";
    }
    President& operator=(const President& other) = default;
};


int main()
{
    get_len("hello");
    vector<string> vs;
    //vs.push_back("hello");
    string str1 = "hello1";
    vs.push_back(str1);
    string str2 = "hello2";
    vs.push_back(str2);
    cout << "sizeof vs ->" << sizeof(vs) << endl;

    string s = "hiyoung";
    cout << "size of string hi ->" << sizeof(s) <<"," << __addressof(s) << endl;

        std::vector<President> elections;
    std::cout << "emplace_back:\n";
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);

    std::vector<President> reElections;
    std::cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

    std::cout << "\nContents:\n";
    for (President const& president: elections) {
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }

    cout <<"after swap" << endl;
    std::swap(elections, reElections);
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }

    vector<President> my;
    if (1 == 0) {
        cout <<"EMC1 added" << endl;
        my.emplace_back("EMC1", "Shanxi", 55);
        cout <<"EMC2 added" << endl;
        my.emplace_back("EMC2", "Shanxi", 55);
            cout <<"EMC3 added" << endl;
        my.emplace_back("EMC3", "Shanxi", 55);
                cout <<"EMC4 added" << endl;
        my.emplace_back("EMC4", "Shanxi", 55);
                cout <<"EMC5 added" << endl;
        my.emplace_back("EMC5", "Shanxi", 55);
                cout <<"EMC6 added" << endl;
        my.emplace_back("EMC6", "Shanxi", 55);
                    cout <<"EMC7 added" << endl;
        my.emplace_back("EMC7", "Shanxi", 55);
                    cout <<"EMC8 added" << endl;
        my.emplace_back("EMC8", "Shanxi", 55);
                    cout <<"EMC9 added" << endl;
        my.emplace_back("EMC9", "Shanxi", 55);
    }
    cout << "type of iterator" << endl;
    cout << typeid(vector<int>::const_iterator::value_type).name() << endl; //i

    vector<int> iv;
    iv.push_back(3);


    auto it = iv.cbegin();
    //error: assignment of read-only location 'it.__gnu_cxx::__normal_iterator<_Iterator, _Container>::operator*<const int*, std::vector<int> >()'|
    //*it = 4;

    it = iv.begin();
    it++;
    ++it;
    return 0;
}
