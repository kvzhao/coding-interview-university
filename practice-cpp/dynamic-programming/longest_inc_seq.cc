
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence
of the array [0,3,1,6,2,2,7].


Note: There exists an O(nlogn) algorithm with binary search?!
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n, 1);

      for (int k = 0; k < n; ++k) {

        for (int i = 0; i < k; ++i) {
          if (nums[k] > nums[i]) {
            dp[k] = max(dp[k], dp[i] + 1);
          }
        }

      }
      return *max_element(dp.begin(), dp.end());
    }
};


int main() {

  Solution sol;
  vector<pair<int, vector<int>>> problems = {
    {4, {10,9,2,5,3,7,101,18}},
    {4, {0,1,0,3,2,3}},
    {1, {7,7,7,7,7,7,7}},
    {4, {6,2,5,1,7,4,8,3}}
  };

  for (auto &[ans, nums] : problems) {
    auto ret = sol.lengthOfLIS(nums);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}