
#include "tools.h"

using namespace std;
using namespace huaguisoftware;

// 试题一说明：
// 要求使用最简洁的代码实现“字符串翻转”功能
// input1: Peter is boy
// output1: boy is Peter
// inout2: CocaCola is soft drink
// output2: drink soft is CocaCola
// input3: less is more simple is better
// output3: better is simple more is less
//
string tools::reverseWords(string input)
{
	//return "not implemented";
	// 注释上面的代码并在此实现题目的要求。
	vector<string> string_vector;

	string::size_type index0 = 0, index1 = 0;
	while ((index1 = input.find(' ', index0)) != string::npos) {
        //cout << index0 << "," << index1 <<  endl;
        string_vector.push_back(input.substr(index0, index1 - index0));
        index0 = index1 + 1;
	}
    string_vector.push_back(input.substr(index0));

    string result;
    for(auto it = string_vector.rbegin(); it != string_vector.rend(); it++) {
        result += (*it) + ' ';
    }
    //Todo : last seperator
	return result;
}

