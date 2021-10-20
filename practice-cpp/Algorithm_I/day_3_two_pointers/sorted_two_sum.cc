#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // numbers are sorted
        // 1-indexed array
        size_t n = nums.size();
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }

        return {-1, -1};
    }
};

int main() {


    vector<int> nums = {2,7,11,15};
    vector<int> ans = {1,2};
    int target = 9;
    Solution sol;

    auto ret = sol.twoSum(nums, target);
    if (ret.size() != ans.size()) {
        cout << "failed\n";

    } else {
        bool passed = true;
        for (size_t i = 0; i < ans.size(); ++i) {
            if (ret[i] != ans[i]) {
                passed = false;
                break;
            }
        }
        if (passed) {
            cout << "passed\n";
        } else {
            cout << "failed, ";
            for (size_t i = 0; i < ret.size(); ++i) cout << ret[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}