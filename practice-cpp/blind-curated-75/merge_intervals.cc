
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        return {{}};
    }
};


int main() {


  Solution sol;
  vector<vector<int>> intervals =  {{1,3},{2,6},{8,10},{15,18}};
  // Output: [[1,6],[8,10],[15,18]]
  auto ret = sol.merge(intervals);

  cout << "[";
  for (int i = 0; i < ret.size(); ++i) {
    cout << "[";
    for (int j = 0; j < ret[i].size(); ++j) {
      if (j == 0) cout << "[";
      cout << ret[i][j];
      if (j != ret[i].size() - 1) cout << ", ";
    }
    cout << "]";
  }
  cout << "]\n";


  return 0;
}