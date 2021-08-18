
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>

using std::vector;
using std::stack;
using std::pair;
using std::make_pair;
using std::cout;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>> paths;

      // vertex, path
      stack<pair<int, vector<int>>> stack_;
      int n = graph.size();
      stack_.emplace(make_pair(0, vector<int>{0}));

      while (!stack_.empty()) {
        auto p = stack_.top();
        stack_.pop();
        int vertex = p.first;
        vector<int> current_path = p.second;

        if (vertex == n - 1) {
          paths.emplace_back(current_path);
        }

        for (auto neighbor : graph[vertex]) {
          vector<int> new_path(current_path);
          new_path.emplace_back(neighbor);
          stack_.emplace(
            make_pair(neighbor, new_path));
        }

      }

      return paths; 
    }
};



int main() {
  Solution sol;

  vector<vector<int>> graph{
    {4,3,1}, {3,2,4}, {3}, {4}, {}};
  vector<vector<int>> res = sol.allPathsSourceTarget(graph);

  // [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
  for (int i = 0; i < res.size(); i++) {
    cout << "path " << i + 1 << ": ";
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}