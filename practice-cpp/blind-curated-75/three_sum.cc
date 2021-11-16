#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        return ret;
    }
};



int main() {
    Solution sol;
    vector<int> nums; 

    nums = {-1,0,1,2,-1,-4};
    auto rets = sol.threeSum(nums);
    for (vector<int>& ret : rets) {
        cout << "[";
        for (auto r : ret)
            cout << r << " ";
        cout << "], ";
    }
    cout << "\n";

    return 0;
}