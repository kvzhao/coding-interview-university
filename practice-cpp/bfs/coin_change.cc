
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
    }
};


int main() {

  Solution sol;

  vector<int> coins = {1, 2, 5};
  int amount = 11;

  auto res = sol.coinChange(coins, amount);
  if (res == 3) {
    cout << "Passed\n";
  } else {
    cout << "Failed, " << res << "\n";
  }
}