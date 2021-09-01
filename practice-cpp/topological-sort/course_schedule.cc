
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using std::vector;
using std::stack;
using std::set;
using std::queue;
using std::cout;
using std::unordered_map;
using std::reverse;

class Solution {
public:

    bool findOrderUtil(int current, unordered_map<int, vector<int>>& graph, vector<int>& visited, vector<int>& result) {
      visited[current] = 1;

      for (auto neighbor : graph[current]) {
        // neighbor explored before current
        if (visited[neighbor] == 1) {
          return false;
        }

        if (visited[neighbor] == 0) {
          if (!findOrderUtil(neighbor, graph, visited, result)) {
            return false;
          }
        }
      }

      visited[current] = 2;
      result.emplace_back(current);
      return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> ordered_results;
      // status: 0 unvisited, 1 exploring, 2 visited
      vector<int> visited(numCourses, 0);

      unordered_map<int, vector<int>> graph;
      for (const auto& p : prerequisites) {
        graph[p[1]].emplace_back(p[0]);
      }
      
      // DFS - visited set & stack
      for (int i = 0; i < numCourses; i++) {

        if (visited[i] == 0) {

          if ( !findOrderUtil(i, graph, visited, ordered_results) ) {
            // cycle-detected failed
            return vector<int>();
          }

        }
      }

      reverse(ordered_results.begin(), ordered_results.end());

      return ordered_results;
    }



};


int main() {


  Solution sol;

  int numCourses = 4;
  vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
  // {0,2,1,3}

  auto res = sol.findOrder(numCourses, prerequisites);

  for (auto r : res) {
    cout << r << " ";
  }
  cout << "\n";

}