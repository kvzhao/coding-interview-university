
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        
      return 0;
    }
};

int main() {

  Solution sol;
  vector<vector<int>> transactions;
  int ans, ret;
  transactions = {{0,1,10},{2,0,5}};
  ans = 2;

  ret = sol.minTransfers(transactions);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  transactions = {{0,1,10},{1,0,1},{1,2,5},{2,0,5}};
  ans = 1;
  ret = sol.minTransfers(transactions);

  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  return 0;
}