
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return -1;
    }
};


int main() {
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
  int ans = 4;
  Solution sol;
  auto ret = sol.search(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n"

  return 0;
}