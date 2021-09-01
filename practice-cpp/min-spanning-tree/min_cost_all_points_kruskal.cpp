
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;
using std::sort;

class DisjointSet {

public:

  DisjointSet(int size) {
    ids.resize(size);
    rank.resize(size);
    for (int i = 0; i < size; i++) {
      ids[i] = i;
      rank[i] = 1;
    }
  };

  int find(int p) {
    while (p != ids[p]) {
      // path compression
      ids[p] = ids[ids[p]];
      p = ids[p];
    }
    return p;
  };

  void join(int p, int q) {
    int root_p = find(p);
    int root_q = find(q);
    if (root_p == root_q) return;

    int rank_p = rank[root_p];
    int rank_q = rank[root_q];
    if (rank_p > rank_q) {
      ids[root_q] = root_p;
    } else if (rank_q > rank_p) {
      ids[root_p] = root_q;
    } else {
      ids[root_q] = root_p;
      rank[root_p] += 1;
    }
  };

  bool is_connected(int p, int q) {
    return find(p) == find(q);
  };

private:
  vector<int> ids;
  vector<int> rank;

};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();
      vector<vector<int>> edges;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          // p_i and p_j
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int dist = abs(x1 - x2) + abs(y1 - y2);
          edges.emplace_back(vector<int> {dist, i, j});
        }
      }

      // weighted undirected graph
      sort(edges.begin(), edges.end());

      int ans = 0;
      DisjointSet ds(n);
      for (const auto& edge : edges) {
        // pi, pj
        int cost = edge[0], pi = edge[1], pj = edge[2];

        if (ds.is_connected(pi, pj)) {
          continue;
        }
        ds.join(pi, pj);
        ans += cost;
      }

      return ans;
    }
};


int main() {

  vector<vector<int>> points {
    {0,0},{2,2},{3,10},{5,2},{7,0}};
  int ans = 20;

  Solution sol;
  int res = sol.minCostConnectPoints(points);

  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;

}