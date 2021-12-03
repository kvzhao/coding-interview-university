#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
*/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};


int main() {

  Solution sol;
  vector<pair<int, int>> problems = {
      {4, 4},
      {1389537, 25}
  };

  for (auto &[ans, n] : problems) {
    auto ret = sol.tribonacci(n);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}