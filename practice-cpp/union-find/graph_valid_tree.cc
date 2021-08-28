
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
public:
    bool validTree(int n, vector<vector<int>>& edges) {

      vector<int> ids(n, 0);
      for (int i = 0; i < n; ++i) {
        ids[i] = i;
      }

      if (edges.size() != n - 1) return false;

      // union-find
      for (const auto& e : edges) {
        int p = e[0], q = e[1];

        // find
        while (p != ids[p]) p = ids[p];
        while (q != ids[q]) q = ids[q];

        // connected
        if (ids[p] == ids[q]) {
          return false;
        }
        // union
        ids[q] = p;
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