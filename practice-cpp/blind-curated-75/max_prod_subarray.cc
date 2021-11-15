#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        return 0;
    }
};


int main() {

    vector<int> nums = {2,3,-2,4};
    int ans = 6;
    Solution sol;

    auto ret = sol.maxProduct(nums);

    if (ret == ans) cout << "passed\n";
    else cout << "failed, " << ret << "\n";

    return 0;
}