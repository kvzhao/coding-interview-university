
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                result.emplace_back(hash[nums[i]]);
                result.emplace_back(i);
                return result;
            }
            hash[target - nums[i]] = i;
        }
        return result;
    }
};


int main() {
    Solution sol;

    vector<int> nums, ans, ret;
    int target;

    nums = {2,7,11,15}, target = 9;
    ans = {0, 1};
    ret = sol.twoSum(nums, target);
    for (auto r : ret)
        cout << r << " ";
    cout << "\n";

    return 0;
}