
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "leetcode_utility.hpp"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> indices;
    for (int i = 0; i < nums.size(); ++i) {
      if (indices.find(target - nums[i]) != indices.end()) {
        return {indices[target - nums[i]], i};
      }
      indices[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  string line;
  Solution sol;
  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    getline(cin, line);
    int n = stoi(line);

    auto ret = sol.twoSum(nums, n);

    string ans = integerVectorToString(ret, ret.size());

    cout << ans << endl;
  }
  return 0;
}