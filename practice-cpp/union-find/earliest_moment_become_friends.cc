

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
private:
  int find_root(int p, vector<int>& ids) {
    while (p != ids[p]) {
      ids[p] = ids[ids[p]];
      p = ids[p];
    }
    return p;
  }

public:
    int earliestAcq(vector<vector<int>>& logs, int n) {

      vector<int> ids(n);
      sort(logs.begin(), logs.end());

      for (int i = 0; i < n; ++i) ids[i] = i;

      for (const auto& log : logs) {
        int p = log[1], q = log[2];
        int root_p = find_root(p, ids);
        int root_q = find_root(q, ids);

        if (root_p != root_q) {
          n--;
          if (n == 1) {
            return log[0];
          }
          ids[root_p] = root_q;
        }

      }
        
      return -1;
    }
};

int main() {

  vector<vector<int>> logs = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
  int n = 6;
  int ans = 20190301;

  Solution sol;

  int ret = sol.earliestAcq(logs, n);
  if (ret == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  return 0;
}