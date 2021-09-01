

#include <vector>
#include <utilty>
#include <queue>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::pair;
using std::queue;
using std::unordered_map
using std::make_pair;
using std::cout;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      return -1;
    }
};


int main() {
  Solution sol;

  vector<vector<int>> times{{2,1,1}, {2,3,1}, {3,4,1}};
  int n = 4, k = 2;
  const int ans = 2;

  auto res = sol.networkDelayTime(times, n, k);

  if (res == ans) {
    cout << "Pass\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}