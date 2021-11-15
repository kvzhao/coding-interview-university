#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int best = -1e9;
        int maxProd = 1, minProd = 1;

        for (auto n : nums) {

            if (n < 0) {
                swap(minProd, maxProd);
            }

            maxProd = max(maxProd * n, n);
            minProd = min(minProd * n, n);
            best = max(maxProd, best);
        }

        return best;
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