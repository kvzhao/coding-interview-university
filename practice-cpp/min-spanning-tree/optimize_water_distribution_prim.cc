

#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using std::vector;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::cout;

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
      int min_cost = 0;
      return min_cost;
    }
};

int main() {

  int n = 3; 
  vector<int> wells = {1,2,2};
  vector<vector<int>> pipes = {{1,2,1},{2,3,1}};
  int ans = 3;

  Solution sol;
  int res = sol.minCostToSupplyWater(n, wells, pipes);

  if (res == ans) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }

  return 0;
}