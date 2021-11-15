#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int result = max_so_far;

        for (size_t i = 1; i < nums.size(); ++i) {
            auto current = nums[i];
            int temp = max(current, max(max_so_far * current, min_so_far * current));
            min_so_far = min(current, min(max_so_far * current, min_so_far * current));
            max_so_far = temp;
            result = max(max_so_far, result);
        }

        return result;
    }
};


int main() {

    vector<int> nums = {2,3,-2,4};
    int ans = 6;
    Solution sol;

    auto ret = sol.maxProduct(nums);

    if (ret == ans) cout << "passed\n";
    else cout << "failed, " << ret << "\n";

    nums = {0, 2};
    ans = 2;
    ret = sol.maxProduct(nums);
    if (ret == ans) cout << "passed\n";
    else cout << "failed, " << ret << "\n";

    return 0;
}