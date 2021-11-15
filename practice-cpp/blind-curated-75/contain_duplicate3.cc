

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    // Given an integer array nums and two integers k and t,
    // return true if there are two distinct indices i and j in the array
    // such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        return false;
    }
};

int main() {

  Solution sol;
  vector<int> nums{1,2,3,1};
  int k = 3;
  int t = 0;

  auto ret = sol.containsNearbyAlmostDuplicate(nums, k, t);
  if (ret)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";
  
  nums = {1,5,9,1,5,9}, k = 2, t = 3;
  ret = sol.containsNearbyAlmostDuplicate(nums, k, t);
  if (!ret)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";

  return 0;
}