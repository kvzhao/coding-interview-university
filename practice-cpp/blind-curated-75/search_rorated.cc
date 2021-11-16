
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] >= nums[left]) {
            // LHS sorted
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
            // RHS sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};


int main() {
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
  int ans = 4, ret = 0;
  Solution sol;

  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {4,5,6,7,0,1,2}, target = 3, ans = -1;
  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {2,3,7}, target = 7, ans = 2;
  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {7,2,3}, target = 7, ans = 0;
  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {3,5,1}, target = 3, ans = 0;
  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  nums = {3,1}, target = 1, ans = 1;
  ret = sol.search(nums, target);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";

  return 0;
}