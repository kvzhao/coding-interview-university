

#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using std::make_pair;
using std::cout;


class DisjointSet {
public:

  DisjointSet(int size) {
    ids.resize(size);
    ranks.resize(size);
    for (int i = 0; i < size; ++i) {
      ids[i] = i;
      ranks[i] = 1;
    }
  }

  int find(int p) {
    while (p != ids[p]) {
      ids[p] = ids[ids[p]];
      p = ids[p];
    }
    return p;
  } 

  void join(int p, int q) {
    int root_p = find(p);
    int root_q = find(q);

    if (root_p == root_q) return;

    int rank_p = ranks[root_p];
    int rank_q = ranks[root_q];

    if (rank_p > rank_q) {
      ids[root_q] = root_p;
    } else if (rank_q > rank_p) {
      ids[root_p] = root_q;
    } else {
      ranks[root_p]++;
      ids[root_q] = root_p;
    }

  }

  bool is_connected(int p, int q) {
    return find(p) == find(q);
  }


private:

  vector<int> ids;
  vector<int> ranks;

};


class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
      // n vertices, from 1...n
      vector<vector<int>> edges;
      for (const auto& pipe : pipes) {
        edges.emplace_back(vector<int>{pipe[2], pipe[0], pipe[1]});
      }
      for (int i = 0; i < n; ++i) {
        edges.emplace_back(vector<int>{wells[i], 0, i + 1});
      }

      sort(edges.begin(), edges.end());

      DisjointSet djs(n + 1);

      int min_cost = 0;
      for (const auto& e : edges) {
        int cost = e[0];
        int p = e[1];
        int q = e[2];

        if (djs.is_connected(p, q)) continue;

        djs.join(p, q);
        n--;
        min_cost += cost;

        if (n == 0) break;

      }

      return min_cost;
        
    }
};

int main() {

  int n = 3; 
  vector<int> wells = {1,2,2};
  vector<vector<int>> pipes = {{1,2,1},{2,3,1}};
  int ans = 3;

  Solution sol;
  int res = sol.minCostToSupplyWater(n, wells, pipes);

  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}