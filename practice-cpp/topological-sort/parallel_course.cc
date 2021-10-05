#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
      // adj list
      unordered_map<int, vector<int>> graph;
      // 1 ~ n
      vector<int> indegree(n + 1, 0);
      for (const auto& r : relations) {
        graph[r[0]].emplace_back(r[1]);
        ++indegree[r[1]];
      }

      deque<int> q;
      for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
          q.emplace_back(i);
        }
      }

      // #semester
      int semesters = 0;
      int taken_courses = 0;

      while (!q.empty()) {
        int size = q.size();
        ++semesters;

        for (int i = 0; i < size; ++i) {
          auto current = q.front();
          q.pop_front();
          ++taken_courses;

          for (auto v : graph[current]) {
            if (--indegree[v] == 0) {
                q.emplace_back(v);
            }
          }
        }

      }
      return taken_courses == n ? semesters : -1;
    }
};

int main() {
  int n = 0, ans = 0, ret;
  vector<vector<int>> relations;
  Solution sol;

  n = 3, relations = {{1,3},{2,3}};
  ans = 2;
  ret = sol.minimumSemesters(n, relations);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  n = 3, relations = {{1,2},{2,3},{3,1}};
  ret = sol.minimumSemesters(n, relations);
  ans = -1;
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  return 0;
}