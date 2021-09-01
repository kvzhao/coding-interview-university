
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::unordered_map;
using std::priority_queue;
using std::make_pair;
using std::min_element;
using std::cout;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // TODO selection: https://leetcode.com/problems/top-k-frequent-elements/solution/
      // TODO lambda: https://docs.microsoft.com/zh-tw/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160
      vector<int> result(k);
      return result;
    }
};



int main() {

  Solution sol;

  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;

  auto res = sol.topKFrequent(nums, k);

  for (auto r : res) {
    cout << r << " ";
  }
  cout << "\n";


  return 0;
}