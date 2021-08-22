
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::multiset;
using std::deque;
using std::stack;
using std::pair;
using std::make_pair;
using std::cout;
using std::min_element;
using std::reverse;

class Solution {
  bool hasCycle(const vector<vector<int>>& graph, int current, int parent, vector<bool>& visited) {
    // DFS: Already visited before depth-first search
    if (visited[current]) {
      return true;
    }
    visited[current] = true;

    for (auto neighbor : graph[current]) {
      if (neighbor != parent && hasCycle(graph, neighbor, current, visited)) {
        return true;
      }
    }
    return false;
  }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges) {
          int e1 = edge[0];
          int e2 = edge[1];
          graph[e1].emplace_back(e2);
          graph[e2].emplace_back(e1);
        }

        // Tree: 1. No cycle, 2. All nodes approachable

        if (hasCycle(graph, 0, -1, visited)) {
          return false;
        }

        for (auto v : visited) {
          if (!v) {
            return false;
          }
        }
        return true;
    }
};

int main() {

  int n = 5;
  vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};

  Solution sol;
  bool p1 = sol.validTree(n, edges);

  vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
  bool p2 = sol.validTree(n, edges2);

  if (p1 and !p2) {
    cout << "Passed\n";
  } else {
    cout << "Failed, p1 = " << p1 << ", p2 = " << p2 << "\n";
  }

  return 0;
}