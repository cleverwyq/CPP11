#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


vector<vector<int> > paths;
unordered_set<int> vowels;

void add_path(int index, int points[], int num)
{
  vector<int> v;
  for (int i = 0; i < num; i++)
        v.push_back(points[i]);
  paths.push_back(v);
}

void initializePaths(){

    int points0[] = {7,11};
    add_path(0, points0, 2);
    int points1[] = {8,10,12};
    add_path(1, points1,3);
    int points2[] = {5,9,11,13};
    add_path(2, points2, 4);
    int points3[] = {6,12,14};
    add_path(3, points3, 3);
    int points4[] = {7,13};
    add_path(4, points4, 2);

    int points5[] = {2,12,15};
    add_path(5, points5, 3);
    int points6[] = {3,13, 16};
    add_path(6, points6, 3);
    int points7[] = {0, 4, 10, 14, 15, 17};
    add_path(7, points7, 6);
    int points8[] = {1, 11, 16};
    add_path(8, points8, 3);
    int points9[] = {2,12, 17};
    add_path(9, points9, 3);

    int points10[] = {1, 7, 16};
    add_path(10, points10, 3);
    int points11[] = {0, 2, 8, 17};
    add_path(11, points11, 4);
    int points12[] = {1, 3, 5, 9};
    add_path(12, points12, 4);
    int points13[] = {2,4,6,15};
    add_path(13, points13, 4);
    int points14[] = {3,7, 16};
    add_path(14, points14, 3);

    int points15[] = {5,7, 13};
    add_path(15, points15, 3);
    int points16[] = {6, 8,10, 14};
    add_path(16, points16, 4);
    int points17[] = {11, 7, 9};
    add_path(17, points17, 3);

    int vs[] = {0, 4, 8, 14};
    for (int i = 0; i < 4; i ++)
        vowels.insert(vs[i]);
}

unordered_set<int> visited;
vector<int> path;
unordered_set<int> visitedVowels;
int counter = 0;

int startFrom(int start) {

    if (visited.find(start) != visited.end()) {
        path.pop_back();
        return -1;
    }

    if (vowels.find(start) != vowels.end()){
        if (visitedVowels.size() == 2) {
             path.pop_back();
             return -1;
        }
        visitedVowels.insert(start);
    }

    if (path.size() == 10) {
        counter ++;
        return -1;
    }
    path.push_back(start);
    visited.insert(start);

    int current =  start;
    vector<int> nextStep = paths[current];
    for (vector<int>::iterator it = nextStep.begin(); it != nextStep.end(); it++) {
        startFrom(*it);
    }

}
int main()
{
    initializePaths();
    int start = 0;
    startFrom(start);
    cout << counter <<endl;
    return 0;
}
