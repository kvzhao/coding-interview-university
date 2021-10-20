
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int current = 0, last_non_zero = 0; current < nums.size(); ++current) {
            if (nums[current] != 0) {
                swap(nums[current], nums[last_non_zero++]);
            }
        }
    }
};

int main() {


    vector<int> nums = {0,1,0,3,12};
    vector<int> ans = {1,3,12,0,0};
    Solution sol;

    sol.moveZeroes(nums);

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