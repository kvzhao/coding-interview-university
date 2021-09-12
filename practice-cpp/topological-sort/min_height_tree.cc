
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    // The idea is to eat up all the leaves at the same time, until one/two leaves are left.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if(n <= 1)
        return n == 0 ? vector<int>{} : vector<int>{0};

      vector<int> indegree(n, 0);
      vector<vector<int>> graph(n);
      for (const auto& e : edges) {
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
        ++indegree[e[0]];
        ++indegree[e[1]];
      }

      unordered_set<int> visited;
      deque<int> q;

      // find all leaf
      for (int i = 0; i < n; ++i) {
        if (indegree[i] == 1) {
          q.emplace_back(i);
          visited.emplace(i);
        }
      }

      vector<int> result;

      int n_leafs = q.size();

      while (!q.empty()) {
        auto current = q.front();
        q.pop_front();

        --n_leafs;
        result.emplace_back(current);

        for (auto v : graph[current]) {
          if (!visited.count(v)) {
            --indegree[v];
            if (indegree[v] == 1) {
              q.emplace_back(v);
              visited.emplace(v);
            }
          }
        }

        if (n_leafs == 0) {
          if (!q.empty()) {
            result.clear();
          }
          n_leafs = q.size();
        }

      }
        
        return result;
    }
};


int main() {

  int n = 0;
  vector<vector<int>> edges;
  vector<int> res;
  Solution sol;
  n = 6, edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
  // {3,4}
  res = sol.findMinHeightTrees(n, edges);
  for (auto r : res)
    cout << r << " ";
  cout << "\n";

  n = 2, edges = {{0,1}};
  // {0,1}
  res = sol.findMinHeightTrees(n, edges);
  for (auto r : res)
    cout << r << " ";
  cout << "\n";

  n = 1, edges = {};
  // {0}
  res = sol.findMinHeightTrees(n, edges);
  for (auto r : res)
    cout << r << " ";
  cout << "\n";

  return 0;
}