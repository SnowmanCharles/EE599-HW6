#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <set>

using namespace std;

class Graph {
public:
    Graph(map<int, set<int>> &vertices) : v_(vertices){};
    map<int, set<int>> v_;
    vector<int> dfs(int root);
    vector<int> dfs_all();
};

#endif