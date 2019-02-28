// chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>

#define SEQUENCE 10
using namespace std;


vector<vector<int> > paths;
unordered_set<int> vowels;
vector<char>  translate;
void add_path(int index, int points[], int num)
{
	vector<int> v;
	for (int i = 0; i < num; i++)
		v.push_back(points[i]);
	paths.push_back(v);
}


//Initialze the possible steps.
//Mapping the keyboard from left to right, top to bottom
//to 0 - 17
void initializePaths(){

	int points0[] = { 7, 11 };
	add_path(0, points0, 2);
	int points1[] = { 8, 10, 12 };
	add_path(1, points1, 3);
	int points2[] = { 5, 9, 11, 13 };
	add_path(2, points2, 4);
	int points3[] = { 6, 12, 14 };
	add_path(3, points3, 3);
	int points4[] = { 7, 13 };
	add_path(4, points4, 2);

	int points5[] = { 2, 12, 15 };
	add_path(5, points5, 3);
	int points6[] = { 3, 13, 16 };
	add_path(6, points6, 3);
	int points7[] = { 0, 4, 10, 14, 15, 17 };
	add_path(7, points7, 6);
	int points8[] = { 1, 11, 16 };
	add_path(8, points8, 3);
	int points9[] = { 2, 12, 17 };
	add_path(9, points9, 3);

	int points10[] = { 1, 7, 16 };
	add_path(10, points10, 3);
	int points11[] = { 0, 2, 8, 17 };
	add_path(11, points11, 4);
	int points12[] = { 1, 3, 5, 9 };
	add_path(12, points12, 4);
	int points13[] = { 2, 4, 6, 15 };
	add_path(13, points13, 4);
	int points14[] = { 3, 7, 16 };
	add_path(14, points14, 3);

	int points15[] = { 5, 7, 13 };
	add_path(15, points15, 3);
	int points16[] = { 6, 8, 10, 14 };
	add_path(16, points16, 4);
	int points17[] = { 11, 7, 9 };
	add_path(17, points17, 3);

	int vs[] = { 0, 4, 8, 14 };
	for (int i = 0; i < 4; i++)
		vowels.insert(vs[i]);
	
	for (int i = 0; i < 15; i++)
		translate.push_back('A' + i);
	translate.push_back('1');
	translate.push_back('2');
	translate.push_back('3');
}

//Output
int counter = 0;
//unordered_set<int> visited;
vector<int> path;
unordered_set<int> visitedVowels;

int startFrom(int start) {



	//Already visited.
	//if (visited.find(start) != visited.end()) {
		//return -1;
	//}
	for (auto it = path.begin(); it != path.end(); it++) {
		if (*it == start) return -1;
	}

	//It is a vowel
	if (vowels.find(start) != vowels.end()){
		if (visitedVowels.size() == 2) {
			return -1;
		}
		visitedVowels.insert(start);
	}

	path.push_back(start);
	//visited.insert(start);

	//Find enough key, Stop.
	if (path.size() == SEQUENCE) {
		counter++;
		for (int i = 0; i < SEQUENCE; i++)
			cout << path[i] << "->";
		cout << "nil" << endl;
		//unordered_set<int>::iterator tmp = visited.find(start);
		//if (tmp != visited.end()) visited.erase(tmp);
		//path.pop_back();


		path.pop_back();
		auto tmp = visitedVowels.find(start);
		if (tmp != visitedVowels.end()) visitedVowels.erase(tmp);
		return -2;
	}



	int current = start;
	vector<int> nextStep = paths[current];
	for (vector<int>::iterator it = nextStep.begin(); it != nextStep.end(); it++) {
		int valid_step = startFrom(*it);
		if (valid_step  == -2) {
			//unordered_set<int>::iterator tmp = visited.find(*it);
			//if (tmp != visited.end()) visited.erase(tmp);
			//path.pop_back();
		}
	}

	//unordered_set<int>::iterator tmp = visited.find(start);
	//if (tmp != visited.end()) visited.erase(tmp);
	auto tmp = visitedVowels.find(start);
	if (tmp != visitedVowels.end()) visitedVowels.erase(tmp);
	path.pop_back();
	return -1;

}

int _tmain(int argc, _TCHAR* argv[])
{
	initializePaths();

	counter = 0;
	//startFrom(0);

	for (int k = 0; k < 18; k++) {
		//visited.clear();
		path.clear();
		visitedVowels.clear();
		
		startFrom(k);

	}
		
	cout << "Total count:" << counter << endl;

	int wait;
	cin >> wait;
	return 0;
}


