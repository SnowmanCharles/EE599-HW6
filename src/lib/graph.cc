#include "graph.h"
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

vector<int> Graph::dfs(int root) {  //O(n + m)
    vector<int> res;
    stack<int> s;
    unordered_set<int> visited;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        s.pop();
        if (visited.count(root) < 1) {
            res.push_back(root);
            visited.insert(root);
        }
        for (auto i = v_[root].begin(); i != v_[root].end(); i++) {
            if (visited.count(*i) < 1) {
                s.push(*i);
            }
        }
    }
    return res;
}

vector<int> Graph::dfs_all() {  //O(m + n)
    unordered_set<int> set;
    for (auto pair : v_) {
        set.insert(pair.first);
        for (int i : pair.second) {
            set.insert(i);
        }
    }
    vector<int> res;
    stack<int> s;
    unordered_set<int> visited;
    for (int cur : set) {
        if (visited.count(cur) >= 1) continue;
        s.push(cur);
        while (!s.empty()) {
            int next = s.top();
            s.pop();
            if (visited.count(next) < 1) {
                res.push_back(next);
                visited.insert(next);
            }
            for (auto i = v_[next].begin(); i != v_[next].end(); i++) {
                if (visited.count(*i) < 1) {
                    s.push(*i);
                }
            }
        }
    }
    return res;
}