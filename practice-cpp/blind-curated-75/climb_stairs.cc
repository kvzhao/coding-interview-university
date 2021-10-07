
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      // climb 1 or 2 steps each time
      vector<int> dp(n + 1); // ignore index 0
      dp[1] = 1;
      dp[2] = 2;
      for (int i = 3; i <= n; ++i) {
        // choose 1 step + 2 step
        dp[i] = dp[i - 1] + dp[i - 2];
      }
        
      return dp[n];
    }
};


int main() {

  Solution sol;
  int n = 3, ans = 3;
  int ret = sol.climbStairs(n);
  if (ret == ans)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";

  return 0;
}