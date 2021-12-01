
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence
of the array [0,3,1,6,2,2,7].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
      return -1;
    }
};


int main() {
  Solution sol;
  vector<int> nums;
  int ans, ret;

  nums = {10,9,2,5,3,7,101,18};
  ans = 4;
  ret = sol.lengthOfLIS(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  nums = {0,1,0,3,2,3};
  ans = 4;
  ret = sol.lengthOfLIS(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  nums = {7,7,7,7,7,7,7};
  ans = 1;
  ret = sol.lengthOfLIS(nums);

  if (ans == ret) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << ret << "\n";
  }

  return 0;
}