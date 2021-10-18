
#include <vector>
#include <iostream>
using namespace std;

// [1, 3, 5], target = 2, lo = 0, hi = 2
// mid => 3, lo => 1, hi => 5
// hi = mid - 1, lo = 1, hi = 1, mid = 1
// lo == hi, hi = mid - 1
// hi = 0, lo = 1, stop

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};


int main() {

    Solution sol;
    vector<int> nums = {1,3,5,6};
    int target = 7;
    int output = 4;

    int ret = sol.searchInsert(nums, target);
    if (ret == output) cout << "passed\n";
    else cout << "failed, " << ret << "\n";

    return 0;
}
