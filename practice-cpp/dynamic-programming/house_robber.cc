
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n + 1, 0);
      dp[0] = 0;
      dp[1] = nums[0];

      for (int i = 2; i <= n; i++) {
        auto current = nums[i - 1];
        dp[i] = max(dp[i - 2] + current, dp[i - 1]);
      }

      return dp[n];
    }
};


int main() {

  vector<int> nums;
  int ans, ret;

  Solution sol;

  nums = {1,2,3,1};
  ans = 4;
  ret = sol.rob(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  nums = {2,7,9,3,1}, ans = 12;
  ret = sol.rob(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  nums = {2,1,1,2};
  ans = 4;
  ret = sol.rob(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  return 0;
}