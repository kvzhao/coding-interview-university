
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
  
    int findBound(vector<int>& nums, int target, bool leftBound = false) {
      int n = nums.size();
      int left = 0, right = n - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target) {
          right = mid - 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else {
          if (leftBound) {
            if (mid == left || nums[mid - 1] != target) {
              // left-most
              return mid;
            } else {
              right = mid - 1;
            }
          } else {

            if (mid == right || nums[mid + 1] != target) {
              return mid;
            } else {
              left = mid + 1;
            }
          }
        }
      }

      return -1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ret{-1, -1};
      int n = nums.size();
      if (n == 0) return ret;
      ret[0] = findBound(nums, target, true);
      ret[1] = findBound(nums, target, false);
      return ret;
    }
};

int main() {

  Solution sol;
  vector<tuple<vector<int>, vector<int>, int>> problems = {
    {{3,4}, {5,7,7,8,8,10}, 8},
    {{3,6}, {5,7,7,8,8,8,8,10}, 8},
    {{-1, -1}, {5,7,7,8,8,10}, 6},
    {{-1, -1}, {}, 0},
    {{0, 0}, {1}, 1}
  };

  bool pass = true;
  for (auto &[ans, nums, target] : problems) {
    auto rets = sol.searchRange(nums, target);
    if (rets.size() != ans.size()) {
      pass = false;
      cout << "size not equal\n";
      continue;
    }
    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i] != rets[i]) {
        pass = false;
        break;
      }
    }
  }
  if (pass) cout << "passed\n";
  else cout << "failed\n";

  return 0;
}