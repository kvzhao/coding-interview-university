

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::min;
using std::max;


// Inspiring problem
// https://leetcode.com/problems/paint-fence/solution/


class Solution {
public:
    int numWays(int n, int k) {
      vector<int> dp(n + 1);

      dp[0] = 0;
      dp[1] = k;
      dp[2] = k * k;

      if (n == 0 || n == 1 || n == 2) {
        return dp[n];
      }

      for (int i = 3; i <= n; ++i) {
        // ways(i) = ways(i-1) * k-1 + ways(i-2) * k-1 * 1
        dp[i] = (dp[i - 2] + dp[i-1]) * (k - 1);
      }

      return dp[n]; 
    }
};



int main() {

  int n = 7;
  int k = 2;
  const int ans = 42;

  Solution sol;

  int ret = sol.numWays(n, k);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  return 0;
}