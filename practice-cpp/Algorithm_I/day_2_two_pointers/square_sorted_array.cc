
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int lo = 0, hi = n - 1;

        for (int i = n - 1; i >=0; --i) {
            if (abs(nums[lo]) > abs(nums[hi])) {
                res[i] = nums[lo] * nums[lo];
                ++lo;
            } else {
                res[i] = nums[hi] * nums[hi];
                --hi;
            }
        }

        return res;
    }
};

int main() {

    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = {0,1,9,16,100};
    Solution sol;

    auto ret = sol.sortedSquares(nums);
    if (ret.size() != ans.size()) {
        cout << "failed\n";

    } else {
        bool passed = true;
        for (int i = 0; i < ans.size(); ++i) {
            if (ret[i] != ans[i]) {
                passed = false;
                break;
            }
        }
        if (passed) {
            cout << "passed\n";
        } else {
            cout << "failed, ";
            for (int i = 0; i < ret.size(); ++i) cout << ret[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}