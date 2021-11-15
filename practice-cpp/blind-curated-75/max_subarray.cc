#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int best = -1e9;
        int maxSum = 0;

        for (auto n : nums) {
            maxSum = max(maxSum + n, n);
            best = max(best, maxSum);
        }
        
        return best;
    }
};


int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = 6;
    Solution sol;

    auto ret = sol.maxSubArray(nums);

    if (ret == ans) cout << "passed\n";
    else cout << "failed, " << ret << "\n";

    return 0;
}