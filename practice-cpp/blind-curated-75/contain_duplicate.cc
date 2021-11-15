

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;


        for (auto n : nums) {
            if (set.find(n) != set.end()) {
                return true;
            }
            set.insert(n);
        }

        return false;
    }
};



int main() {

  Solution sol;
  vector<int> nums{1,2,3,1};

  auto ret = sol.containsDuplicate(nums);

  if (ret)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";

  return 0;
}