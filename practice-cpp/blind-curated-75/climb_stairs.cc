
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        return 0;
    }
};


int main() {

  Solution sol;
  int n = 3, ans = 3;
  int ret = sol.climbStairs(n);
  if (ret == ans)
    cout << "pass\n";
  else
    cout << "failed, " << ret << "\n";

  return 0;
}