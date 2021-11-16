#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // with duplicated nums
    int findMin(vector<int>& nums) {


      return -1;
    }
};

int main() {
  vector<int> nums = {2,2,2,0,1};
  int ans = 0;
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