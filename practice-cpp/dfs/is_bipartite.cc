
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::stack;
using std::pair;
using std::queue;
using std::make_pair;
using std::cout;
using std::min_element;
using std::reverse;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> colors(n, -1);

      for (int start = 0; start < n; ++start) {
        // graph can be totally seperate
        if (colors[start] == -1) {

          // Doesn't matter wheter DFS or BFS
          queue<int> q;
          q.push(start);
          colors[start] = 0;

          while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : graph[node]) {
              if (colors[neighbor] == -1) {
                q.push(neighbor);
                colors[neighbor] = colors[node] ^ 1;
              } else if (colors[neighbor] == colors[node]) {
                return false;
              }
            }
          }
        }
      }


      return true;
    }
};



int main() {

  Solution sol;
  vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
  auto p1 = sol.isBipartite(graph);

  graph = {{1,3},{0,2},{1,3},{0,2}};
  auto p2 = sol.isBipartite(graph);

  if (!p1 and p2) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << p1 << ", " << p2 << "\n";
  }

  return 0;
}