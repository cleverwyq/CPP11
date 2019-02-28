// Subset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <set>

using namespace std;
int* Subsets(int r1, int r2, int m1, int m2) {
	int *result = NULL;
	if (m1 <= 0 || m2 <= 0) {
		return result;
	}

	if (m1 > r2 || m2 > r2) {
		return result;
	}
	int min_m1 = r1 + (m1 - (r1 % m1 == 0 ? m1: r1 % m1));
	int min_m2 = r1 + (m2 - (r1 % m2 == 0 ? m2: r1 % m2));
	cout << min_m1 << "," << min_m2 << endl;


	//Todo: the number of multi_m1 can also be calculated by (r2 - r1)/m1 ?
	vector<int> m1v, m2v;
	for (int i = 0, multi_m1 = min_m1; multi_m1 <= r2; i++) {		
		m1v.push_back(multi_m1);
		multi_m1 = min_m1 + i * m1;
	}

	for (int i = 0, multi_m2 = min_m2; multi_m2 <= r2; i++) {
		m2v.push_back(multi_m2);		
		multi_m2 = min_m2 + i * m2;
	}

	//Erase duplicate
	set<int> result_set;
	for (vector<int>::iterator it1 = m1v.begin(); it1 != m1v.end(); ++it1) {
		result_set.insert(*it1);
	}
	for (vector<int>::iterator it2 = m2v.begin(); it2 != m2v.end(); ++it2) {
		result_set.insert(*it2);
	}

	int total_size = result_set.size();
	result = new int[total_size + 1];

	int index = 0;
	for (set<int>::iterator it = result_set.begin(); it != result_set.end(); ++it) {
		result[index++] = *it;
	}

	//Sentinel
	result[total_size] = -1;
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Subsets(3, 12, 4, 6);
	Subsets(7, 12, 4, 6);
	Subsets(4, 12, 4, 6);
	return 0;
}

