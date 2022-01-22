#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

  int Helper(vector<int>& nums, int left, int right) {

    if (left == right) return left;

    int mid = left + (right - left) / 2;
    int mid2 = mid + 1;

    if (nums[mid] > nums[mid2]) {
      return Helper(nums, left, mid);
    } else {
      return Helper(nums, mid2, right);
    }

  }
public:
    int findPeakElement(vector<int>& nums) {
      return Helper(nums, 0, nums.size() - 1);
    }
};

int main() {

  Solution sol;
  vector<pair<int, vector<int>>> problems = {
    {2, {1,2,3,1}},
    {5, {1,2,1,3,5,6,4}}
  };

  for (auto &[ans, nums] : problems) {
    auto ret = sol.findPeakElement(nums);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}