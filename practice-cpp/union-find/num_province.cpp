
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

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

  int find_recursion(int p) {
    if (ids[p] == p) {
      return p;
    }
    return find_recursion(ids[p]);
  }

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

  int get_num_root() {
    int num = 0;
    for (int i = 0; i < ids.size(); i++) {
      if (i == ids[i]) num++;
    }
    return num;
  }

private:
  vector<int> ids;
  vector<int> rank;

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

      int n = isConnected.size();
      DisjointSet ds(n);
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (isConnected[i][j] == 1) {
            ds.join(i, j);
          }
        }
      }
      return ds.get_num_root();
    }
};


int main() {

  vector<vector<int>> isConnected{
    vector<int>{1, 1, 0},
    vector<int>{1, 1, 0},
    vector<int>{0, 0, 1}
  };
  int ans = 2;

  Solution sol;

  int res = sol.findCircleNum(isConnected);

  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed\n";
  }

  return 0;
}