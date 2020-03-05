#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/graph.h"

using namespace std;

int main()
{
    map<int, set<int>> v{
      {1, {2, 3}},
      {2, {1, 3, 4, 5}},
      {3, {1, 2, 4}},
      {4, {2, 3, 4}}
    };
    Graph g(v);
    vector<int> actual = g.dfs(1);
    for (int i = 0; i < actual.size(); i++) {
        cout << actual[i] << " ";
    }
    cout << endl;

    map<int, set<int>> v1{
        {1, {2, 3}},
        {2, {1, 3, 4, 5}},
        {3, {1, 2, 4}},
        {4, {2, 3, 4}},
        {6, {5, 4}}
    };
    Graph g1(v1);
    actual = g1.dfs_all();
    for (int i = 0; i < actual.size(); i++) {
        cout << actual[i] << " ";
    }
    cout << endl;


    Solution solution;
    vector<vector<int>> maze{
        {1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    vector<int> start{0,0}, end{4,4};
    cout << solution.checkMaze(maze, start, end) << endl;


    vector<vector<int>> maze1{
        {1,1,0,0,0},
        {1,1,1,1,1},
        {0,1,0,0,1},
        {1,0,0,0,0},
        {1,1,1,1,1}
    };
    vector<int> start1{1,2}, end1{4,4};
    cout << solution.checkMaze(maze1, start1, end1) << endl;


    vector<int> vec{9,1,2,8,7,3,6,4,5};
    solution.partition(vec, 8);
    for (int i : vec) cout << i << " ";
    cout << endl;

    return EXIT_SUCCESS;
}