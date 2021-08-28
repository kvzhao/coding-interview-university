#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;

class Solution {
private:

  vector<int> ids;

  int find(int p) {
    while (p != ids[p]) p = ids[p];
    return p;
  }

  void join(int p, int q) {
    int root_p = find(p);
    int root_q = find(q);
    if (root_p == root_q) return;
    ids[root_q] = root_p;
  }

  bool connected(int p, int q) {
    return find(p) == find(q);
  }

public:
    int minimumCost(int n, vector<vector<int>>& connections) {

      sort(connections.begin(), connections.end(),
           [](const vector<int>& v1, const vector<int>& v2 ) -> bool {return v1[2] < v2[2];});
        
      ids.resize(n + 1);
      for (int i = 0; i <= n; ++i) {
        ids[i] = i;
      }

      int min_cost = 0;
      for (const auto& edge : connections) {
        int i = edge[0], j = edge[1];
        int cost = edge[2];
        if (connected(i, j)) continue;

        join(i, j);
        n--;
        min_cost += cost;
        if (n == 1) break;

      }

      return n == 1 ? min_cost : -1;
      
    }
};

int main() {

  Solution sol;

  int n = 3;
  vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
  int ans1 = 6;

  int ret1 = sol.minimumCost(n, connections);

  n = 4;
  connections = {{1,2,3},{3,4,4}};
  int ans2 = -1;
  int ret2 = sol.minimumCost(n, connections);

  if (ret1 == ans1 and ret2 == ans2) {
    cout << "Passed\n";
  } else {
    cout << "Failed, p1 = " << ret1 << ", p2 = " << ret2 << "\n";
  }

  return 0;
}