#include "../leetcode_utility.hpp"

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  string line;
  Solution sol;
  while (getline(cin, line)) {
    auto nums = stringToIntegerVector(line);
    getline(cin, line);
    int n = stoi(line);
    int ret = sol.search(nums, n);
    cout << ret << endl;
  }
  return 0;
}