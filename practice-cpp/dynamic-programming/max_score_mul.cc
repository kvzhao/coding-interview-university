
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

* Choose one integer x from either the start or the end of the array nums.
* Add multipliers[i] * x to your score.
* Remove x from the array nums.

Return the maximum score after performing m operations.
*/


class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        
        return -1;
    }
};


int main() {

  Solution sol;
  vector<tuple<int, vector<int>, vector<int>>> problems = {
    {14, {1,2,3}, {3,2,1}},
    {102, {-5,-3,-3,-2,7,1}, {-10,-5,3,4,6}}
  };

  for (auto &[ans, nums, muls] : problems) {
    auto ret = sol.maximumScore(nums, muls);
    if (ans == ret) {
      cout << "Passed\n";
    } else {
      cout << "Failed, " << ret << "\n";
    }
  }

  return 0;
}