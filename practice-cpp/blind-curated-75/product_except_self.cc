
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    // A beautiful O(n), O(1) solution
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int forward = 1, backward = 1;

        for (int i = 0; i < n; ++i) {
            res[i] *= forward;
            res[n - 1 - i] *= backward;
            forward *= nums[i];
            backward *= nums[n - 1 - i];
        }
        
        return res;
    }
};


int main() {

    vector<int> nums = {1,2,3,4};
    vector<int> ans = {24,12,8,6};
    Solution sol;

    auto ret = sol.productExceptSelf(nums);
    bool passed = true;

    if (ret.size() == ans.size()) {
        for (size_t i = 0; i < ans.size(); ++i) {
            if (ans[i] != ret[i]) {
                cout << ans[i] 
                << " != " << ret[i] << ", i = " << i << "\n";
                passed = false;
                break;
            }
        }
    } else {
        passed = false;
    }

    if(!passed) cout << "failed\n";
    else cout << "passed\n";

    return 0;
}