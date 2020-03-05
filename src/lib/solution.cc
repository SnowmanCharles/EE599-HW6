#include "solution.h"
#include <unordered_set>
#include <queue>
using namespace std;

string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

bool Solution::checkMaze(vector<vector<int>> &maze, vector<int> &start, vector<int> &end) {//O(m * n)
  if (start[0] == end[0] && start[1] == end[1]) return true;
  int m = maze.size(), n = maze[0].size();
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  queue<int> q;
  unordered_set<int> visited;
  q.push(start[0] * (m + n) + start[1]);
  visited.insert(start[0] * (m + n) + start[1]);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int x = cur / (m + n), y = cur % (m + n);
    if (x == end[0] && y == end[1]) return true;
    for (vector<int> d : dir) {
      int nextx = x + d[0], nexty = y + d[1];
      if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && maze[nextx][nexty] == 1 &&visited.count(nextx * (m + n) + nexty) < 1) {
        visited.insert(nextx * (m + n) + nexty);
        q.push(nextx * (m + n) + nexty);
      }
    }
  }
  return false;
}

void Solution::partition(vector<int> &vec, int p) {//O(n)
  int n = vec.size();
  swap(vec[n - 1], vec[p]);
  int j = 0;
  for (int i = 0; i < n - 1; i++) {
    if (vec[i] <= vec[n - 1]) {
      swap(vec[j++], vec[i]);
    }
  }
  swap(vec[j], vec[n - 1]);
}