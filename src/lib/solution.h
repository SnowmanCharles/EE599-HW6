#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string PrintHelloWorld();
  bool checkMaze(vector<vector<int>> &maze, vector<int> &start, vector<int> &end);
  void partition(vector<int> &vec, int p);
};

#endif