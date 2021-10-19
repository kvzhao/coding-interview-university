
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // in-place algorithm
        size_t n = nums.size();
        vector<int> buff (nums);

        for (size_t i = 0; i < n; ++i) {
            nums[(i + k) % n] = buff[i];
        }
    }
};


int main() {

    vector<int> nums = {1,2,3,4,5,6,7};
    vector<int> ans = {5,6,7,1,2,3,4};
    int k = 3;
    Solution sol;
    sol.rotate(nums, k);

    if (nums.size() != ans.size()) {
        cout << "failed\n";

    } else {
        bool passed = true;
        for (size_t i = 0; i < ans.size(); ++i) {
            if (nums[i] != ans[i]) {
                passed = false;
                break;
            }
        }
        if (passed) {
            cout << "passed\n";
        } else {
            cout << "failed, ";
            for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
            cout << "\n";
        }
    }

    return 0;
}