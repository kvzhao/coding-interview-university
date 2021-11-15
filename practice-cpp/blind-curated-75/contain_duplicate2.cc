

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/contains-duplicate-ii/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        // k is the window size
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i) {

          if (i > k) {
            set.erase(nums[i - k - 1]);
          }

          if (set.find(nums[i]) != set.end()) {
            return true;
          }

          set.insert(nums[i]);
        }

        return false;
    }
};



int main() {

  Solution sol;
  vector<int> nums{1,2,3,1,2,3};
  int k = 2;

  auto ret = sol.containsNearbyDuplicate(nums, k);
  if (!ret)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";
  
  nums = {1,2,3,1}, k = 3;
  ret = sol.containsNearbyDuplicate(nums, k);
  if (ret)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";

  return 0;
}