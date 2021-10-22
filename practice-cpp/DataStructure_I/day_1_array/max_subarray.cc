

#include <iostream>
#include <vector>
#include <bits/stdc++.h> // for int_min

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];
        
        int max = INT_MIN;
        int current = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            current += nums[i];

            if (current > max) {
                max = current;
            }

            current = std::max(current, 0);
        }
        
        return max;
    }
};

int main() {


    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = 6;
    int ret = sol.maxSubArray(nums);

    if (ret == ans)
        cout << "pass\n";
    else
        cout << "failed, " << ret << "\n";

    return 0;
}