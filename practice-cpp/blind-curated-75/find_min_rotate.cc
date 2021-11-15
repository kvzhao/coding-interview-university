#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        return 0;
    }
};

int main() {
  vector<int> nums = {3,4,5,1,2};
  int ans = 1;
  Solution sol;
  auto ret = sol.findMin(nums);
  if (ret == ans) cout << "passed\n";
  else cout << "failed, " << ret << "\n";
  return 0;
}