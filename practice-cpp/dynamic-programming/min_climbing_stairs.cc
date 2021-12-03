
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
    Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
*/

class Solution {
public:
    int minCostClimbingStairsDP(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // space optimization
        int prev2 = 0, prev1 = 0;
        for(size_t i = 2; i <= cost.size(); i++) {
            int temp = prev1;
            prev1 = min(prev2 + cost[i-2], prev1 + cost[i-1]);
            prev2 = temp;
        }
        return prev1;
    }
};


int main() {

  Solution sol;
  vector<pair<int, vector<int>>> problems = {
    {15, {10,15,20}},
    {6, {1,100,1,1,1,100,1,1,100,1}}
  };

  for (auto &[ans, costs] : problems) {
    auto ret = sol.minCostClimbingStairs(costs);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}