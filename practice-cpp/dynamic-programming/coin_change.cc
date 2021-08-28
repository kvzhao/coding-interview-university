
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::min;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int maximum = amount + 1;

      vector<int> dp(amount + 1, maximum);
      dp[0] = 0;

      for (int n = 1; n <= amount; ++n) {
        for (int j = 0; j < coins.size(); ++j) {
          if (coins[j] <= n) {
            dp[n] = min(dp[n], dp[n - coins[j]] + 1);
          }
        }
      }

      return dp[amount] > amount ? -1 : dp[amount];
    }
};


int main() {

  Solution sol;

  vector<int> coins = {1, 2, 5};
  int amount = 11;

  auto res = sol.coinChange(coins, amount);
  if (res == 3) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }
}