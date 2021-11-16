#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // require O(lnN) algorithm -> binary search
    int findMin(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      int left = 0, right = nums.size() - 1;

      // non-rotated case
      if (nums[right] > nums[0]) return nums[0];

      // only rotated case
      while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid + 1] < nums[mid]) return nums[mid + 1];
        //if (nums[mid] < nums[mid - 1]) return nums[mid];

        if (nums[mid] > nums[0])
          left = mid;
        else
          right = mid;
      }

      return -1;
    }
};

int main() {
  vector<int> nums = {3,4,5,1,2};
  int ans = 1;
  Solution sol;
  auto ret = sol.findMin(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {11,13,15,17}; ans = 11;
  ret = sol.findMin(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {1}; ans = 1;
  ret = sol.findMin(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {3, 2, 1}; ans = 1;
  ret = sol.findMin(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  return 0;
}